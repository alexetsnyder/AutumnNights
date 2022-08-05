#include "grid3d.h"
#include <random>

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

    hasViewport = false;

    srand(time(0));
}

void Grid3D::init()
{
    for (int i = 0; i < rows; ++i)
    {
        grid.push_back(vector<Tile>());
        for (int j = 0; j < cols; ++j)
        {
            Tile tile(QPoint(i * tileSize, j * tileSize), QPoint(tileSize, tileSize));
            tile.setBackground(GetRandomColor());
            tile.setText(GetRandomChar());
            grid[i].push_back(tile);
        }
    }
}

void Grid3D::setViewport(QRect viewport)
{
    this->viewport = viewport;
    hasViewport = true;
}

void Grid3D::drawTo(QPixmap& pixMap)
{
    if (hasViewport)
    {
        int startRow = viewport.left() / tileSize;
        int startCol = viewport.top() / tileSize;
        int endRow = viewport.width() / tileSize;
        int endCol = viewport.height() / tileSize;

        for (int i = startRow; i < endRow; ++i)
        {
            for (int j = startCol; j < endCol; ++j)
            {
                grid[i][j].drawTo(pixMap);
            }
        }
    }
    else
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                grid[i][j].drawTo(pixMap);
            }
        }
    }
}

string Grid3D::GetRandomChar()
{
    string c;
    c = (char)GetRandomInt(0, 128);
    return c;
}

QColor Grid3D::GetRandomColor()
{
    int red = GetRandomInt(0, 255);
    int green = GetRandomInt(0, 255);
    int blue = GetRandomInt(0, 255);
    return QColor(red, green, blue);
}

int Grid3D::GetRandomInt(int n, int m)
{
    return (rand() % (m - 1)) + n;
}
