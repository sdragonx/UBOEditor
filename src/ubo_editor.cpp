#include "ubo_editor.h"

//------------------------------------------------------------------------------

void push_color(GLenum e)
{
    switch (e) {
    // base
    case GL_BOOL:
    case GL_INT:
#if defined(GL_UNSIGNED_INT)
    case GL_UNSIGNED_INT:
#endif
    case GL_FLOAT:
#if defined(GL_DOUBLE)
    case GL_DOUBLE:
#endif

    // vec<N, T>
    case GL_BOOL_VEC2:
    case GL_BOOL_VEC3:
    case GL_BOOL_VEC4:
    case GL_INT_VEC2:
    case GL_INT_VEC3:
    case GL_INT_VEC4:
    case GL_UNSIGNED_INT_VEC2:
    case GL_UNSIGNED_INT_VEC3:
    case GL_UNSIGNED_INT_VEC4:
    case GL_FLOAT_VEC2:
    case GL_FLOAT_VEC3:
    case GL_FLOAT_VEC4:

        ImGui::PushStyleColor(ImGuiCol_Button, 0xFF008000);
        break;

    // mat<M, N, T>
    case GL_FLOAT_MAT2:
    case GL_FLOAT_MAT2x3:
    case GL_FLOAT_MAT2x4:
    case GL_FLOAT_MAT3:
    case GL_FLOAT_MAT3x2:
    case GL_FLOAT_MAT3x4:
    case GL_FLOAT_MAT4:
    case GL_FLOAT_MAT4x2:
    case GL_FLOAT_MAT4x3:
#if defined(GL_DOUBLE)
    case GL_DOUBLE_MAT2:
    case GL_DOUBLE_MAT3:
    case GL_DOUBLE_MAT4:
    case GL_DOUBLE_MAT2x3:
    case GL_DOUBLE_MAT2x4:
    case GL_DOUBLE_MAT3x2:
    case GL_DOUBLE_MAT3x4:
    case GL_DOUBLE_MAT4x2:
    case GL_DOUBLE_MAT4x3:
    case GL_DOUBLE_VEC2:
    case GL_DOUBLE_VEC3:
    case GL_DOUBLE_VEC4:
#endif

        ImGui::PushStyleColor(ImGuiCol_Button, 0xFFFF8000);
        // ImGui::PushStyleColor(ImGuiCol_Button, 0xFFFF6000);
        // ImGui::PushStyleColor(ImGuiCol_Button, 0xFFFF4000);
        break;

        // samplers

#if defined(GL_SAMPLER_1D)
    case GL_SAMPLER_1D:
    case GL_SAMPLER_1D_SHADOW:
    case GL_SAMPLER_1D_ARRAY_SHADOW:
#endif

    case GL_SAMPLER_2D:
    case GL_SAMPLER_2D_SHADOW:
    case GL_SAMPLER_2D_ARRAY_SHADOW:
    case GL_SAMPLER_2D_MULTISAMPLE:
    case GL_SAMPLER_2D_MULTISAMPLE_ARRAY:
#if defined(GL_SAMPLER_2D_RECT)
    case GL_SAMPLER_2D_RECT:
    case GL_SAMPLER_2D_RECT_SHADOW:
#endif
    case GL_SAMPLER_3D:
    case GL_SAMPLER_BUFFER:
    case GL_SAMPLER_CUBE:
    case GL_SAMPLER_CUBE_SHADOW:
    case GL_SAMPLER_CUBE_MAP_ARRAY:
    case GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW:

#if defined(GL_INT_SAMPLER_1D)
    case GL_INT_SAMPLER_1D:
    case GL_INT_SAMPLER_1D_ARRAY:
#endif
    case GL_INT_SAMPLER_2D:
    case GL_INT_SAMPLER_2D_ARRAY:
    case GL_INT_SAMPLER_2D_MULTISAMPLE:
    case GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY:
#if defined(GL_INT_SAMPLER_2D_RECT)
    case GL_INT_SAMPLER_2D_RECT:
#endif
    case GL_INT_SAMPLER_3D:
    case GL_INT_SAMPLER_BUFFER:
    case GL_INT_SAMPLER_CUBE:
    case GL_INT_SAMPLER_CUBE_MAP_ARRAY:

#if defined(GL_UNSIGNED_INT_SAMPLER_1D)
    case GL_UNSIGNED_INT_SAMPLER_1D:
    case GL_UNSIGNED_INT_SAMPLER_1D_ARRAY:
#endif
    case GL_UNSIGNED_INT_SAMPLER_2D:
    case GL_UNSIGNED_INT_SAMPLER_2D_ARRAY:
    case GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE:
    case GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY:
#if defined(GL_UNSIGNED_INT_SAMPLER_2D_RECT)
    case GL_UNSIGNED_INT_SAMPLER_2D_RECT:
#endif
    case GL_UNSIGNED_INT_SAMPLER_3D:
    case GL_UNSIGNED_INT_SAMPLER_BUFFER:
    case GL_UNSIGNED_INT_SAMPLER_CUBE:
    case GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY:
        break;

        // images

#if defined(GL_IMAGE_1D)
    case GL_IMAGE_1D:
    case GL_IMAGE_1D_ARRAY:
#endif
    case GL_IMAGE_2D:
    case GL_IMAGE_2D_ARRAY:
#if defined(GL_IMAGE_2D_RECT)
    case GL_IMAGE_2D_RECT:
    case GL_IMAGE_2D_MULTISAMPLE:
    case GL_IMAGE_2D_MULTISAMPLE_ARRAY:
#endif
    case GL_IMAGE_3D:
    case GL_IMAGE_BUFFER:
    case GL_IMAGE_CUBE:
    case GL_IMAGE_CUBE_MAP_ARRAY:

#if defined(GL_INT_IMAGE_1D)
    case GL_INT_IMAGE_1D:
    case GL_INT_IMAGE_1D_ARRAY:
#endif
    case GL_INT_IMAGE_2D:
    case GL_INT_IMAGE_2D_ARRAY:
#if defined(GL_INT_IMAGE_2D_RECT)
    case GL_INT_IMAGE_2D_RECT:
    case GL_INT_IMAGE_2D_MULTISAMPLE:
    case GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY:
#endif
    case GL_INT_IMAGE_3D:
    case GL_INT_IMAGE_BUFFER:
    case GL_INT_IMAGE_CUBE:
    case GL_INT_IMAGE_CUBE_MAP_ARRAY:

#if defined(GL_UNSIGNED_INT_IMAGE_1D)
    case GL_UNSIGNED_INT_IMAGE_1D:
    case GL_UNSIGNED_INT_IMAGE_1D_ARRAY:
#endif
    case GL_UNSIGNED_INT_IMAGE_2D:
    case GL_UNSIGNED_INT_IMAGE_2D_ARRAY:
#if defined(GL_UNSIGNED_INT_IMAGE_2D_RECT)
    case GL_UNSIGNED_INT_IMAGE_2D_RECT:
    case GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE:
    case GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY:
#endif
    case GL_UNSIGNED_INT_IMAGE_3D:
    case GL_UNSIGNED_INT_IMAGE_BUFFER:
    case GL_UNSIGNED_INT_IMAGE_CUBE:
    case GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY:
        break;
    default:
        break;
    }
}

