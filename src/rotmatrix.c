#include "rotmatrix.h"

void rm_applyMatrix4f(rm_vec4f *result, rm_vec4f *v, rm_mat4f *m)
{
    // local result, used so that if the user passes the
    // same pointer for both vec parameters there isn't any bugs
    rm_vec4f l_result = {0, 0, 0, 0};

    for (int i=0; i<4; i++)
    {
        l_result[i] = (*v)[0] * (*m)[i*4] + (*v)[1] * (*m)[i*4 + 1] + (*v)[2] * (*m)[i*4 + 2] + (*v)[3] * (*m)[i*4 + 3];
    }

    for (int i=0; i<4; i++)
    {
        (*result)[i] = l_result[i];
    }

    return;
}

void rm_multiplyMatrix4f(rm_mat4f *result, rm_mat4f *l, rm_mat4f *r)
{
    // local result, used so that if the user passes the
    // same pointer for the result pointer as one of the other pointers there isn't any bugs
    rm_mat4f l_result = {
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0
    };

    for (int row=0; row<4; row++)
    {
        for (int col=0; col<4; col++)
        {
            for(int i=0; i<4; i++)
            {
                l_result[row*4 + col] += (*l)[row * 4 + i] * (*r)[i * 4 + col];
            }
        }
    }

    for (int i=0; i<16; i++)
    {
        (*result)[i] = l_result[i];
    }

    return;
}

void rm_genRotationX4f(rm_mat4f *result, float degrees)
{
    float c = cos(degrees * (ROTMATRIX_PI / 180.0f));
    float s = sin(degrees * (ROTMATRIX_PI / 180.0f));

    rm_mat4f l_result = {
        1,  0,  0,  0,
        0,  c, -s,  0,
        0,  s,  c,  0,
        0,  0,  0,  1
    };

    for (int i=0; i<16; i++)
    {
        (*result)[i] = l_result[i];
    }

    return;
}

void rm_genRotationY4f(rm_mat4f *result, float degrees)
{
    float c = cos(degrees * (ROTMATRIX_PI / 180.0f));
    float s = sin(degrees * (ROTMATRIX_PI / 180.0f));

    rm_mat4f l_result = {
         c,  0,  s,  0,
         0,  1,  0,  0,
        -s,  0,  c,  0,
         0,  0,  0,  1
    };

    for (int i=0; i<16; i++)
    {
        (*result)[i] = l_result[i];
    }

    return;
}

void rm_genRotationZ4f(rm_mat4f *result, float degrees)
{
    float c = cos(degrees * (ROTMATRIX_PI / 180.0f));
    float s = sin(degrees * (ROTMATRIX_PI / 180.0f));

    rm_mat4f l_result = {
        c, -s,  0,  0,
        s,  c,  0,  0,
        0,  0,  1,  0,
        0,  0,  0,  1
    };

    for (int i=0; i<16; i++)
    {
        (*result)[i] = l_result[i];
    }

    return;
}

void rm_transpose4f(rm_mat4f *result, rm_mat4f *m)
{
    rm_mat4f l_result;

    for (int row=0; row<4; row++)
    {
        for (int col=0; col<4; col++)
        {
            l_result[row * 4 + col] = (*m)[col * 4 + row];
        }
    }

    for (int i=0; i<16; i++)
    {
        (*result)[i] = l_result[i];
    }
}

void rm_genIdentity4f(rm_mat4f *result)
{
    for (int r=0; r<4; r++)
    {
        for(int c=0; c<4; c++)
        {
            (*result)[r*4 + c] = (float)(r == c);
        }
    }
}

void rm_toGLVec(rm_glVec *glvec, rm_vec4f *v)
{
    (*glvec)[0] = (*v)[0];
    (*glvec)[1] = (*v)[1];
    (*glvec)[2] = (*v)[2];
    return;
}

void rm_toGLMat(rm_glMat *glmat, rm_mat4f *m)
{
    rm_transpose4f(glmat, m);
    return;
}