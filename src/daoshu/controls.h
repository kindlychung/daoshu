#pragma once
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

class Controls : public QWidget {
    Q_OBJECT

   public:
    Controls(QWidget *parent = 0);
    virtual ~Controls(){};

   private:
    void disableSpins();
    void enableSpins();
    void initSpinValues();

   protected:
    QSpinBox *hourSpin;
    QSpinBox *minSpin;
    QSpinBox *secSpin;
    QHBoxLayout *spinLayout;
    QHBoxLayout *buttonLayout;
    QVBoxLayout *controlLayout;
    QPushButton *setButton;
    QPushButton *cancelButton;
   private slots:
    void setButtonClicked();
    void cancelButtonClicked();
   public slots:
    void handleTimeup();
    void handleCancel();
    void decrement();
   signals:
    void valueSet(int nMilliSec);
    void timerCancelled();
};
