#include "tile.h"
#include <QPainter>

Tile::Tile(QPoint leftTop, QPoint size)
{
    tileBackground = QBrush(Qt::red);
    tilePen = QPen(Qt::black);
    textPen = QPen(Qt::white);
    textFont = QFont();
    textFont.setPixelSize(12);

    setSize(size);
    setPos(leftTop);

    setText("~");
}

void Tile::setSize(QPoint size)
{
    this->size = size;
    this->width = size.x();
    this->height = size.y();
}

void Tile::setPos(QPoint leftTop)
{
    int left = leftTop.x();
    int top = leftTop.y();
    int bottom = top + width;
    int right = left + height;

    this->leftTop = QPoint(left, top);
    this->leftBottom = QPoint(left, bottom);
    this->rightTop = QPoint(right, top);
    this->rightBottom = QPoint(right, bottom);
    this->center = QPoint(left + width / 2, top + height / 2);
}

void Tile::setPosCenter(QPoint center)
{
   QPoint leftTop(center.x() - width / 2, center.y() - height / 2);
   setPos(leftTop);
}

void Tile::setText(string text)
{
    tileText = text;
}

void Tile::drawTo(QPixmap& pixMap)
{
    QPainter painter;
    painter.begin(&pixMap);
    painter.setBrush(tileBackground);
    painter.setPen(tilePen);
    painter.drawRect(QRect(leftTop, QSize(width, height)));

    painter.setPen(textPen);
    painter.setFont(textFont);
    painter.drawText(
                QRect(leftTop, QSize(width, height / 2)),
                Qt::AlignCenter,
                QString::fromStdString(tileText));
    painter.end();
}


