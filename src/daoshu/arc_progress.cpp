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

    QColor arcColor(0, 127, 127, 181);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(arcColor, 15));
    QRectF rect(padding, padding, arcWidth, arcWidth);
    painter.drawArc(rect, 90 * 16, (360 * nSec / totalSec) * 16);
    painter.save();
    QColor tickColor(225, 177, 177, 199);
    painter.setPen(QPen(tickColor, 3));
    painter.translate(width() / 2, width() / 2);
    painter.setFont(QFont("sans", 24));
    auto radius = arcWidth / 2;
    QRectF rectText(-radius, -15, arcWidth, 30);
    auto textOption = QTextOption(Qt::AlignCenter);
    if (nSec) {
        painter.drawText(rectText, "Counting...", textOption);
    } else {
        painter.drawText(rectText, "Time is up!", textOption);
    }
    for (int i = 0; i < 60; ++i) {
        painter.drawLine(radius - 5, 0, radius - 2, 0);
        painter.rotate(6);
    }
    painter.restore();
}

void ArcProgress::decrement() {
    if (this->nSec) {
        this->nSec--;
    } else {
        emit timeUp();
    }
}