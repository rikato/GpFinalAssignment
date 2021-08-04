#pragma once
#include "Window.h"

class Application 
{
public:
	Window window;

	Application();
	~Application();

	void Start();

private:
	bool isRunning = true;
};
