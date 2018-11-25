#include "daoshu_window.h"

DaoshuWindow::DaoshuWindow(int width, QWidget *parent) : QWidget(parent) {
    arcUI = new ArcProgress(width);
    setFixedWidth(width);
    setMinimumHeight(width);
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
    connect(controls, SIGNAL(valueSet(int)), this, SLOT(startCountdown(int)));
    connect(arcUI, SIGNAL(timeUp()), this, SLOT(timeUpAudio()));
    connect(arcUI, SIGNAL(timeUp()), controls, SLOT(handleTimeup()));
}

void DaoshuWindow::startTimer() { timer->start(1000); }
void DaoshuWindow::stopTimer() { timer->stop(); }
void DaoshuWindow::timeUpAudio() {
    timer->stop();
    for (int i = 0; i < 10; i++) {
        system("aplay /home/kaiyin/bell.wav 2> /dev/null");
    }
}

void DaoshuWindow::startCountdown(int nSec) {
    arcUI->setSeconds(nSec);
    startTimer();
}
