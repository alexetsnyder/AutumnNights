#pragma once
#include <GLFW/glfw3.h>
#include <string>

class Window
{
	public:
		Window();
		Window(std::string title, int width, int height);

	private:
		std::string title;
		int width, height;
};

