#include "ui.h"

#include "src/glcommon.h"
#include "src/ubo_editor.h"
#include "src/ubo_viewer.h"

static bool _m_uboEditor = true;
static bool _m_uboViewer = false;

void init_ui(GLFWwindow* window, bool useSettings)
{
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();

    // 关闭 ImGui 配置文件的显示
    if (!useSettings) {
        io.WantSaveIniSettings = false;
        io.IniFilename = nullptr;
    }

    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
    // io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;    // Enable Gamepad Controls
    // io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;  // Disable Mouse Cursor

    // io.Fonts->AddFontFromFileTTF("c:/windows/fonts/consola.ttf", 16.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());
    // io.Fonts->AddFontFromFileTTF("c:/windows/fonts/msyh.ttc", 20.0f, NULL, io.Fonts->GetGlyphRangesChineseSimplifiedCommon());
    io.Fonts->AddFontFromFileTTF("c:/windows/fonts/msyh.ttc", 20.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());
    // io.Fonts->AddFontFromFileTTF("X:/bin/assets/msyhc.ttf", 20.0f, NULL, io.Fonts->GetGlyphRangesDefault());

    // For Microsoft IME, pass your HWND to enable IME positioning:
    // io.ImeWindowHandle = my_hwnd;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    // ImGui::StyleColorsLight();
    // ImGui::StyleColorsClassic();
    ImGui::GetStyle().FrameBorderSize = 1.0f;

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL2_Init();
}

static void ui_begin()
{
    // Start the Dear ImGui frame
    ImGui_ImplOpenGL2_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

static void ui_end()
{
    // Rendering
    ImGui::Render();

    // GLint last_program;
    // glGetIntegerv(GL_CURRENT_PROGRAM, &last_program);
    // glUseProgram(0);
    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
    // glUseProgram(last_program);
}

void display_ui(GLFWwindow* window)
{
    glViewport(0, 0, screen.x, screen.y);

    ui_begin();

    if (_m_uboEditor) {
        display_ubo_editor(_m_uboEditor);
    }

    if (_m_uboViewer) {
        // display_uniform_buffer(program.id(), _m_uboViewer);
    }

    ui_end();
}
