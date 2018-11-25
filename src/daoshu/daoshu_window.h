#pragma once
#include <QtCore/QTimer>
#include <QtWidgets/QStackedLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "arc_progress.h"
#include "controls.h"

class DaoshuWindow : public QWidget {
    Q_OBJECT

   public:
    DaoshuWindow(int width = 300, QWidget* parent = 0);

   protected:
    QTimer* timer;
    QVBoxLayout* layout;
    Controls* controls;
    ArcProgress* arcUI;
   public slots:
    void startTimer();
    void timeUpAudio();
    void stopTimer();
    void startCountdown(int nMilliSec);
};
