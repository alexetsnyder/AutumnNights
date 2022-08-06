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

void Tile::setBackground(QColor color)
{
    tileBackground = QBrush(color);
}

void Tile::setText(string text)
{
    tileText = text;
}

void Tile::drawTo(QPixmap& pixMap, QPoint point)
{
    int left = leftTop.x() - point.x();
    int top = leftTop.y() - point.y();

    QPainter painter;
    painter.begin(&pixMap);
    painter.setBrush(tileBackground);
    painter.setPen(tilePen);
    painter.drawRect(QRect(QPoint(left, top), QSize(width, height)));

    painter.setPen(textPen);
    painter.setFont(textFont);
    painter.drawText(
                QRect(QPoint(left, top), QSize(width, height / 2)),
                Qt::AlignCenter,
                QString::fromStdString(tileText));
    painter.end();
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


