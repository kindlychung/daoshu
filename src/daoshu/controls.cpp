#include "controls.h"
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QtWidgets>
#include <cassert>

Controls::Controls(QWidget* parent) : QWidget(parent) {
    controlLayout = new QVBoxLayout;
    spinLayout = new QHBoxLayout;
    buttonLayout = new QHBoxLayout;
    hourSpin = new QSpinBox;
    minSpin = new QSpinBox;
    secSpin = new QSpinBox;
    hourSpin->setSuffix("H");
    minSpin->setSuffix("M");
    secSpin->setSuffix("S");
    for (auto w : (QSpinBox*[]){hourSpin, minSpin, secSpin}) {
        w->setRange(0, 59);
        w->setStyleSheet("font-size: 64px");
        w->setSizePolicy(
            QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed));
    }
    initSpinValues();
    setButton = new QPushButton("Set");
    cancelButton = new QPushButton("Cancel");
    spinLayout->addWidget(hourSpin);
    spinLayout->addWidget(minSpin);
    spinLayout->addWidget(secSpin);
    buttonLayout->addWidget(setButton);
    buttonLayout->addWidget(cancelButton);
    controlLayout->addLayout(spinLayout);
    controlLayout->addLayout(buttonLayout);
    setLayout(controlLayout);
    connect(setButton, SIGNAL(clicked()), this, SLOT(setButtonClicked()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancelButtonClicked()));
}

void Controls::initSpinValues() {
    hourSpin->setValue(0);
    minSpin->setValue(0);
    secSpin->setValue(3);  // set a timer of 3 seconds by default
}

void Controls::decrement() {
    // every tick from QTimer is set at 100ms, so you need 10 ticks before you
    // can count down 1 second
    static int _counter = 10;
    if (_counter == 10) {
        _counter = 1;
        if (!hourSpin->value() && !minSpin->value() && !secSpin->value()) {
            return;
        }
        if (!secSpin->value()) {
            if (!minSpin->value()) {
                hourSpin->setValue(hourSpin->value() - 1);
                minSpin->setValue(59);
            } else {
                minSpin->setValue(minSpin->value() - 1);
            }
            secSpin->setValue(59);
        } else {
            secSpin->setValue(secSpin->value() - 1);
        }
    } else {
        _counter++;
    }
}

void Controls::setButtonClicked() {
    int nMilliSec =
        (hourSpin->value() * 3600 + minSpin->value() * 60 + secSpin->value()) *
        1000;
    if (nMilliSec <= 0) return;
    emit valueSet(nMilliSec);
    disableSpins();
}

QString Controls::enabledSpinStyle() {
    return QString("background-color: white; font-size: 64px");
}
QString Controls::disabledSpinStyle() {
    return QString("background-color: lightgray; font-size: 64px");
}

void Controls::enableSpins() {
    hourSpin->setReadOnly(false);
    minSpin->setReadOnly(false);
    secSpin->setReadOnly(false);
    auto style = enabledSpinStyle();
    hourSpin->setStyleSheet(style);
    minSpin->setStyleSheet(style);
    secSpin->setStyleSheet(style);
}

void Controls::disableSpins() {
    auto style = disabledSpinStyle();
    for (auto& spin : (QSpinBox*[]){hourSpin, minSpin, secSpin}) {
        spin->setReadOnly(true);
        spin->setStyleSheet(style);
    }
}

void Controls::handleTimeup() { enableSpins(); }
void Controls::handleCancel() {
    enableSpins();
    initSpinValues();
}

void Controls::cancelButtonClicked() {
    enableSpins();
    emit timerCancelled();
}