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

    Grid3D grid(QPoint(width() * 2, height() * 2), 10);
    grid.setViewport(QRect(100, 100, width(), height()));
    grid.drawTo(pixMap);
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.drawPixmap(QPoint(0, 0), pixMap);

    painter.end();
}

void Canvas::keyPressEvent(QKeyEvent *event)
{
    keys.push_back(event->key());
}

void Canvas::keyReleaseEvent(QKeyEvent *event)
{
    auto i = getIteratorOfKey(event->key());
    if (i != keys.end())
    {
       keys.erase(i);
    }
}

vector<int>::iterator Canvas::getIteratorOfKey(int key)
{
    for (auto i = keys.begin(); i != keys.end(); ++i)
    {
        if (*i == key)
        {
            return i;
        }
    }
    return keys.end();
}
