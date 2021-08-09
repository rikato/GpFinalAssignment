#include "Application.h"

#include <iostream>

#include "../Renderer/Renderer.h"
#include "../vendor/objLoader/objLoader.h"
#include "../Renderer/Mesh.h"

Application::Application()
{
    if (!glfwInit())
        return;

    m_GlfwWindow = glfwCreateWindow(800, 600, "Graphics programming final assignment", NULL, NULL);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwMakeContextCurrent(m_GlfwWindow);

    if (m_GlfwWindow == NULL)
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
}

Application::~Application()
{
    delete m_GlfwWindow;
}

void Application::Start()
{
    Renderer renderer;
    Scene scene(m_GlfwWindow);

    // Keep the glfw window open until it is instructed to be closed.
    while (!glfwWindowShouldClose(m_GlfwWindow))
    {
        renderer.Clear();

        scene.m_Camera->Update();

        for (auto object : scene.m_Objects)
        {
            object->Update(scene.m_Camera->GetViewMatrix(), scene.m_Camera->GetProjectionMatrix());
        }

        // Swap front and back buffers.
        glfwSwapBuffers(m_GlfwWindow);

        // Poll for and process events.
        glfwPollEvents();
    }

    // Clean up all glfw resources when exiting the application.
    glfwTerminate();
}