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

        void drawTo(QPixmap& pixMap);

    private:
        int rows, cols;
        int x, y, z;
        int tileSize;
        vector<vector<Tile>> grid;
};

#endif // GRID3D_H
