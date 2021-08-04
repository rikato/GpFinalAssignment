#include "Application/Application.h"

int main(void)
{
    Application* application;

    application = new Application();

    application->Start();

    return 0;
}