void pop_color(GLenum type)
{
    switch (type) {
    // base
    case GL_BOOL:
    case GL_INT:
#if defined(GL_UNSIGNED_INT)
    case GL_UNSIGNED_INT:
#endif
    case GL_FLOAT:
#if defined(GL_DOUBLE)
    case GL_DOUBLE:
#endif

    // vec<N, T>
    case GL_BOOL_VEC2:
    case GL_BOOL_VEC3:
    case GL_BOOL_VEC4:
    case GL_INT_VEC2:
    case GL_INT_VEC3:
    case GL_INT_VEC4:
    case GL_UNSIGNED_INT_VEC2:
    case GL_UNSIGNED_INT_VEC3:
    case GL_UNSIGNED_INT_VEC4:
    case GL_FLOAT_VEC2:
    case GL_FLOAT_VEC3:
    case GL_FLOAT_VEC4:

        ImGui::PopStyleColor();
        break;

    // mat<M, N, T>
    case GL_FLOAT_MAT2:
    case GL_FLOAT_MAT2x3:
    case GL_FLOAT_MAT2x4:
    case GL_FLOAT_MAT3:
    case GL_FLOAT_MAT3x2:
    case GL_FLOAT_MAT3x4:
    case GL_FLOAT_MAT4:
    case GL_FLOAT_MAT4x2:
    case GL_FLOAT_MAT4x3:

#if defined(GL_DOUBLE)
    case GL_DOUBLE_MAT2:
    case GL_DOUBLE_MAT3:
    case GL_DOUBLE_MAT4:
    case GL_DOUBLE_MAT2x3:
    case GL_DOUBLE_MAT2x4:
    case GL_DOUBLE_MAT3x2:
    case GL_DOUBLE_MAT3x4:
    case GL_DOUBLE_MAT4x2:
    case GL_DOUBLE_MAT4x3:
    case GL_DOUBLE_VEC2:
    case GL_DOUBLE_VEC3:
    case GL_DOUBLE_VEC4:
#endif
        ImGui::PopStyleColor();
        break;

#if defined(GL_SAMPLER_1D)
    case GL_SAMPLER_1D:
#endif
    case GL_SAMPLER_2D:
    case GL_SAMPLER_3D:
    case GL_SAMPLER_CUBE:
#if defined(GL_SAMPLER_1D_SHADOW)
    case GL_SAMPLER_1D_SHADOW:
#endif
    case GL_SAMPLER_2D_SHADOW:
        break;
    default:
        break;
    }
}

