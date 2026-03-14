#pragma once

#if defined(_MSC_VER)
    #pragma execution_character_set("utf-8")
#endif

#if defined(__GNUC__)
    #pragma GCC diagnostic ignored "-Wmissing-field-initializers"
    #pragma GCC diagnostic ignored "-Wunused-function"
    #pragma GCC diagnostic ignored "-Wunused-parameter"
    #pragma GCC diagnostic ignored "-Wunused-variable"
#endif

#ifndef _USE_MATH_DEFINES
    #define _USE_MATH_DEFINES
#endif

#define UBOEDITOR_VERSION 0.1

// std

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <stdint.h>
#include <string>
#include <vector>

// glew
#if !defined(GLEW_STATIC)
#define GLEW_STATIC
#endif
#include <glew/glew.h>

// glfw
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

// glm
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/io.hpp>
#include <glm/gtx/normal.hpp>
#include <glm/gtx/rotate_vector.hpp>

// imgui
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl2.h>

#include "vertex.h"

#if defined(__BORLANDC__) || defined(_MSC_VER)

    #pragma comment(lib, "opengl32.lib")
    #pragma comment(lib, "glu32.lib")
    #pragma comment(lib, "gdi32.lib")
    #pragma comment(lib, "shell32.lib")

    #if defined(_M_AMD64) || defined(_M_X64)
        #pragma comment(lib, "x64/glfw3.lib")
        #pragma comment(lib, "x64/glew32s.lib")
    #else
        #pragma comment(lib, "x86/glfw3.lib")
        #pragma comment(lib, "x86/glew32s.lib")
    #endif
#endif

#if defined(_MSC_VER)
    #if defined(_DEBUG)
        #pragma comment(lib, "msvcrtd.lib")
        #pragma comment(lib, "vcruntimed.lib")
        #pragma comment(lib, "ucrtd.lib")
    #else
        #pragma comment(lib, "msvcrt.lib")
        #pragma comment(lib, "vcruntime.lib")
        #pragma comment(lib, "ucrt.lib")
    #endif
#endif

#define countof(a) (sizeof(a) / sizeof(a[0]))
#define offset_element(obj,element) ((void*)(offsetof(obj, element)))

typedef uint8_t byte_t;

typedef glm::u8vec3 vec3ub;
typedef glm::u8vec4 vec4ub;
typedef glm::ivec2 vec2i;
typedef glm::ivec3 vec3i;
typedef glm::ivec4 vec4i;
typedef glm::vec2 vec2f;
typedef glm::vec3 vec3f;
typedef glm::vec4 vec4f;
typedef glm::dvec2 vec2d;
typedef glm::dvec3 vec3d;
typedef glm::dvec4 vec4d;
typedef glm::mat3 mat3f;
typedef glm::mat4 mat4f;

//
// io
//

// load file to buffer
template<typename T>
int load_file(std::vector<T>& buf, const std::string& filename)
{
    std::ifstream in;
    in.open(filename.c_str(), std::ios::binary);
    if (in.is_open()) {
        in.seekg(0, std::ios::end);
        size_t size = static_cast<size_t>(in.tellg());
        buf.resize(size / sizeof(T));
        in.seekg(0, std::ios::beg);
        in.read(reinterpret_cast<char*>(buf.data()), buf.size() * sizeof(T));
        return static_cast<int>(in.gcount());
    }
    else {
        std::cout << "load file \"" << filename << "\" failed!" << std::endl;
        return 0;
    }
}

// load string from file
template<typename T>
int load_file(std::basic_string<T>& str, const std::string& filename)
{
    std::vector<T> buf;
    if (load_file(buf, filename)) {
        str.assign(reinterpret_cast<T*>(buf.data()), buf.size());
        return static_cast<int>(buf.size());
    }
    return 0;
}

extern vec2i screen;

// init GLFW window
GLFWwindow* initgl(const std::string& title, int width, int height, bool resizable);

// events
void reshape_event(GLFWwindow* window, int width, int height);
void keyboard_event(GLFWwindow* window, int key, int scancode, int action, int modifier);
void mouse_event(GLFWwindow* window, int button, int action, int mods);
void motion_event(GLFWwindow* window, double x, double y);
void scroll_event(GLFWwindow* window, double x, double y);
void update(GLFWwindow* window, double delay);
void display(GLFWwindow* window);

// string format
const char* imgui_format(const char* param, ...);
