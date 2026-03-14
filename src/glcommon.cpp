#include "glcommon.h"

//------------------------------------------------------------------------------

#define CGL_LOG_ERROR std::printf

//------------------------------------------------------------------------------

// 返回 shader 类型名字
const char* shader_type_to_string(GLenum type)
{
    switch (type) {
    case GL_FRAGMENT_SHADER:
        return "fragment shader";
    case GL_VERTEX_SHADER:
        return "vertex shader";
    case GL_GEOMETRY_SHADER:
        return "geometry shader";
    case GL_TESS_EVALUATION_SHADER:
        return "tess evaluation shader";
    case GL_TESS_CONTROL_SHADER:
        return "tess control shader";
    case GL_COMPUTE_SHADER:
        return "compute shader";
    default:
        return "unknown shader";
    }
}

// create a shader object, and compile the shader.
GLuint compile_shader(GLenum type, const char* source, GLint size)
{
    GLuint shader;

    // check source
    if (source == nullptr || size == 0) {
        return GL_NONE;
    }

    // create the shader object
    shader = glCreateShader(type);

    if (!shader) {
        CGL_LOG_ERROR("glshader: create shader failed.\n");
        return GL_NONE;
    }

    // load the shader source
    glShaderSource(shader, 1, &source, &size);

    // Compile the shader
    glCompileShader(shader);

    // check the compile status
    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status != GL_TRUE) {
        GLint infoLen = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
        if (infoLen > 1) {
            char* infoLog = (char*) malloc(sizeof(char) * infoLen);
            glGetShaderInfoLog(shader, infoLen, nullptr, infoLog);
            CGL_LOG_ERROR("%s %s", shader_type_to_string(type), infoLog);
            free(infoLog);
        }

        glDeleteShader(shader);
        return GL_NONE;
    }

    return shader;
}

//------------------------------------------------------------------------------

// 返回 shader 数据类型的大小
int glshader_sizeof(GLenum e)
{
    switch (e) {
    // base
    case GL_BOOL:               return 4;
    case GL_INT:                return 4;
    case GL_UNSIGNED_INT:       return 4;
    case GL_FLOAT:              return 4;

    // vec<N, bool>
    case GL_BOOL_VEC2:          return 8;
    case GL_BOOL_VEC3:          return 12;
    case GL_BOOL_VEC4:          return 16;

    // vec<N, int>
    case GL_INT_VEC2:           return 8;
    case GL_INT_VEC3:           return 12;
    case GL_INT_VEC4:           return 16;

    // vec<N, unsigned int>
    case GL_UNSIGNED_INT_VEC2:  return 8;
    case GL_UNSIGNED_INT_VEC3:  return 12;
    case GL_UNSIGNED_INT_VEC4:  return 16;

    // vec<N, float>
    case GL_FLOAT_VEC2:         return 8;
    case GL_FLOAT_VEC3:         return 12;
    case GL_FLOAT_VEC4:         return 16;

    // mat<M, N, float>
    case GL_FLOAT_MAT2:         return 16;
    case GL_FLOAT_MAT2x3:       return 24;
    case GL_FLOAT_MAT2x4:       return 32;
    case GL_FLOAT_MAT3:         return 36;
    case GL_FLOAT_MAT3x2:       return 24;
    case GL_FLOAT_MAT3x4:       return 48;
    case GL_FLOAT_MAT4:         return 64;
    case GL_FLOAT_MAT4x2:       return 32;
    case GL_FLOAT_MAT4x3:       return 48;

#if defined(GL_DOUBLE)
    // double
    case GL_DOUBLE:             return 8;
    case GL_DOUBLE_VEC2:        return 16;
    case GL_DOUBLE_VEC3:        return 24;
    case GL_DOUBLE_VEC4:        return 32;
    case GL_DOUBLE_MAT2:        return 32;
    case GL_DOUBLE_MAT2x3:      return 48;
    case GL_DOUBLE_MAT2x4:      return 64;
    case GL_DOUBLE_MAT3:        return 72;
    case GL_DOUBLE_MAT3x2:      return 48;
    case GL_DOUBLE_MAT3x4:      return 96;
    case GL_DOUBLE_MAT4:        return 128;
    case GL_DOUBLE_MAT4x2:      return 64;
    case GL_DOUBLE_MAT4x3:      return 96;
#endif

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
        return 8;
    default:
        break;
    }
    return 0;
}

