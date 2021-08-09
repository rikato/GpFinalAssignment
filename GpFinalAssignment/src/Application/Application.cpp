#include "Application.h"

#include <iostream>

#include "../Renderer/Renderer.h"
#include "../vendor/objLoader/objLoader.h"
#include "../Helpers/Mesh.h"

Application::Application()
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
}

Application::~Application()
{
    delete glfwWindow;
}

void Application::Start()
{
    Renderer renderer;
    Scene scene(glfwWindow);

    // Keep the glfw window open until it is instructed to be closed.
    while (!glfwWindowShouldClose(glfwWindow))
    {
        renderer.Clear();

        scene.camera->Update();

        for (auto object : scene.objects)
        {
            object->Update(scene.camera->GetViewMatrix(), scene.camera->GetProjectionMatrix());
        }

        // Swap front and back buffers.
        glfwSwapBuffers(glfwWindow);

        // Poll for and process events.
        glfwPollEvents();
    }

    // Clean up all glfw resources when exiting the application.
    glfwTerminate();
}