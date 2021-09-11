#include "daoshu_window.h"
#include "daoshu_notify.h"
#include "play_sound.h"

DaoshuWindow::DaoshuWindow(int width, QWidget *parent) : QWidget(parent) {
    auto expandPolicy = QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    arcUI = new ArcProgress(width);
    controls = new Controls;
    layout = new QVBoxLayout;
    layout->addWidget(arcUI);
    layout->addWidget(controls);
    layout->setAlignment(arcUI, Qt::AlignmentFlag::AlignHCenter);
    layout->setAlignment(controls, Qt::AlignmentFlag::AlignHCenter);
    controls->setSizePolicy(expandPolicy);
    setLayout(layout);
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), controls, SLOT(decrement()));
    connect(timer, SIGNAL(timeout()), arcUI, SLOT(decrement()));
    connect(timer, SIGNAL(timeout()), arcUI, SLOT(update()));
    connect(arcUI, SIGNAL(timeUp()), this, SLOT(timeUpAudio()));
    connect(arcUI, SIGNAL(timeUp()), controls, SLOT(handleTimeup()));
    connect(controls, SIGNAL(timerCancelled()), arcUI, SLOT(handleCancel()));
    connect(controls, SIGNAL(valueSet(int)), this, SLOT(startCountdown(int)));
    connect(controls, SIGNAL(timerCancelled()), this, SLOT(stopTimer()));
}

void DaoshuWindow::startTimer() { timer->start(100); }
void DaoshuWindow::stopTimer() { timer->stop(); }
void DaoshuWindow::timeUpAudio() {
    timer->stop();
	auto s = controls->msgField->text();
    notify(s);
    play_sound(7);
    return;
}

void DaoshuWindow::startCountdown(int nMilliSec) {
    arcUI->setSeconds(nMilliSec);
    startTimer();
}
