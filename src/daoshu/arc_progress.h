#pragma once
#include <QtWidgets/QWidget>

class ArcProgress : public QWidget {
    Q_OBJECT

   public:
    ArcProgress(int width, QWidget *parent = 0);
    virtual ~ArcProgress(){};

   private:
    bool blink = false;

   protected:
    void paintEvent(QPaintEvent *event) override;
    int initWidth;
    int nMilliSec = 0;
    int totalMilliSec = 1;
    int padding = 0;
    int arcWidth = 0;
   public slots:
    void decrement();
    void handleCancel();
   signals:
    void timeUp();

   public:
    void setSeconds(int c) {
        nMilliSec = c;
        totalMilliSec = c;
    }  // c > 0 is checked at call site
};