#include "Application.h"
#include <iostream>

Application::Application()
{
}

Application::~Application()
{
}

void Application::Start()
{
    // Keep the glfw window open until it is instructed to be closed.
    while (!glfwWindowShouldClose(window.glfwWindow))
    {
        window.Update();
    }

    window.~Window();

    // Clean up all glfw resources when exiting the application.
    glfwTerminate();
}