#ifndef GRID3D_H
#define GRID3D_H

#include <vector>
#include <QPixmap>
#include "tile.h"

class Grid3D : public Coordinate
{
    public:
        Grid3D(QPoint size, int tileSize, QPoint leftTop = QPoint(0, 0));

        void init();

        void setViewport(QRect viewport);

        void drawTo(QPixmap& pixMap);

    private:
        string GetRandomChar();
        QColor GetRandomColor();
        int GetRandomInt(int n, int m);

        bool hasViewport;
        QRect viewport;
        int rows, cols;
        int x, y, z;
        int tileSize;
        vector<vector<Tile>> grid;
};

#endif // GRID3D_H
