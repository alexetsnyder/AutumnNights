#include "canvas.h"
#include <QPainter>
#include <QBrush>
#include <QPen>

Canvas::Canvas(QWidget *parent)
    : QWidget{parent}
{

}

void Canvas::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.fillRect(QRect(), QBrush(QColor(65, 32, 64)));

    painter.setBrush(QBrush(Qt::red));
    painter.setPen(QPen(Qt::black));

    painter.translate(width() / 2, height() / 2);

    painter.drawRect(QRect(-50, -50, 100, 100));

    painter.end();
}
