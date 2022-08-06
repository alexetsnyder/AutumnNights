#ifndef COORDINATE_H
#define COORDINATE_H

#include <QBrush>

using namespace std;

class Coordinate
{
    public:
        Coordinate(QPoint leftTop = QPoint(0, 0), QPoint size = QPoint(10, 10));

        void setPos(QPoint leftTop);
        void setPosCenter(QPoint center);
        void setText(string text);
        void setSize(QPoint size);

    protected:
        QPoint leftTop;
        QPoint leftBottom;
        QPoint rightTop;
        QPoint rightBottom;
        QPoint center;

        QPoint size;
        int width;
        int height;
};

#endif // COORDINATE_H