// 返回 shader 数据类型的名字
const char* glshader_value_type_to_string(GLenum e)
{
    switch (e) {
    // base
    case GL_BOOL:               return "bool";
    case GL_INT:                return "int";
    case GL_UNSIGNED_INT:       return "uint";
    case GL_FLOAT:              return "float";

    // vec<N, bool>
    case GL_BOOL_VEC2:          return "bvec2";
    case GL_BOOL_VEC3:          return "bvec3";
    case GL_BOOL_VEC4:          return "bvec4";

    // vec<N, int>
    case GL_INT_VEC2:           return "ivec2";
    case GL_INT_VEC3:           return "ivec3";
    case GL_INT_VEC4:           return "ivec4";

    // vec<N, unsigned int>
    case GL_UNSIGNED_INT_VEC2:  return "uvec2";
    case GL_UNSIGNED_INT_VEC3:  return "uvec3";
    case GL_UNSIGNED_INT_VEC4:  return "uvec4";

    // vec<N, float>
    case GL_FLOAT_VEC2:         return "vec2";
    case GL_FLOAT_VEC3:         return "vec3";
    case GL_FLOAT_VEC4:         return "vec4";

    // mat<M, N, float>
    case GL_FLOAT_MAT2:         return "mat2";
    case GL_FLOAT_MAT2x3:       return "mat2x3";
    case GL_FLOAT_MAT2x4:       return "mat2x4";
    case GL_FLOAT_MAT3:         return "mat3";
    case GL_FLOAT_MAT3x2:       return "mat3x2";
    case GL_FLOAT_MAT3x4:       return "mat3x4";
    case GL_FLOAT_MAT4:         return "mat4";
    case GL_FLOAT_MAT4x2:       return "mat4x2";
    case GL_FLOAT_MAT4x3:       return "mat4x3";

#if defined(GL_DOUBLE)
    // double
    case GL_DOUBLE:             return "double";
    case GL_DOUBLE_VEC2:        return "dvec2";
    case GL_DOUBLE_VEC3:        return "dvec3";
    case GL_DOUBLE_VEC4:        return "dvec4";
    case GL_DOUBLE_MAT2:        return "dmat2";
    case GL_DOUBLE_MAT2x3:      return "dmat2x3";
    case GL_DOUBLE_MAT2x4:      return "dmat2x4";
    case GL_DOUBLE_MAT3:        return "dmat3";
    case GL_DOUBLE_MAT3x2:      return "dmat3x2";
    case GL_DOUBLE_MAT3x4:      return "dmat3x4";
    case GL_DOUBLE_MAT4:        return "dmat4";
    case GL_DOUBLE_MAT4x2:      return "dmat4x2";
    case GL_DOUBLE_MAT4x3:      return "dmat4x3";
#endif

    // samplers

#if defined(GL_SAMPLER_1D)
    case GL_SAMPLER_1D:                     return "sampler1D";
    case GL_SAMPLER_1D_SHADOW:              return "sampler1DShadow";
    case GL_SAMPLER_1D_ARRAY_SHADOW:        return "sampler1DArrayShadow";
#endif

    case GL_SAMPLER_2D:                     return "sampler2D";
    case GL_SAMPLER_2D_SHADOW:              return "sampler2DShadow";
    case GL_SAMPLER_2D_ARRAY_SHADOW:        return "sampler2DArrayShadow";
    case GL_SAMPLER_2D_MULTISAMPLE:         return "sampler2DMS";
    case GL_SAMPLER_2D_MULTISAMPLE_ARRAY:   return "sampler2DMSArray";
#if defined(GL_SAMPLER_2D_RECT)
    case GL_SAMPLER_2D_RECT:                return "sampler2DRect";
    case GL_SAMPLER_2D_RECT_SHADOW:         return "sampler2DRectShadow";
#endif
    case GL_SAMPLER_3D:                     return "sampler3D";
    case GL_SAMPLER_BUFFER:                 return "samplerBuffer";
    case GL_SAMPLER_CUBE:                   return "samplerCube";
    case GL_SAMPLER_CUBE_SHADOW:            return "samplerCubeShadow";
    case GL_SAMPLER_CUBE_MAP_ARRAY:         return "samplerCubeArray";
    case GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW:  return "samplerCubeArrayShadow";

    // int sampler
#if defined(GL_INT_SAMPLER_1D)
    case GL_INT_SAMPLER_1D:                     return "isampler1D";
    case GL_INT_SAMPLER_1D_ARRAY:               return "isampler1DArray";
#endif
    case GL_INT_SAMPLER_2D:                     return "isampler2D";
    case GL_INT_SAMPLER_2D_ARRAY:               return "isampler2DArray";
    case GL_INT_SAMPLER_2D_MULTISAMPLE:         return "isampler2DMS";
    case GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY:   return "isampler2DMSArray";
#if defined(GL_INT_SAMPLER_2D_RECT)
    case GL_INT_SAMPLER_2D_RECT:                return "isampler2DRect";
#endif  
    case GL_INT_SAMPLER_3D:                     return "isampler3D";
    case GL_INT_SAMPLER_BUFFER:                 return "isamplerBuffer";
    case GL_INT_SAMPLER_CUBE:                   return "isamplerCube";
    case GL_INT_SAMPLER_CUBE_MAP_ARRAY:         return "isamplerCubeArray";

    // unsigned int sampler
#if defined(GL_UNSIGNED_INT_SAMPLER_1D)
    case GL_UNSIGNED_INT_SAMPLER_1D:                    return "usampler1D";
    case GL_UNSIGNED_INT_SAMPLER_1D_ARRAY:              return "usampler1DArray";
#endif
    case GL_UNSIGNED_INT_SAMPLER_2D:                    return "usampler2D";
    case GL_UNSIGNED_INT_SAMPLER_2D_ARRAY:              return "usampler2DArray";
    case GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE:        return "usampler2DMS";
    case GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY:  return "usampler2DMSArray";
#if defined(GL_UNSIGNED_INT_SAMPLER_2D_RECT)
    case GL_UNSIGNED_INT_SAMPLER_2D_RECT:               return "usampler2DRect";
#endif
    case GL_UNSIGNED_INT_SAMPLER_3D:                    return "usampler3D";
    case GL_UNSIGNED_INT_SAMPLER_BUFFER:                return "usamplerBuffer";
    case GL_UNSIGNED_INT_SAMPLER_CUBE:                  return "usamplerCube";
    case GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY:        return "usamplerCubeArray";

    //
    // images
    //

#if defined(GL_IMAGE_1D)
    case GL_IMAGE_1D:               return "image1D";
    case GL_IMAGE_1D_ARRAY:         return "image1DArray";
#endif
    case GL_IMAGE_2D:               return "image2D";
    case GL_IMAGE_2D_ARRAY:         return "image2DArray";
#if defined(GL_IMAGE_2D_RECT)
    case GL_IMAGE_2D_RECT:          return "image2DRect";
    case GL_IMAGE_2D_MULTISAMPLE:   return "image2DMS";
    case GL_IMAGE_2D_MULTISAMPLE_ARRAY:     return "image2DMSArray";
#endif
    case GL_IMAGE_3D:               return "image3D";
    case GL_IMAGE_BUFFER:           return "imageBuffer";
    case GL_IMAGE_CUBE:             return "imageCube";
    case GL_IMAGE_CUBE_MAP_ARRAY:   return "imageCubeArray";

    // int image
#if defined(GL_INT_IMAGE_1D)
    case GL_INT_IMAGE_1D:                   return "iimage1D";
    case GL_INT_IMAGE_1D_ARRAY:             return "iimage1DArray";
#endif
    case GL_INT_IMAGE_2D:                   return "iimage2D";
    case GL_INT_IMAGE_2D_ARRAY:             return "iimage2DArray";
#if defined(GL_INT_IMAGE_2D_RECT)
    case GL_INT_IMAGE_2D_RECT:              return "iimage2DRect";
    case GL_INT_IMAGE_2D_MULTISAMPLE:       return "iimage2DMS";
    case GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY: return "iimage2DMSArray";
#endif
    case GL_INT_IMAGE_3D:                   return "iimage3D";
    case GL_INT_IMAGE_BUFFER:               return "iimageBuffer";
    case GL_INT_IMAGE_CUBE:                 return "iimageCube";
    case GL_INT_IMAGE_CUBE_MAP_ARRAY:       return "iimageCubeArray";

    // unsigned int image
#if defined(GL_UNSIGNED_INT_IMAGE_1D)
    case GL_UNSIGNED_INT_IMAGE_1D:                      return "uimage1D";
    case GL_UNSIGNED_INT_IMAGE_1D_ARRAY:                return "uimage1DArray";
#endif
    case GL_UNSIGNED_INT_IMAGE_2D:                      return "uimage2D";
    case GL_UNSIGNED_INT_IMAGE_2D_ARRAY:                return "uimage2DArray";
#if defined(GL_UNSIGNED_INT_IMAGE_2D_RECT)
    case GL_UNSIGNED_INT_IMAGE_2D_RECT:                 return "uimage2DRect";
    case GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE:          return "uimage2DMS";
    case GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY:    return "uimage2DMSArray";
#endif
    case GL_UNSIGNED_INT_IMAGE_3D:                      return "uimage3D";
    case GL_UNSIGNED_INT_IMAGE_BUFFER:                  return "uimageBuffer";
    case GL_UNSIGNED_INT_IMAGE_CUBE:                    return "uimage2DMS";
    case GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY:          return "uimage2DMSArray";
    default:
        break;
    }

    return "unknown";
}

