#include "daoshu_window.h"
#include "play_sound.h"

DaoshuWindow::DaoshuWindow(int width, QWidget *parent) : QWidget(parent) {
    arcUI = new ArcProgress(width);
    setFixedWidth(width);
    setFixedHeight(width * 1.5);
    controls = new Controls;
    layout = new QVBoxLayout;
    layout->addWidget(arcUI);
    layout->addWidget(controls);
    layout->setAlignment(Qt::AlignmentFlag::AlignCenter);
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
    play_sound(3);
    return;
}

void DaoshuWindow::startCountdown(int nMilliSec) {
    arcUI->setSeconds(nMilliSec);
    startTimer();
}
