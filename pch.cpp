#include "pch.h"

using namespace std;

vec2i screen(1280, 720);

// glfw error callback
void error_event(int error, const char* description)
{
    printf("glfw> 0x%08X: %s\n", error, description);
}

// init GLFW window
GLFWwindow* initgl(const std::string& title, int width, int height, bool resizable)
{
    // set error callback
    glfwSetErrorCallback(error_event);

    // init glfw
    if (!glfwInit()) {
        return nullptr;
    }

    // 初始化 glfw 配置

    // Open window (ask for OpenGL ES 3.0 or better)
    //glfwWindowHint( GLFW_CLIENT_API, GLFW_OPENGL_ES_API );
    //glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    //glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 0 );

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);       // 设置 OpenGL 任意渲染模式
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);      // 设置 OpenGL 核心渲染模式
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);    // 设置 OpenGL 兼容渲染模式

    #if MACOS
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
    #endif

    // multisampling
    glfwWindowHint(GLFW_SAMPLES, 4);

    // window resizable
    glfwWindowHint(GLFW_RESIZABLE, resizable ? GLFW_TRUE : GLFW_FALSE);

    // create window
    GLFWwindow* window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    if (!window) {
        glfwTerminate();
        return nullptr;
    }

    // make current
    glfwMakeContextCurrent(window);

    // vertical sync
    glfwSwapInterval(1);

    // init glew
    if (GLEW_OK != glewInit()) {
        printf("glew> OpenGL extensions loading failed.\n");
    }

    printf("GL_RENDERER: %s %s\n", glGetString(GL_VENDOR), glGetString(GL_RENDERER));
    printf("GL_VERSION : %s\n", glGetString(GL_VERSION));
    printf("GL_SHADING_LANGUAGE_VERSION: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));

    //
    // init opengl state
    //

    glClearColor(0.0f, 0.5f, 1.0f, 1.0f);

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glDepthFunc(GL_LEQUAL);
    glClearDepth(1.0);

    return window;
}

// string format
const char* imgui_format(const char* param, ...)
{
    static char buf[256] = { 0 };

    va_list body;
    va_start(body, param);
    std::vsnprintf(buf, sizeof(buf), param, body);
    va_end(body);

    return buf;
}
