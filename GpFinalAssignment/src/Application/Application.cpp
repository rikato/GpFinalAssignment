#include "Application.h"

#include <iostream>

#include "../Renderer/Renderer.h"
#include "../vendor/objLoader/objLoader.h"
#include "../Renderer/Mesh.h"

Application::Application()
{
    if (!glfwInit())
        return;

    m_GlfwWindow = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Graphics programming final assignment", NULL, NULL);

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

    glViewport(0, 0, 1920, 1080);

    // Hide cursor.
    glfwSetInputMode(m_GlfwWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

Application::~Application()
{
    delete m_GlfwWindow;
}

void Application::Start()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glDisable(GL_CULL_FACE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    Renderer renderer;
    Scene scene(m_GlfwWindow);

    double previousFrameTime = 0.0f;

    // Keep the glfw window open until it is instructed to be closed.
    while (!glfwWindowShouldClose(m_GlfwWindow))
    {
        renderer.Clear();

        // Get the current time of this frame and store it.
        double currentFrameTime = glfwGetTime();    
        double deltaTime = currentFrameTime - previousFrameTime;

        // Update the camera and calculate the delta time between frames.
        scene.m_Camera->Update(deltaTime);

        // Set the current time as previous time so we can calculate the delta next frame.
        previousFrameTime = currentFrameTime;

        for (auto model : scene.GetModels())
        {
            model->Update(scene.m_Camera->GetViewMatrix(), scene.m_Camera->GetProjectionMatrix(), deltaTime);
        }

        // Swap front and back buffers.
        glfwSwapBuffers(m_GlfwWindow);

        // Poll for and process events.
        glfwPollEvents();
    }

    // Clean up all glfw resources when exiting the application.
    glfwTerminate();
}