// clang-format on

// opengl enum
struct OPENGL_ENUMERATE
{
    GLenum value;
    const char* name;

    bool is_null() const
    {
        return name == nullptr;
    }
};

#define OPENGL_ENUMERATE_ITEM(a) \
    { \
        a, #a \
    }

// shader variable types
static const OPENGL_ENUMERATE OPENGL_SHADER_VARIABLE_TYPES[] = {
    // base
    OPENGL_ENUMERATE_ITEM(GL_BOOL),
    OPENGL_ENUMERATE_ITEM(GL_INT),
    OPENGL_ENUMERATE_ITEM(GL_UNSIGNED_INT),
    OPENGL_ENUMERATE_ITEM(GL_FLOAT),

    // vec<N, bool>
    OPENGL_ENUMERATE_ITEM(GL_BOOL_VEC2),
    OPENGL_ENUMERATE_ITEM(GL_BOOL_VEC3),
    OPENGL_ENUMERATE_ITEM(GL_BOOL_VEC4),

    // vec<N, int>
    OPENGL_ENUMERATE_ITEM(GL_INT_VEC2),
    OPENGL_ENUMERATE_ITEM(GL_INT_VEC3),
    OPENGL_ENUMERATE_ITEM(GL_INT_VEC4),

    // vec<N, unsigned int>
    OPENGL_ENUMERATE_ITEM(GL_UNSIGNED_INT_VEC2),
    OPENGL_ENUMERATE_ITEM(GL_UNSIGNED_INT_VEC3),
    OPENGL_ENUMERATE_ITEM(GL_UNSIGNED_INT_VEC4),

    // vec<N, float>
    OPENGL_ENUMERATE_ITEM(GL_FLOAT_VEC2),
    OPENGL_ENUMERATE_ITEM(GL_FLOAT_VEC3),
    OPENGL_ENUMERATE_ITEM(GL_FLOAT_VEC4),

    // mat<M, N, float>
    OPENGL_ENUMERATE_ITEM(GL_FLOAT_MAT2),
    OPENGL_ENUMERATE_ITEM(GL_FLOAT_MAT2x3),
    OPENGL_ENUMERATE_ITEM(GL_FLOAT_MAT2x4),
    OPENGL_ENUMERATE_ITEM(GL_FLOAT_MAT3),
    OPENGL_ENUMERATE_ITEM(GL_FLOAT_MAT3x2),
    OPENGL_ENUMERATE_ITEM(GL_FLOAT_MAT3x4),
    OPENGL_ENUMERATE_ITEM(GL_FLOAT_MAT4),
    OPENGL_ENUMERATE_ITEM(GL_FLOAT_MAT4x2),
    OPENGL_ENUMERATE_ITEM(GL_FLOAT_MAT4x3),

#if defined(GL_DOUBLE)
    // double
    OPENGL_ENUMERATE_ITEM(GL_DOUBLE),
    OPENGL_ENUMERATE_ITEM(GL_DOUBLE_MAT2),
    OPENGL_ENUMERATE_ITEM(GL_DOUBLE_MAT3),
    OPENGL_ENUMERATE_ITEM(GL_DOUBLE_MAT4),
    OPENGL_ENUMERATE_ITEM(GL_DOUBLE_MAT2x3),
    OPENGL_ENUMERATE_ITEM(GL_DOUBLE_MAT2x4),
    OPENGL_ENUMERATE_ITEM(GL_DOUBLE_MAT3x2),
    OPENGL_ENUMERATE_ITEM(GL_DOUBLE_MAT3x4),
    OPENGL_ENUMERATE_ITEM(GL_DOUBLE_MAT4x2),
    OPENGL_ENUMERATE_ITEM(GL_DOUBLE_MAT4x3),
    OPENGL_ENUMERATE_ITEM(GL_DOUBLE_VEC2),
    OPENGL_ENUMERATE_ITEM(GL_DOUBLE_VEC3),
    OPENGL_ENUMERATE_ITEM(GL_DOUBLE_VEC4),
#endif

// samplers

#if defined(GL_SAMPLER_1D)
    OPENGL_ENUMERATE_ITEM(GL_SAMPLER_1D),
    OPENGL_ENUMERATE_ITEM(GL_SAMPLER_1D_SHADOW),
    OPENGL_ENUMERATE_ITEM(GL_SAMPLER_1D_ARRAY_SHADOW),
#endif

    OPENGL_ENUMERATE_ITEM(GL_SAMPLER_2D),
    OPENGL_ENUMERATE_ITEM(GL_SAMPLER_2D_SHADOW),
    OPENGL_ENUMERATE_ITEM(GL_SAMPLER_2D_ARRAY_SHADOW),
    OPENGL_ENUMERATE_ITEM(GL_SAMPLER_2D_MULTISAMPLE),
    OPENGL_ENUMERATE_ITEM(GL_SAMPLER_2D_MULTISAMPLE_ARRAY),
#if defined(GL_SAMPLER_2D_RECT)
    OPENGL_ENUMERATE_ITEM(GL_SAMPLER_2D_RECT),
    OPENGL_ENUMERATE_ITEM(GL_SAMPLER_2D_RECT_SHADOW),
#endif
    OPENGL_ENUMERATE_ITEM(GL_SAMPLER_3D),
    OPENGL_ENUMERATE_ITEM(GL_SAMPLER_BUFFER),
    OPENGL_ENUMERATE_ITEM(GL_SAMPLER_CUBE),
    OPENGL_ENUMERATE_ITEM(GL_SAMPLER_CUBE_SHADOW),
    OPENGL_ENUMERATE_ITEM(GL_SAMPLER_CUBE_MAP_ARRAY),
    OPENGL_ENUMERATE_ITEM(GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW),

#if defined(GL_INT_SAMPLER_1D)
    OPENGL_ENUMERATE_ITEM(GL_INT_SAMPLER_1D),
    OPENGL_ENUMERATE_ITEM(GL_INT_SAMPLER_1D_ARRAY),
#endif
    OPENGL_ENUMERATE_ITEM(GL_INT_SAMPLER_2D),
    OPENGL_ENUMERATE_ITEM(GL_INT_SAMPLER_2D_ARRAY),
    OPENGL_ENUMERATE_ITEM(GL_INT_SAMPLER_2D_MULTISAMPLE),
    OPENGL_ENUMERATE_ITEM(GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY),
#if defined(GL_INT_SAMPLER_2D_RECT)
    OPENGL_ENUMERATE_ITEM(GL_INT_SAMPLER_2D_RECT),
#endif
    OPENGL_ENUMERATE_ITEM(GL_INT_SAMPLER_3D),
    OPENGL_ENUMERATE_ITEM(GL_INT_SAMPLER_BUFFER),
    OPENGL_ENUMERATE_ITEM(GL_INT_SAMPLER_CUBE),
    OPENGL_ENUMERATE_ITEM(GL_INT_SAMPLER_CUBE_MAP_ARRAY),

#if defined(GL_UNSIGNED_INT_SAMPLER_1D)
    OPENGL_ENUMERATE_ITEM(GL_UNSIGNED_INT_SAMPLER_1D),
    OPENGL_ENUMERATE_ITEM(GL_UNSIGNED_INT_SAMPLER_1D_ARRAY),
#endif
    OPENGL_ENUMERATE_ITEM(GL_UNSIGNED_INT_SAMPLER_2D),
    OPENGL_ENUMERATE_ITEM(GL_UNSIGNED_INT_SAMPLER_2D_ARRAY),
    OPENGL_ENUMERATE_ITEM(GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE),
    OPENGL_ENUMERATE_ITEM(GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY),
#if defined(GL_UNSIGNED_INT_SAMPLER_2D_RECT)
    OPENGL_ENUMERATE_ITEM(GL_UNSIGNED_INT_SAMPLER_2D_RECT),
#endif
    OPENGL_ENUMERATE_ITEM(GL_UNSIGNED_INT_SAMPLER_3D),
    OPENGL_ENUMERATE_ITEM(GL_UNSIGNED_INT_SAMPLER_BUFFER),
    OPENGL_ENUMERATE_ITEM(GL_UNSIGNED_INT_SAMPLER_CUBE),
    OPENGL_ENUMERATE_ITEM(GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY),

// images

#if defined(GL_IMAGE_1D)
    OPENGL_ENUMERATE_ITEM(GL_IMAGE_1D),
    OPENGL_ENUMERATE_ITEM(GL_IMAGE_1D_ARRAY),
#endif
    OPENGL_ENUMERATE_ITEM(GL_IMAGE_2D),
    OPENGL_ENUMERATE_ITEM(GL_IMAGE_2D_ARRAY),
#if defined(GL_IMAGE_2D_RECT)
    OPENGL_ENUMERATE_ITEM(GL_IMAGE_2D_RECT),
    OPENGL_ENUMERATE_ITEM(GL_IMAGE_2D_MULTISAMPLE),
    OPENGL_ENUMERATE_ITEM(GL_IMAGE_2D_MULTISAMPLE_ARRAY),
#endif
    OPENGL_ENUMERATE_ITEM(GL_IMAGE_3D),
    OPENGL_ENUMERATE_ITEM(GL_IMAGE_BUFFER),
    OPENGL_ENUMERATE_ITEM(GL_IMAGE_CUBE),
    OPENGL_ENUMERATE_ITEM(GL_IMAGE_CUBE_MAP_ARRAY),

#if defined(GL_INT_IMAGE_1D)
    OPENGL_ENUMERATE_ITEM(GL_INT_IMAGE_1D),
    OPENGL_ENUMERATE_ITEM(GL_INT_IMAGE_1D_ARRAY),
#endif
    OPENGL_ENUMERATE_ITEM(GL_INT_IMAGE_2D),
    OPENGL_ENUMERATE_ITEM(GL_INT_IMAGE_2D_ARRAY),
#if defined(GL_INT_IMAGE_2D_RECT)
    OPENGL_ENUMERATE_ITEM(GL_INT_IMAGE_2D_RECT),
    OPENGL_ENUMERATE_ITEM(GL_INT_IMAGE_2D_MULTISAMPLE),
    OPENGL_ENUMERATE_ITEM(GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY),
#endif
    OPENGL_ENUMERATE_ITEM(GL_INT_IMAGE_3D),
    OPENGL_ENUMERATE_ITEM(GL_INT_IMAGE_BUFFER),
    OPENGL_ENUMERATE_ITEM(GL_INT_IMAGE_CUBE),
    OPENGL_ENUMERATE_ITEM(GL_INT_IMAGE_CUBE_MAP_ARRAY),

#if defined(GL_UNSIGNED_INT_IMAGE_1D)
    OPENGL_ENUMERATE_ITEM(GL_UNSIGNED_INT_IMAGE_1D),
    OPENGL_ENUMERATE_ITEM(GL_UNSIGNED_INT_IMAGE_1D_ARRAY),
#endif
    OPENGL_ENUMERATE_ITEM(GL_UNSIGNED_INT_IMAGE_2D),
    OPENGL_ENUMERATE_ITEM(GL_UNSIGNED_INT_IMAGE_2D_ARRAY),
#if defined(GL_UNSIGNED_INT_IMAGE_2D_RECT)
    OPENGL_ENUMERATE_ITEM(GL_UNSIGNED_INT_IMAGE_2D_RECT),
    OPENGL_ENUMERATE_ITEM(GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE),
    OPENGL_ENUMERATE_ITEM(GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY),
#endif
    OPENGL_ENUMERATE_ITEM(GL_UNSIGNED_INT_IMAGE_3D),
    OPENGL_ENUMERATE_ITEM(GL_UNSIGNED_INT_IMAGE_BUFFER),
    OPENGL_ENUMERATE_ITEM(GL_UNSIGNED_INT_IMAGE_CUBE),
    OPENGL_ENUMERATE_ITEM(GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY),

    { GL_NONE, nullptr },
};

