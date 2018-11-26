#include <QtCore/QDebug>
#include <QtWidgets/QtWidgets>

#include "arc_progress.h"

ArcProgress::ArcProgress(int width, QWidget *parent)
    : QWidget(parent), initWidth(width) {
    this->setFixedSize(QSize(width, width));
    padding = width / 10;
    arcWidth = width - 2 * padding;
}

void ArcProgress::paintEvent(QPaintEvent *) {
    static const QPoint secondHand[3] = {QPoint(3, 8), QPoint(-3, 8),
                                         QPoint(0, -90)};

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QColor arcColor(0, 127, 127, 181);
    painter.setPen(QPen(arcColor, 15));
    QRectF rect(padding, padding, arcWidth, arcWidth);
    auto arcEnd = (360 * nMilliSec / totalMilliSec);
    painter.drawArc(rect, 90 * 16, arcEnd * 16);
    painter.save();
    QColor blinkColor(128, 27, 27, 255);
    painter.setPen(QPen(blinkColor, 15));
    if (blink) {
        painter.drawArc(rect, (90 + arcEnd) * 16, 1 * 16);
    }
    blink = !blink;
    painter.restore();
    QColor tickColor(225, 177, 177, 199);
    painter.setPen(QPen(tickColor, 3));
    painter.translate(width() / 2, width() / 2);
    painter.setFont(QFont("sans", 24));
    auto radius = arcWidth / 2;
    QRectF rectText(-radius, -15, arcWidth, 30);
    auto textOption = QTextOption(Qt::AlignCenter);
    if (nMilliSec) {
        painter.drawText(rectText, "Counting...", textOption);
    } else {
        painter.drawText(rectText, "Time is up!", textOption);
    }
    // paint the ticks
    for (int i = 0; i < 60; ++i) {
        painter.drawLine(radius - 5, 0, radius - 2, 0);
        painter.rotate(6);
    }
    // painter.restore();
}

void ArcProgress::decrement() {
    if (this->nMilliSec) {
        this->nMilliSec -= 100;
    } else {
        blink = false;
        emit timeUp();
    }
}

void ArcProgress::handleCancel() { nMilliSec = 0; }