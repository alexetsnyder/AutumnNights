#include "grid3d.h"

Grid3D::Grid3D(QPoint size, int tileSize, QPoint leftTop)
    : Coordinate(leftTop, size)
{
    x = 0;
    y = 0;
    z = 0;
    this->tileSize = tileSize;

    rows = size.x() / tileSize;
    cols = size.y() / tileSize;

    init();
}

void Grid3D::init()
{
    for (int i = 0; i < rows; ++i)
    {
        grid.push_back(vector<Tile>());
        for (int j = 0; j < cols; ++j)
        {
            Tile tile(QPoint(i * tileSize, j * tileSize), QPoint(tileSize, tileSize));
            grid[i].push_back(tile);
        }
    }
}

void Grid3D::drawTo(QPixmap& pixMap)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            grid[i][j].drawTo(pixMap);
        }
    }
}

