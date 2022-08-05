#ifndef TILE_H
#define TILE_H

#include <QFont>
#include <QBrush>
#include <QPen>
#include <string>

using namespace std;

class Tile
{
    public:
        Tile(QPoint leftTop = QPoint(0, 0), QPoint size = QPoint(10, 10));

        void setPos(QPoint leftTop);
        void setPosCenter(QPoint center);
        void setText(string text);
        void setSize(QPoint size);

        void drawTo(QPixmap& pixMap);

    private:
        string tileText;

        QPoint leftTop;
        QPoint leftBottom;
        QPoint rightTop;
        QPoint rightBottom;
        QPoint center;

        QPoint size;
        int width;
        int height;

        QBrush tileBackground;
        QPen tilePen;
        QPen textPen;
        QFont textFont;
};

#endif // TILE_H
