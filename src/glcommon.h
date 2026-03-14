#pragma once

#include "../pch.h"


// create a shader object, and compile the shader.
GLuint compile_shader(GLenum type, const char *source, GLint size);

// 返回 shader 数据类型的大小
int shader_sizeof(GLenum e);

// 返回 shader 数据类型的名字
const char* shader_value_type_to_string(GLenum e);

// UBO 的信息描述
struct UniformBlockDesc
{
    GLuint id;         // block index
    GLchar name[64];   // 名字
    GLint dataSize;    // 数据大小
    GLint uniformSize; // block 大小

    std::vector<GLint> uniforms;
    std::vector<GLint> types;
    std::vector<GLint> offsets;
    std::vector<GLint> sizes;
};

// 获取 UBO 信息描述
int GetUniformBlockDesc(GLuint programID, GLuint blockID, UniformBlockDesc& desc);
