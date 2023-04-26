#ifndef ROTMATRIX_H
#define ROTMATRIX_H


#include <math.h>

#ifndef ROTMATRIX_PI
    #define ROTMATRIX_PI 3.1415926535897932384626433
#endif


#ifdef __cplusplus
extern "C" {
#endif


// typedef float rm_vec4f[4];

typedef struct
{
    float v[4];
} rm_vec4f;

// This is row major whereas opengl matrices are column major
typedef struct
{
    float m[16];
} rm_mat4f;

/**
 * @brief Applies a matrix to a vector
 * 
 * @param v The vector to apply the matrix to
 * @param m The matrix to apply
 * 
 * @return The resulting vector
*/
rm_vec4f rm_applyMatrix4f(rm_vec4f v, rm_mat4f m);

/**
 * @brief Multiplies two matrices together
 * 
 * @param l The matrix to put on the left of the multiplication
 * @param r The matrix to put on the right of the multiplication
 * 
 * @return The resulting matrix
*/
rm_mat4f rm_multiplyMatrix4f(rm_mat4f l, rm_mat4f r);

/**
 * @brief Generates a rotation matrix for the x-axis for the specified degree measure
 * 
 * @param degrees The amount of degrees to set as the rotation
 * 
 * @return The rotation matrix of the specified axis and degree measure
*/
rm_mat4f rm_genRotationX4f(float degrees);

/**
 * @brief Generates a rotation matrix for the y-axis for the specified degree measure
 * 
 * @param degrees The amount of degrees to set as the rotation
 * 
 * @return The rotation matrix of the specified axis and degree measure
*/
rm_mat4f rm_genRotationY4f(float degrees);

/**
 * @brief Generates a rotation matrix for the z-axis for the specified degree measure
 * 
 * @param degrees The amount of degrees to set as the rotation
 * 
 * @return The rotation matrix of the specified axis and degree measure
*/
rm_mat4f rm_genRotationZ4f(float degrees);

/**
 * @brief Generates a translation matrix
 * 
 * @param x The amount to translate in the x axis
 * @param y The amount to translate in the y axis
 * @param z The amount to translate in the z axis
 * 
 * @return The resulting translation matrix
*/
rm_mat4f rm_genTranslation4f(float x, float y, float z);

/**
 * @brief Generates a scale matrix
 * 
 * @param x The amount to scale on the x axis
 * @param y The amount to scale on the y axis
 * @param z The amount to scale on the z axis
 * 
 * @return The resulting scale matrix
*/
rm_mat4f rm_genScale4f(float x, float y, float z);

/**
 * @brief Generates an identity matrix
 * 
 * @return The identity matrix
*/
rm_mat4f rm_genIdentity4f();

/**
 * @brief Generates a zero matrix
 * 
 * @return The zero matrix
*/
rm_mat4f rm_genZero4f();

/**
 * @brief Generates a vector
 * 
 * @param x The x component
 * @param y The y component
 * @param z The z component
 * @param w The w component, if its 1, its a point in 3d space, if its 0, its a direction in 3d space
 * 
 * @return The vector you so desire
*/
rm_vec4f rm_genVec4f(float x, float y, float z, float w);

/**
 * @brief Transposes a matrix and stroes the result in the specifed matrix
 * 
 * @param m The matrix to transpose
 * 
 * @return The transposed matrix
*/
rm_mat4f rm_transpose4f(rm_mat4f m);

/**
 * @brief Stores an opengl compatable version of a rotmatrix vector in the specified pointer
 * 
 * @param openGLVec3f a float pointer that has 3 floats of space allocated to it (or you risk memory corruption)
 * @param v the rotmatrix vector you want to convert
*/
void rm_retrieveOpenGLVec3f(float *openGLVec3f, rm_vec4f v);

/**
 * @brief Returns the dot product of 2 vectors (disregards the 4th, w component)
 * 
 * @param l The vector on the left
 * @param r The vector ont he right
 * 
 * @return The dot product of the two vectors
*/
float rm_dotProduct(rm_vec4f l, rm_vec4f r);

/**
 * @brief Returns the cross product of 2 vectors (disregards the 4th, w component)
 * 
 * @param l The vector on the left
 * @param r The vector ont he right
 * @param isPosition 0: Direction, 1: Position
 * 
 * @return The cross product of the two vectors
*/
rm_vec4f rm_crossProduct(rm_vec4f l, rm_vec4f r, int isPosition);

#ifdef __cplusplus
}
#endif


#endif