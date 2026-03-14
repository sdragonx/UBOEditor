
#include "pch.h"
#include "ui.h"

using namespace std;

vec2f mouse;
vec2f lastpos;
int mouse_button; // 1 left button; 2 right button

// main
int main(int argc, char* argv[])
{
    char title[128] = { 0 };
    snprintf(title, _countof(title), "%s %0.2f", "GLSL Uniform Buffer Editor", UBOEDITOR_VERSION);

    // init glfw window
    GLFWwindow* window = initgl(title, screen.x, screen.y, true);

    if (!window) {
        cout << "GLFW window create failed." << endl;
        return -1;
    }

    // events callback
    glfwSetFramebufferSizeCallback(window, reshape_event);
    glfwSetKeyCallback(window, keyboard_event);
    glfwSetMouseButtonCallback(window, mouse_event);
    glfwSetCursorPosCallback(window, motion_event);
    glfwSetScrollCallback(window, scroll_event);

    // imgui
    init_ui(window, false);

    double t = glfwGetTime();
    while (!glfwWindowShouldClose(window)) {
        // update
        t = glfwGetTime() - t;
        update(window, t);
        t = glfwGetTime();

        // clear screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // display
        display(window);
        display_ui(window);

        // swap buffers
        glfwSwapBuffers(window);

        // poll events
        glfwPollEvents();
    }

    // free variable and resource

    // close window
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

void reshape_event(GLFWwindow* window, int width, int height)
{
    // Window size cannot be 0
    if (width == 0 || height == 0) {
        return;
    }
    screen = vec2i(width, height);
    glViewport(0, 0, width, height);
}

void keyboard_event(GLFWwindow* window, int key, int scancode, int action, int modifier)
{
    if (action != GLFW_PRESS) {
        return;
    }

    switch (key) {
    case GLFW_KEY_ESCAPE: // press esc to exit
        glfwSetWindowShouldClose(window, GLFW_TRUE);
        break;

    case GLFW_KEY_F1:
        break;
    case GLFW_KEY_F2:
        break;
    case GLFW_KEY_F3:
        break;
    case GLFW_KEY_F4:
        break;

    default:
        break;
    }
}

void mouse_event(GLFWwindow* window, int button, int action, int mods)
{
}

void motion_event(GLFWwindow* window, double x, double y)
{
    // printf("mouse move : %d, %d\n", int(x), int(y));
}

void scroll_event(GLFWwindow* window, double x, double y)
{
    // printf("scroll : %0.3lf, %0.3lf\n", x, y);
}

void update(GLFWwindow* window, double delay)
{
}

void display(GLFWwindow* window)
{

}
