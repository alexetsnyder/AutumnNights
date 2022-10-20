#pragma once
#include <GLFW/glfw3.h>
#include <string>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

class Window
{
	public:
		Window();
		Window(std::string title, int width, int height);

		void init();

		void setTitle(std::string title);
		void setSize(int width, int height);
		void setWidth(int width);
		void setHeight(int height);
		void setFrambufferCallback(GLFWframebuffersizefun callback);

		bool isRunning();
		void terminate(int retVal);
		void swapBuffers();
		void pollEvents();
		void free();

	private:
		GLFWwindow* window;
		std::string title;
		int width, height;
};

