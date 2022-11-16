#include "affine.h"
#include<cmath>
#include <string.h>
void affine::rotationX(float alfa,float *matrix)
{
    alfa=alfa*M_PI/180;
    float sinA=sin(alfa);
    float cosA=cos(alfa);
    float matrix2[16]={1,0,0,0,
                             0,cosA,-sinA,0,
                             0,sinA,cosA,0,
                             0,0,0,1};
    memcpy(matrix,matrix2,16*sizeof(float));
}

void affine::rotationY(float alfa,float *matrix)
{
    alfa=alfa*M_PI/180;
    float sinA=sin(alfa);
    float cosA=cos(alfa);
    float matrix2[16]={cosA,0,sinA,0,
                             0,1,0,0,
                             -sinA,0,cosA,0,
                             0,0,0,1};
    memcpy(matrix,matrix2,16*sizeof(float));
}

void affine::rotationZ(float alfa,float *matrix)
{
    alfa=alfa*M_PI/180;
    float sinA=sin(alfa);
    float cosA=cos(alfa);
    float matrix2[16]={cosA,-sinA,0,0,
                       sinA,cosA,0,0,
                       0,0,1,0,
                       0,0,0,1};
    memcpy(matrix,matrix2,16*sizeof(float));
}

void affine::dilatation(float a, float b, float c,float *matrix)
{
    float matrix2[16]={a,0,0,0,
                       0,b,0,0,
                       0,0,c,0,
                       0,0,0,1};
    memcpy(matrix,matrix2,16*sizeof(float));
}

void affine::reflectionXY(float *matrix)
{
    float matrix2[16]={1,0,0,0,
                       0,1,0,0,
                       0,0,-1,0,
                       0,0,0,1};
    memcpy(matrix,matrix2,16*sizeof(float));
}

void affine::reflectionYZ(float *matrix)
{
    float matrix2[16]={-1,0,0,0,
                            0,1,0,0,
                            0,0,1,0,
                            0,0,0,1};
    memcpy(matrix,matrix2,16*sizeof(float));
}

void affine::reflectionZX(float *matrix)
{
    float matrix2[16]={1,0,0,0,
                            0,-1,0,0,
                            0,0,1,0,
                            0,0,0,1};
    memcpy(matrix,matrix2,16*sizeof(float));
}

void affine::translation(float l, float m, float v,float *matrix)
{
    float matrix2[16]={1,0,0,0,
                       0,1,0,0,
                       0,0,1,0,
                       l,m,v,1};
    memcpy(matrix,matrix2,16*sizeof(float));
}

void *affine::matrixMultiply(float *mat1, float *mat2)
{
    float res[16]={0};
    for (int i = 0; i < 4; ++i)
    {
            for (int j = 0; j < 4; ++j)
            {
                for (int k = 0; k < 4; ++k)
                {
                    res[i * 4 + j] += mat1[i * 4 + k] * mat2[k * 4 + j];
                }
            }
    }
    memcpy(mat1,res,16*sizeof(float));
}
