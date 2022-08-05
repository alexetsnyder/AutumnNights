#include "tile.h"
#include <QPainter>

Tile::Tile(QPoint leftTop, QPoint size)
    : Coordinate(leftTop, size)
{
    tileBackground = QBrush(Qt::red);
    tilePen = QPen(Qt::black);
    textPen = QPen(Qt::white);
    textFont = QFont();
    textFont.setPixelSize(12);

    setText("~");
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


