#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <QtWidgets/QWidget>

class AnalogClock : public QWidget {
    Q_OBJECT

   public:
    AnalogClock(QWidget *parent = 0);
    virtual ~AnalogClock(){};

   protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif