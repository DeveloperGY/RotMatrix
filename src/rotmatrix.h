#ifndef ROTMATRIX_H
#define ROTMATRIX_H


#include <math.h>

#ifndef ROTMATRIX_PI
    #define ROTMATRIX_PI 3.1415926535897932384626433
#endif


#ifdef __cplusplus
extern "C" {
#endif


typedef float rm_vec4f[4];

// This is row major whereas opengl matrices are column major
typedef float rm_mat4f[16];

typedef float rm_glVec[3];
typedef float rm_glMat[16];

/**
 * @brief Applies a matrix to a vector and puts ther result in the specified vector
 * 
 * @param result A pointer to the vector to store the result in
 * @param v The vector to apply the matrix to
 * @param m The matrix to apply
*/
void rm_applyMatrix4f(rm_vec4f *result, rm_vec4f *v, rm_mat4f *m);

/**
 * @brief Multiplies two matrices together and stores the result in the specified matrix
 * 
 * @param result A pointer to the matrix to store the result in
 * @param l The matrix to put on the left of the multiplication
 * @param r The matrix to put on the right of the multiplication
*/
void rm_multiplyMatrix4f(rm_mat4f *result, rm_mat4f *l, rm_mat4f *r);

/**
 * @brief Generates a rotation matrix for the x-axis for the specified degree measure
 * 
 * @param result The matrix to store the resulting rotation matrix in
 * @param degrees The amount of degrees to set as the rotation
*/
void rm_genRotationX4f(rm_mat4f *result, float degrees);

/**
 * @brief Generates a rotation matrix for the y-axis for the specified degree measure
 * 
 * @param result The matrix to store the resulting rotation matrix in
 * @param degrees The amount of degrees to set as the rotation
*/
void rm_genRotationY4f(rm_mat4f *result, float degrees);

/**
 * @brief Generates a rotation matrix for the z-axis for the specified degree measure
 * 
 * @param result The matrix to store the resulting rotation matrix in
 * @param degrees The amount of degrees to set as the rotation
*/
void rm_genRotationZ4f(rm_mat4f *result, float degrees);

/**
 * @brief Transposes a matrix and stroes the result in the specifed matrix
 * 
 * @param result The matrix to store the result in
 * @param m The matrix to transpose
*/
void rm_transpose4f(rm_mat4f *result, rm_mat4f *m);

/**
 * @brief Generates an identity matrix and stores it in the specified matrix
 * 
 * @param result The matrix to store the identity matrix in
*/
void rm_genIdentity4f(rm_mat4f *result);

/**
 * @brief Turns an rm_vec4f to an opengl compatable vector
 * 
 * @param glvec The resulting opengl compatable vector
 * @param v The vector to openglify
*/
void rm_toGLVec(rm_glVec *glvec, rm_vec4f *v);

/**
 * @brief Turns an rm_mat4f to an opengl compatable matrix
 * 
 * @param glmat The resulting opengl compatable matrix
 * @param m The matrix to openglify
*/
void rm_toGLMat(rm_glMat *glmat,  rm_mat4f *m);

#ifdef __cplusplus
}
#endif


#endif