//------------------------------------------------------------------------------

// 列表框风格
const ImGuiTableFlags tableFlags =
    ImGuiTableFlags_RowBg |
    // ImGuiTableFlags_SizingFixedFit |
    // ImGuiTableFlags_NoHostExtendX |
    ImGuiTableFlags_ScrollY |
    ImGuiTableFlags_NoHostExtendY |
    ImGuiTableFlags_BordersH | ImGuiTableFlags_BordersV;

//------------------------------------------------------------------------------

// 显示变量列表
void display_uniforms_table(
    GLuint programID,
    GLint uniformSize,
    std::vector<GLint> uniforms,
    std::vector<GLint> types,
    std::vector<GLint> offsets,
    std::vector<GLint> sizes
)
{
    GLsizei size;
    char buf[256] = { 0 };

    /*
    if (ImGui::BeginTable(u8"##uniform_table", 6, tableFlags)) {
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0); ImGui::Text(u8"");// "##item_index");
        ImGui::TableSetColumnIndex(1); ImGui::Text(u8"索引");
        ImGui::TableSetColumnIndex(2); ImGui::Text(u8"名字");
        ImGui::TableSetColumnIndex(3); ImGui::Text(u8"类型");
        ImGui::TableSetColumnIndex(4); ImGui::Text(u8"偏移");
        ImGui::TableSetColumnIndex(5); ImGui::Text(u8"大小");

        for (int i = 0; i < uniformSize; ++i) {
            GLint uniformID = uniforms[i];
            size = 0;
            glGetActiveUniformName(programID, uniformID, sizeof(buf), &size, buf);

            ImGui::TableNextRow();
            ImGui::TableSetColumnIndex(0); ImGui::Text(u8"%d", i);
            ImGui::TableSetColumnIndex(1); ImGui::Text(u8"%d", uniformID);
            ImGui::TableSetColumnIndex(2); ImGui::Text(buf);
            ImGui::TableSetColumnIndex(3); ImGui::Text(GLenum_to_string(types[i]));
            ImGui::TableSetColumnIndex(4); ImGui::Text(u8"%d", offsets[i]);
            ImGui::TableSetColumnIndex(5); ImGui::Text(u8"%d", sizes[i]);
        }

        ImGui::EndTable();
    }
    */

    // clang-format off

    if (ImGui::BeginTable(u8"##uniform_table", 5, tableFlags)) {
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0); ImGui::Text(u8"索引");
        ImGui::TableSetColumnIndex(1); ImGui::Text(u8"名字");
        ImGui::TableSetColumnIndex(2); ImGui::Text(u8"类型");
        ImGui::TableSetColumnIndex(3); ImGui::Text(u8"偏移");
        ImGui::TableSetColumnIndex(4); ImGui::Text(u8"数量");

        for (int i = 0; i < uniformSize; ++i) {
            GLint uniformID = uniforms[i];
            size = 0;
            glGetActiveUniformName(programID, uniformID, sizeof(buf), &size, buf);

            ImGui::TableNextRow();
            ImGui::TableSetColumnIndex(0); ImGui::Text(u8"%d", uniformID);
            ImGui::TableSetColumnIndex(1); ImGui::Text(u8"%s", buf);
            ImGui::TableSetColumnIndex(2); ImGui::Text(u8"%s", shader_value_type_to_string(types[i]));
            ImGui::TableSetColumnIndex(3); ImGui::Text(u8"%d", offsets[i]);
            ImGui::TableSetColumnIndex(4); ImGui::Text(u8"%d", sizes[i]);
        }

        ImGui::EndTable();
    }

    // clang-format on
}

