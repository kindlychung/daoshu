#include "controls.h"
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QtWidgets>

Controls::Controls(QWidget *parent) : QWidget(parent) {
    controlLayout = new QVBoxLayout;
    spinLayout = new QHBoxLayout;
    buttonLayout = new QHBoxLayout;
    hourSpin = new QSpinBox;
    minSpin = new QSpinBox;
    secSpin = new QSpinBox;
    hourSpin->setValue(0);
    hourSpin->setRange(0, 120);
    minSpin->setValue(0);
    minSpin->setRange(0, 60);
    secSpin->setValue(10);
    secSpin->setRange(0, 60);
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
}

void Controls::decrement() {
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
}

void Controls::setButtonClicked() {
    emit valueSet(hourSpin->value() * 3600 + minSpin->value() * 60 +
                  secSpin->value());
    disableSpins();
}

void Controls::enableSpins() {
    hourSpin->setReadOnly(false);
    minSpin->setReadOnly(false);
    secSpin->setReadOnly(false);
}

void Controls::disableSpins() {
    hourSpin->setReadOnly(true);
    minSpin->setReadOnly(true);
    secSpin->setReadOnly(true);
}

void Controls::handleTimeup() { enableSpins(); }

void Controls::cancelButtonClicked() { qDebug() << "cancelled"; }