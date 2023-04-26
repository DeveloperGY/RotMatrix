#include "rotmatrix.h"

rm_vec4f rm_applyMatrix4f(rm_vec4f v, rm_mat4f m)
{
    rm_vec4f result = rm_genVec4f(0, 0, 0, 0);

    for (int i=0; i<4; i++)
    {
        result.v[i] = v.v[0] * m.m[i*4] + v.v[1] * m.m[i*4 + 1] + v.v[2] * m.m[i*4 + 2] + v.v[3] * m.m[i*4 + 3];
    }

    return result;
}

rm_mat4f rm_multiplyMatrix4f(rm_mat4f l, rm_mat4f r)
{
    rm_mat4f result = rm_genZero4f();

    for (int row=0; row<4; row++)
    {
        for (int col=0; col<4; col++)
        {
            for(int i=0; i<4; i++)
            {
                result.m[row*4 + col] += l.m[row * 4 + i] * r.m[i * 4 + col];
            }
        }
    }

    return result;
}

rm_mat4f rm_genRotationX4f(float degrees)
{
    float c = cos(degrees * (ROTMATRIX_PI / 180.0f));
    float s = sin(degrees * (ROTMATRIX_PI / 180.0f));

    rm_mat4f result = {{
        1,  0,  0,  0,
        0,  c, -s,  0,
        0,  s,  c,  0,
        0,  0,  0,  1
    }};

    return result;
}

rm_mat4f rm_genRotationY4f(float degrees)
{
    float c = cos(degrees * (ROTMATRIX_PI / 180.0f));
    float s = sin(degrees * (ROTMATRIX_PI / 180.0f));

    rm_mat4f result = {{
         c,  0,  s,  0,
         0,  1,  0,  0,
        -s,  0,  c,  0,
         0,  0,  0,  1
    }};

    return result;
}

rm_mat4f rm_genRotationZ4f(float degrees)
{
    float c = cos(degrees * (ROTMATRIX_PI / 180.0f));
    float s = sin(degrees * (ROTMATRIX_PI / 180.0f));

    rm_mat4f result = {{
        c, -s,  0,  0,
        s,  c,  0,  0,
        0,  0,  1,  0,
        0,  0,  0,  1
    }};

    return result;
}

rm_mat4f rm_genTranslation4f(float x, float y, float z)
{
    rm_mat4f result = {{
        1, 0, 0, x,
        0, 1, 0, y,
        0, 0, 1, z,
        0, 0, 0, 1
    }};

    return result;
}

rm_mat4f rm_genScale4f(float x, float y, float z)
{
    rm_mat4f result = {{
        x, 0, 0, 0,
        0, y, 0, 0,
        0, 0, z, 0,
        0, 0, 0, 1
    }};

    return result;
}

rm_mat4f rm_genIdentity4f()
{
    rm_mat4f result = {{
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    }};
    return result;
}

rm_mat4f rm_genZero4f()
{
    rm_mat4f result = {{
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0
    }};

    return result;
}

rm_vec4f rm_genVec4f(float x, float y, float z, float w)
{
    rm_vec4f result = {{x, y, z, w}};

    return result;
}

rm_mat4f rm_transpose4f(rm_mat4f m)
{
    rm_mat4f result = rm_genZero4f();

    for (int row=0; row<4; row++)
    {
        for (int col=0; col<4; col++)
        {
            result.m[row * 4 + col] = m.m[col * 4 + row];
        }
    }

    return result;
}

void rm_retrieveOpenGLVec3f(float *openGLVec3f, rm_vec4f v)
{
    openGLVec3f[0] = v.v[0];
    openGLVec3f[1] = v.v[1];
    openGLVec3f[2] = v.v[2];

    return;
}

float rm_dotProduct(rm_vec4f l, rm_vec4f r)
{
    float result = 0;

    result += l.v[0] * r.v[0];
    result += l.v[1] * r.v[1];
    result += l.v[2] * r.v[2];

    return result;
}

rm_vec4f rm_crossProduct(rm_vec4f l, rm_vec4f r, int isPosition)
{
    // xyzzy

    rm_vec4f result = rm_genVec4f(0, 0, 0, isPosition);

    result.v[0] = l.v[1] * r.v[2] - l.v[2] * r.v[1];
    result.v[1] = l.v[2] * r.v[0] - l.v[0] * r.v[2];
    result.v[2] = l.v[0] * r.v[1] - l.v[1] * r.v[3];

    return result;
}