const float ITEM_CY = 24.0f;
const float ADDR_CX = 80.0f;

void display_uniform(const char* typeName, const char* uniformName, GLenum type, int size, float cx)
{
    if (size <= 16) {
        ImGui::Button(imgui_format(u8"%s %s : %d", typeName, uniformName, size), ImVec2(size * cx, ITEM_CY));
    }
    else {
        for (int n = size; n > 0; n -= 16) {
            if (n < 16) {
                ImGui::Button(imgui_format(u8"##%s %s[%d]", typeName, uniformName, size - n), ImVec2(n * cx, ITEM_CY));
            }
            else {
                if (n == size) {
                    // ImGui::Button(imgui_format(u8"%s %s[%d]", typeName, uniformName, size - n), ImVec2(16 * cx, ITEM_CY));
                    ImGui::Button(imgui_format(u8"%s %s : %d", typeName, uniformName, size), ImVec2(16 * cx, ITEM_CY));
                }
                else {
                    ImGui::Button(imgui_format(u8"##%s %s[%d]", typeName, uniformName, size - n), ImVec2(16 * cx, ITEM_CY));
                }
            }
        }
    }
}

void nextLine(int& addr)
{
    ImGui::SetNextItemWidth(ADDR_CX);
    // ImGui::LabelText("##label", imgui_format("%d", addr));
    // ImGui::Selectable(imgui_format("%d", addr), false, 0, ImVec2(ADDR_CX, ITEM_CY));
    ImGui::Text("%08X", addr);
    ImGui::SameLine();
    addr += 16;
}

