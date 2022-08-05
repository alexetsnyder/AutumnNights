#include "World.h"

World::World()
{
	Initialize(0, 0);
}

World::World(int rows, int cols)
{
	Initialize(rows, cols);
}

void World::Initialize(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	grid = std::vector<std::vector<int>>();
	Initialize_Grid_Rows();
	Clear(0);
}

void World::Initialize_Grid_Rows()
{
	for (int i = 0; i < rows; ++i)
	{
		grid.push_back(std::vector<int>());
		for (int j = 0; j < cols; ++j)
		{
			grid[i].push_back(1);
		}
	}
}

void World::Update()
{
}

std::string World::Draw()
{
	std::string world_string = "";
	for (auto grid_row : grid)
	{
		for (auto grid_value : grid_row)
		{
			world_string += std::to_string(grid_value);
		}
		world_string += "\n";
	}
	return world_string;
}

void World::Clear(int value)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			grid[i][j] = value;
		}
	}
}

