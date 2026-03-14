#include "ubo_editor.h"


// 列表框风格
const ImGuiTableFlags tableFlags =
    ImGuiTableFlags_RowBg |
    // ImGuiTableFlags_SizingFixedFit |
    // ImGuiTableFlags_NoHostExtendX |
    ImGuiTableFlags_ScrollY |
    ImGuiTableFlags_NoHostExtendY |
    ImGuiTableFlags_BordersH | ImGuiTableFlags_BordersV;

int selectedID = -1;

void display_blocks_table(GLuint programID)
{
    char buf[256] = { 0 };
    GLsizei size;
    GLint param;
    bool selected;

    GLint blockSize;
    glGetProgramiv(programID, GL_ACTIVE_UNIFORM_BLOCKS, &blockSize);
    ImGui::Text("blocks: %d", blockSize);

    if (ImGui::BeginTable("##uniform_table", 5, tableFlags, ImVec2(-1.0f, 200.0f))) {
        ImGui::TableNextRow();
        // clang-format off
        ImGui::TableSetColumnIndex(0); ImGui::Text("索引");
        ImGui::TableSetColumnIndex(1); ImGui::Text("名字");
        ImGui::TableSetColumnIndex(2); ImGui::Text("绑定");
        ImGui::TableSetColumnIndex(3); ImGui::Text("数据大小");
        ImGui::TableSetColumnIndex(4); ImGui::Text("成员数量");
        // clang-format on

        for (int blockID = 0; blockID < blockSize; ++blockID) {
            ImGui::TableNextRow();

            selected = selectedID == blockID;

            ImGui::TableSetColumnIndex(0);
            if (ImGui::Selectable(imgui_format("%d##block.id", blockID), &selected)) {
                selectedID = blockID;
            }

            glGetActiveUniformBlockiv(programID, blockID, GL_UNIFORM_BLOCK_NAME_LENGTH, &param);
            glGetActiveUniformBlockName(programID, blockID, param, &size, buf);

            ImGui::TableSetColumnIndex(1);
            if (ImGui::Selectable(imgui_format("%s##block.name", buf), &selected)) {
                selectedID = blockID;
            }

            glGetActiveUniformBlockiv(programID, blockID, GL_UNIFORM_BLOCK_BINDING, &param);
            ImGui::TableSetColumnIndex(2);
            if (ImGui::Selectable(imgui_format("%d##block.binding", param), &selected)) {
                selectedID = blockID;
            }

            glGetActiveUniformBlockiv(programID, blockID, GL_UNIFORM_BLOCK_DATA_SIZE, &param);
            ImGui::TableSetColumnIndex(3);
            if (ImGui::Selectable(imgui_format("%d##block.size", param), &selected)) {
                selectedID = blockID;
            }

            glGetActiveUniformBlockiv(programID, blockID, GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS, &param);
            ImGui::TableSetColumnIndex(4);
            if (ImGui::Selectable(imgui_format("%d##block.uniforms", param), &selected)) {
                selectedID = blockID;
            }
        }

        ImGui::EndTable();
    }
}

void display_uniforms_table(GLuint programID, GLint blockID)
{
    char buf[256] = { 0 };
    GLsizei size;

    GLint uniformSize;
    glGetActiveUniformBlockiv(programID, selectedID, GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS, &uniformSize);
    ImGui::Text("uniforms: %d", uniformSize);

    std::vector<GLint> uniforms;
    uniforms.resize(uniformSize);
    glGetActiveUniformBlockiv(programID, selectedID, GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES, uniforms.data());

    GLint param;

    if (ImGui::BeginTable("##uniform_table", 5, tableFlags)) {
        ImGui::TableNextRow();

        // clang-format off
        ImGui::TableSetColumnIndex(0); ImGui::Text("索引");
        ImGui::TableSetColumnIndex(1); ImGui::Text("名字");
        ImGui::TableSetColumnIndex(2); ImGui::Text("类型");
        ImGui::TableSetColumnIndex(3); ImGui::Text("偏移");
        ImGui::TableSetColumnIndex(4); ImGui::Text("数量");
        // clang-format on

        for (int i = 0; i < uniformSize; ++i) {
            ImGui::TableNextRow();

            GLint uniformID = uniforms[i];
            ImGui::TableSetColumnIndex(0);
            ImGui::Text("%d", uniformID);

            glGetActiveUniformName(programID, uniformID, sizeof(buf), &size, buf);
            ImGui::TableSetColumnIndex(1);
            ImGui::Text("%s", buf);

            glGetActiveUniformsiv(programID, 1, (GLuint*) &uniformID, GL_UNIFORM_TYPE, &param);
            ImGui::TableSetColumnIndex(2);
            ImGui::Text("%s", shader_value_type_to_string(param));

            glGetActiveUniformsiv(programID, 1, (GLuint*) &uniformID, GL_UNIFORM_OFFSET, &param);
            ImGui::TableSetColumnIndex(3);
            ImGui::Text("%d", param);

            glGetActiveUniformsiv(programID, 1, (GLuint*) &uniformID, GL_UNIFORM_SIZE, &param);
            ImGui::TableSetColumnIndex(4);
            ImGui::Text("%d", param);
        }

        ImGui::EndTable();
    }
}

// 显示 UBO
void display_uniform_buffer(GLuint programID, bool& visible)
{
    if (programID == GL_NONE) {
        return;
    }

    int flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
    ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));
    ImGui::SetNextWindowSize(ImVec2(screen.x, screen.y));
    if (ImGui::Begin(imgui_format("Uniform Buffer - program[%d]", programID), &visible, flags)) {
        display_blocks_table(programID);
        // ImGui::Separator();

        if (selectedID != -1) {
            display_uniforms_table(programID, selectedID);
        }
    }
    ImGui::End();
}