// 显示变量视图
void display_uniforms_view(
    GLuint programID,
    GLint uniformSize,
    std::vector<GLint> uniforms,
    std::vector<GLint> types,
    std::vector<GLint> offsets,
    std::vector<GLint> sizes
)
{
    char uniformName[256] = { 0 };
    GLsizei nameLength;
    GLsizei typeSize;
    GLsizei dataSize;

    int addr = 0;


    float cx = (ImGui::GetWindowWidth() - ADDR_CX) / 16.0f;
    float w, h;

    for (int i = 0; i < uniformSize; ++i) {
        GLint uniformID = uniforms[i];
        nameLength      = 0;
        glGetActiveUniformName(programID, uniformID, sizeof(uniformName), &nameLength, uniformName);

        // 如果偏移不是 16 的倍数，不换行
        if ((offsets[i] % 16) != 0) {
            ImGui::SameLine();
            // x += ImGui::GetStyle().ItemSpacing.x;
        }
        else {
            nextLine(addr);
        }

        // 数据长度
        typeSize = shader_sizeof(types[i]);
        dataSize = typeSize * sizes[i];

        // 数据类型
        const char* typeName = shader_value_type_to_string(types[i]);

        // 压入样式颜色
        push_color(types[i]);

        // 根据数据长度生成按钮
        if (sizes[i] == 1) { // 变量
            // w = typeSize * cx;

            if (dataSize <= 16) {
                ImGui::Button(imgui_format(u8"%s %s : %d", typeName, uniformName, dataSize), ImVec2(dataSize * cx, ITEM_CY));
            }
            else {
                for (int n = dataSize; n > 0; n -= 16) {
                    if (n < 16) {
                        nextLine(addr);
                        ImGui::Button(imgui_format(u8"##%s %s[%d]", typeName, uniformName, dataSize - n), ImVec2(n * cx, ITEM_CY));
                    }
                    else {
                        if (n == dataSize) {
                            // ImGui::Button(imgui_format(u8"%s %s[%d]", typeName, uniformName, size - n), ImVec2(16 * cx, ITEM_CY));
                            ImGui::Button(imgui_format(u8"%s %s : %d", typeName, uniformName, dataSize), ImVec2(16 * cx, ITEM_CY));
                        }
                        else {
                            nextLine(addr);
                            ImGui::Button(imgui_format(u8"##%s %s[%d]", typeName, uniformName, dataSize - n), ImVec2(16 * cx, ITEM_CY));
                        }
                    }
                }
            }
        }
        else { // 数组
            // "var[0]"
            uniformName[nameLength - 3] = '\0';
            //*
            nameLength = 0;
            for (int n = dataSize; n > 0; n -= 16) {
                if (n < 16) {
                    nextLine(addr);
                    ImGui::Button(imgui_format(u8"##%s %s[%d]", typeName, uniformName, n), ImVec2(n * cx, ITEM_CY));
                }
                else {
                    // ImGui::Button(imgui_format(u8"%s %s[%d]", typeName, uniformName, n), ImVec2(16 * cx, ITEM_CY));
                    // nameLength += 16 / shader_sizeof(types[i]);
                    if (n == dataSize) {
                        ImGui::Button(imgui_format(u8"%s %s[%d]", typeName, uniformName, sizes[i]), ImVec2(16 * cx, ITEM_CY));
                    }
                    else {
                        nextLine(addr);
                        ImGui::Button(imgui_format(u8"##%s %s[%d]", typeName, uniformName, n), ImVec2(16 * cx, ITEM_CY));
                    }
                }
            }
            //*/
            /*
            int offset = 0;
            int startX;
            for (int varID = 0; varID < sizes[i]; ++varID) {
                startX = offset % 16;
                if ((startX) != 0) {
                    ImGui::SameLine();
                }

                if (startX + typeSize <= 16) {
                    ImGui::Button(imgui_format(u8"%s %s[%d] : %d", typeName, uniformName, varID, typeSize), ImVec2(typeSize * cx, ITEM_CY));
                }
                else {
                    for (int n = typeSize; n > 0; n -= 16) {
                        if (n < 16) {
                            ImGui::Button(imgui_format(u8"##%s %s[%d]", typeName, uniformName, typeSize - n), ImVec2(n * cx, ITEM_CY));
                        }
                        else {
                            if (n == typeSize) {
                                // ImGui::Button(imgui_format(u8"%s %s[%d]", typeName, uniformName, size - n), ImVec2(16 * cx, ITEM_CY));
                                ImGui::Button(imgui_format(u8"%s %s[%d] : %d", typeName, uniformName, varID, typeSize), ImVec2(16 * cx, ITEM_CY));
                            }
                            else {
                                ImGui::Button(imgui_format(u8"##%s %s[%d]", typeName, uniformName, typeSize - n), ImVec2(16 * cx, ITEM_CY));
                            }
                        }
                    }
                }
                offset += typeSize;
            }
            */
        }

        // 弹出样式颜色
        pop_color(types[i]);
    }
}

// treeview
/*
for (int blockID = 0; blockID < blockSize; ++blockID) {
    if (ImGui::TreeNode(imgui_format(u8"%d##block_node", blockID))) {
        glGetActiveUniformBlockiv(programID, blockID, GL_UNIFORM_BLOCK_BINDING, &param);
        ImGui::LabelText(u8"binding", "%d", param);

        glGetActiveUniformBlockiv(programID, blockID, GL_UNIFORM_BLOCK_DATA_SIZE, &param);
        ImGui::LabelText(u8"data size", "%d", param);

        //glGetActiveUniformBlockiv(programID, blockID, GL_UNIFORM_BLOCK_NAME_LENGTH, &param);
        //ImGui::LabelText(u8"name length", "%d", param);

        glGetActiveUniformBlockName(programID, blockID, param, &size, buf);
        ImGui::LabelText(u8"name", buf);

        //{{ block uniforms begin
        glGetActiveUniformBlockiv(programID, blockID, GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS, &uniformSize);
        ImGui::LabelText(u8"uniforms", "%d", uniformSize);

        uniforms.resize(uniformSize);
        glGetActiveUniformBlockiv(programID, blockID, GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES, uniforms.data());
        //ImGui::LabelText(u8"indices", "%d", param);

        types.resize(uniformSize);
        glGetActiveUniformsiv(programID, uniformSize, (GLuint*) uniforms.data(), GL_UNIFORM_TYPE, types.data());

        offsets.resize(uniformSize);
        glGetActiveUniformsiv(programID, uniformSize, (GLuint*) uniforms.data(), GL_UNIFORM_OFFSET, offsets.data());

        sizes.resize(uniformSize);
        glGetActiveUniformsiv(programID, uniformSize, (GLuint*) uniforms.data(), GL_UNIFORM_SIZE, sizes.data());
        //}} block uniforms end

        if (ImGui::TreeNode(u8"uniforms:")) {
            for (int i = 0; i < uniformSize; ++i) {
                GLint uniformID = uniforms[i];
                size = 0;
                glGetActiveUniformName(programID, uniformID, sizeof(buf), &size, buf);
                ImGui::Text(u8"[%d] %d = %20s  type = %20s size = %8d offset = %8d\n",
                    i, uniformID, buf, GLenum_to_string(types[i]), sizes[i], offsets[i]);
            }
            ImGui::TreePop();
        }
        ImGui::TreePop();

        ImGui::TreePop();
    }
}
*/