//------------------------------------------------------------------------------
// UBO
//------------------------------------------------------------------------------

// 获取 UBO 信息描述
int GetUniformBlockDesc(GLuint programID, GLuint blockID, UniformBlockDesc& desc)
{
    GLint param;
    GLsizei size;

    desc.id = blockID;

    glGetActiveUniformBlockiv(programID, blockID, GL_UNIFORM_BLOCK_NAME_LENGTH, &param);
    glGetActiveUniformBlockName(programID, blockID, param, &size, desc.name);

    glGetActiveUniformBlockiv(programID, blockID, GL_UNIFORM_BLOCK_DATA_SIZE, &desc.dataSize);

    glGetActiveUniformBlockiv(programID, blockID, GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS, &desc.uniformSize);

    desc.uniforms.resize(desc.uniformSize);
    glGetActiveUniformBlockiv(programID, blockID, GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES, desc.uniforms.data());
    std::sort(desc.uniforms.begin(), desc.uniforms.end()); // 获取的顺序是乱的

    desc.types.resize(desc.uniformSize);
    glGetActiveUniformsiv(programID, desc.uniformSize, (GLuint*) desc.uniforms.data(), GL_UNIFORM_TYPE, desc.types.data());

    desc.sizes.resize(desc.uniformSize);
    glGetActiveUniformsiv(programID, desc.uniformSize, (GLuint*) desc.uniforms.data(), GL_UNIFORM_SIZE, desc.sizes.data());

    desc.offsets.resize(desc.uniformSize);
    glGetActiveUniformsiv(programID, desc.uniformSize, (GLuint*) desc.uniforms.data(), GL_UNIFORM_OFFSET, desc.offsets.data());

    return 0;
}
