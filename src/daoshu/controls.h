#pragma once
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

class Controls : public QWidget {
    Q_OBJECT

   public:
    QLineEdit *msgField;
    Controls(QWidget *parent = 0);
    virtual ~Controls(){};

   private:
    void disableSpins();
    void enableSpins();
    void disableMsgField();
    void enableMsgField();
    void initSpinValues();
    QString enabledSpinStyle();
    QString disabledSpinStyle();
	int hours = 0;
	int minutes = 0;
	int seconds = 3;

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