// table view
void uniform_buffer_table_view(int programID)
{
    GLsizei size;
    char buf[256] = { 0 };

    GLint param;

    // blocks
    GLint uniformSize;
    std::vector<GLint> uniforms;
    std::vector<GLint> types;
    std::vector<GLint> offsets;
    std::vector<GLint> sizes;

    GLint blockSize;
    glGetProgramiv(programID, GL_ACTIVE_UNIFORM_BLOCKS, &blockSize);

    /*
    if (ImGui::BeginListBox(u8"##block_list", ImVec2(100.0f, -1.0f))) {
        for (int blockID = 0; blockID < blockSize; ++blockID) {
            glGetActiveUniformBlockiv(programID, blockID, GL_UNIFORM_BLOCK_NAME_LENGTH, &param);
            glGetActiveUniformBlockName(programID, blockID, param, &size, buf);
            ImGui::Text(buf);
        }

        ImGui::EndListBox();
    }
    ImGui::SameLine();
    */

    if (ImGui::BeginTabBar(u8"##table_bar")) {

        for (int blockID = 0; blockID < blockSize; ++blockID) {
            glGetActiveUniformBlockiv(programID, blockID, GL_UNIFORM_BLOCK_NAME_LENGTH, &param);
            glGetActiveUniformBlockName(programID, blockID, param, &size, buf);

            // block uniforms begin {
            glGetActiveUniformBlockiv(programID, blockID, GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS, &uniformSize);

            uniforms.resize(uniformSize);
            glGetActiveUniformBlockiv(programID, blockID, GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES, uniforms.data());
            // ImGui::LabelText(u8"indices", "%d", param);
            std::sort(uniforms.begin(), uniforms.end()); // 获取的顺序是乱的

            types.resize(uniformSize);
            glGetActiveUniformsiv(programID, uniformSize, (GLuint*) uniforms.data(), GL_UNIFORM_TYPE, types.data());

            sizes.resize(uniformSize);
            glGetActiveUniformsiv(programID, uniformSize, (GLuint*) uniforms.data(), GL_UNIFORM_SIZE, sizes.data());

            offsets.resize(uniformSize);
            glGetActiveUniformsiv(programID, uniformSize, (GLuint*) uniforms.data(), GL_UNIFORM_OFFSET, offsets.data());
            //} block uniforms end

            if (ImGui::BeginTabItem(u8"视图##table_item")) {
                // 显示数据大小
                glGetActiveUniformBlockiv(programID, blockID, GL_UNIFORM_BLOCK_DATA_SIZE, &param);
                ImGui::Text(u8"data size = %d", param - 16);

                display_uniforms_view(programID, uniformSize - 1, uniforms, types, offsets, sizes);

                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem(u8"表格##table_item")) {
                display_uniforms_table(programID, uniformSize - 1, uniforms, types, offsets, sizes);

                ImGui::EndTabItem();
            }
        }

        ImGui::EndTabBar();
    }
}

