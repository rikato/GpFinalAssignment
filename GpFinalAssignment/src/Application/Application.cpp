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

    //scene = new Scene(glfwWindow);
}

Application::~Application()
{
}

void Application::Start()
{
    Renderer renderer;

    // Setup the shader for this mesh.
    Shader shader("assets/shaders/Basic.shader");
    shader.Bind();

    Mesh teapot("assets/models/teapot/teapot.obj");

    Camera camera(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glfwWindow);

    // Keep the glfw window open until it is instructed to be closed.
    while (!glfwWindowShouldClose(glfwWindow))
    {
        renderer.Clear();

        //Set the shader uniforms.
        shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);

        //Set the shader uniforms.
        shader.SetUniformMat4f("MVP", camera.GetMVP());

        teapot.Draw();

        // Swap front and back buffers.
        glfwSwapBuffers(glfwWindow);

        // Poll for and process events.
        glfwPollEvents();
    }

    // Clean up all glfw resources when exiting the application.
    glfwTerminate();
}