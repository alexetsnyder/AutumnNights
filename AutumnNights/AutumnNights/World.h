#pragma once
#include <vector>
#include <string>

class World
{
	public:
		World();
		World(int rows, int cols);
		void Update();
		std::string Draw();

	private:
		void Initialize(int rows, int cols);
		void Initialize_Grid_Rows();
		void Clear(int value);
		int cols, rows;
		std::vector<std::vector<int>> grid;

};

