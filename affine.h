#ifndef AFFINE_H
#define AFFINE_H


class affine
{
public:
    static void rotationX(float alfa,float *matrix);
    static void rotationY(float alfa,float *matrix);
    static void rotationZ(float alfa,float *matrix);
    static void dilatation(float a,float b, float c,float *matrix);
    static void reflectionXY(float *matrix);
    static void reflectionYZ(float *matrix);
    static void reflectionZX(float *matrix);
    static void translation(float l,float m,float v,float *matrix);
    static void *matrixMultiply(float *mat1,float *mat2);
private:
    affine(){};
};

#endif // AFFINE_H
