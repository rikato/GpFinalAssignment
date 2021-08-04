#include <iostream>
#include "Window.h"
#include "Renderer.h"

Window::Window()
    :scene(nullptr), glfwWindow(nullptr)
{
    if (!glfwInit())
        return;

    glfwWindow = glfwCreateWindow(800, 600, "Graphics programming final assignment", NULL, NULL);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwMakeContextCurrent(glfwWindow);

    if (glfwWindow == NULL)
    {
        std::cout << "Failed to create glfw window" << std::endl;

        glfwTerminate();

        return;
    }

    // Let's make sure glad is loaded before using any OpenGl functions.
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize Glad" << std::endl;

        return;
    }

    glViewport(0, 0, 800, 600);

    scene = new Scene();
}

Window::~Window()
{
    scene->~Scene();
}

void Window::Update()
{
    /* Render here */
    GLCall(glClear(GL_COLOR_BUFFER_BIT));

    GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

    glEnd();

    /* Swap front and back buffers */
    glfwSwapBuffers(glfwWindow);

    /* Poll for and process events */
    glfwPollEvents();
}
