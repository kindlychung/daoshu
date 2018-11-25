#pragma once
#include <QtWidgets/QWidget>

class ArcProgress : public QWidget {
    Q_OBJECT

   public:
    ArcProgress(int width, QWidget *parent = 0);
    virtual ~ArcProgress(){};

   protected:
    void paintEvent(QPaintEvent *event) override;
    int initWidth;
    int nSec = 0;
    int totalSec = 1;
    int padding = 0;
    int arcWidth = 0;
   public slots:
    void decrement();
   signals:
    void timeUp();

   public:
    void setSeconds(int c) {
        nSec = c;
        totalSec = c;
    }  // c > 0 is checked at call site
};