// sub window view
void uniform_buffer_view(int programID)
{
    UniformBlockDesc desc;
    GetUniformBlockDesc(programID, 0, desc);

    // ImVec2(-0.5f, -1.0f)
    ImVec2 childSize = ImVec2(ImGui::GetContentRegionAvail().x * 0.5f - ImGui::GetStyle().ItemSpacing.x * 0.65f, 0.0f);

    // 图形视图
    if (ImGui::BeginChild(u8"child_view", childSize, 0)) {
        // ImGui::Text(u8"图形视图：");

        // 显示数据大小
        ImGui::Text(u8"图形视图：(数据大小 = %d)", desc.dataSize - 16);

        if (ImGui::BeginChild(u8"child_view", childSize, ImGuiChildFlags_Border)) {
            display_uniforms_view(programID, desc.uniformSize - 1, desc.uniforms, desc.types, desc.offsets, desc.sizes);
        }
        ImGui::EndChild();
    }
    ImGui::EndChild();

    // 表格视图
    ImGui::SameLine();
    if (ImGui::BeginChild(u8"child_tableview", childSize, 0)) {
        ImGui::Text(u8"表格视图：");
        display_uniforms_table(programID, desc.uniformSize - 1, desc.uniforms, desc.types, desc.offsets, desc.sizes);
    }
    ImGui::EndChild();
}

// 代码
static char buf[4096] = // { 0 };
    {
        "vec3 position;\n"
        "vec3 normal;\n"
        "vec2 texCoord;\n"
        "\n"
        "mat4 projection;\n"
        //"mat4 view;\n"
        //"mat4 model;\n"
        "mat3 normalMatrix;\n"
        "\n"
        "vec2 v2[2];\n"
        "vec3 v3[2];\n"
        "vec4 v4[2];\n"
        "mat3 m3[2];\n"
        "mat4 m4[2];\n"
    };

// 错误信息
static char compileInfo[4096] = { 0 };

static void ubo_editor()
{
    // 代码头
    const char* codeHead =
        "#version 330 core\n"
        "layout (std140) uniform elements {";

    // 中间是编辑的代码

    // 代码结尾
    const char* codeTail =
        "    vec4 __built_in_vec4;"
        "};"
        "void main() {"
        "    gl_Position = __built_in_vec4;"
        "}";

    // 编辑框
    ImGui::Text(u8"结构体: (std140)");
    ImGui::InputTextMultiline(u8"GLSL##glsl.source", buf, IM_ARRAYSIZE(buf), ImVec2(-1.0f, 200.0f));

    std::string code = codeHead;
    code.append(buf);
    code.append(codeTail);

    GLuint shader = shader = glCreateShader(GL_VERTEX_SHADER);
    const GLchar* source   = code.c_str();
    GLsizei size           = code.size();
    glShaderSource(shader, 1, &source, &size);
    glCompileShader(shader);

    GLint status;

    // 判断 shader 是否编译成功
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status != GL_TRUE) {
        GLint infoLen = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
        if (infoLen > 1) {
            infoLen = glm::min(infoLen, (GLint) sizeof(compileInfo));
            glGetShaderInfoLog(shader, infoLen, nullptr, compileInfo);
        }

        // 显示错误信息
        ImGui::InputTextMultiline(
            "##comiple_error_text", compileInfo, sizeof(compileInfo),
            ImVec2(-1.0f, -1.0f), ImGuiInputTextFlags_ReadOnly
        );

        glDeleteShader(shader);
    }
    else {
        // 编译一个 Program，并显示信息
        GLuint program = glCreateProgram();

        glAttachShader(program, shader);
        glLinkProgram(program);
        glDetachShader(program, shader);
        glDeleteShader(shader);

        glGetProgramiv(program, GL_LINK_STATUS, &status);
        if (status != GL_TRUE) {
            glDeleteProgram(program);
            program = GL_NONE;
        }

        if (program) {
            // 显示 ubo
            // if (ImGui::CollapsingHeader(u8"Uniform")) {
            uniform_buffer_view(program);
            //}

            glDeleteProgram(program);
        }
    }
}

/* 显示 ubo 编辑器
 */
void display_ubo_editor(bool& visible)
{
    int flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
    ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));
    ImGui::SetNextWindowSize(ImVec2(screen.x, screen.y));
    if (ImGui::Begin(u8"Uniform Buffer 编辑器", &visible, flags)) {
        ubo_editor();
    }
    ImGui::End();
}
