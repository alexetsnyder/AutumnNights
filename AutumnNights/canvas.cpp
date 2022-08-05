#include "canvas.h"
#include <QPaintEvent>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include "grid3d.h"

Canvas::Canvas(QWidget *parent)
    : QWidget{parent}
{
    setMinimumSize(800, 400);

    background = QBrush(Qt::gray);
    pixMap = QPixmap(width(), height());
}

void Canvas::draw()
{
    QPainter painter;
    painter.begin(&pixMap);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.fillRect(QRect(0, 0, width(), height()), background);
    painter.end();

    Grid3D grid(QPoint(width(), height()), 10);
    grid.drawTo(pixMap);

//    Tile tile;
//    tile.setPosCenter(QPoint(width() / 2, height() / 2));
//    tile.drawTo(pixMap);
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.drawPixmap(QPoint(0, 0), pixMap);

//    painter.fillRect(event->rect(), background);

//    painter.setBrush(QBrush(Qt::red));
//    painter.setPen(QPen(Qt::black));

//    painter.translate(width() / 2, height() / 2);

//    painter.drawRect(QRect(-50, -50, 100, 100));

    painter.end();
}
