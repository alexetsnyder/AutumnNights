#include "coordinate.h"

Coordinate::Coordinate(QPoint leftTop, QPoint size)
{
    setSize(size);
    setPos(leftTop);
}

void Coordinate::setSize(QPoint size)
{
    this->size = size;
    this->width = size.x();
    this->height = size.y();
}

void Coordinate::setPos(QPoint leftTop)
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

void Coordinate::setPosCenter(QPoint center)
{
   QPoint leftTop(center.x() - width / 2, center.y() - height / 2);
   setPos(leftTop);
}
