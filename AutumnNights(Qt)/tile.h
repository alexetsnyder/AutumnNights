#ifndef TILE_H
#define TILE_H

#include <QFont>
#include <QBrush>
#include <QPen>
#include "coordinate.h"

using namespace std;

class Tile : public Coordinate
{
    public:
        Tile(QPoint leftTop = QPoint(0, 0), QPoint size = QPoint(10, 10));

        void setText(string text);
        void setBackground(QColor color);

        void drawTo(QPixmap& pixMap);
        void drawTo(QPixmap& pixMap, QPoint point);

    private:
        string tileText;

        QBrush tileBackground;
        QPen tilePen;
        QPen textPen;
        QFont textFont;
};

#endif // TILE_H
