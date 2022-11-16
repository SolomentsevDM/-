#include "Opengl_Widget.h"
#include <GL/gl.h>
#include<QOpenGLContext>
#include<QOpenGLFunctions_1_5>
#include<affine.h>
void Opengl_Widget::initializeGL()
{
    glClearColor(0,0,0,0);
    glClearDepth(1);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}

void Opengl_Widget::resizeGL(int nWidth, int nHeight)
{
    //glViewport(0, 0, nWidth, nHeight);
    if(nWidth>nHeight)
        glViewport((nWidth-nHeight)/2,0,nHeight,nHeight);
    else
        glViewport(0,(nHeight-nWidth)/2,nWidth,nWidth);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-3,3,-3,3,-4,4);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
float Opengl_Widget::mat[16]={ 1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
void Opengl_Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);

    //glLoadIdentity();
    //glTranslatef(0,0,0);

    //glBegin(GL_TRIANGLES);
   //glColor3f(0.5,1.0,0.0);
    //glVertex3f(-1,-1,1);
    //glVertex3f(1,-1,-1);
    //glVertex3f(-1,1,1);
    //glEnd();

    //mat=
    glLoadMatrixf(mat);
    //glRotatef(30,1,0.2,0);
    glBegin(GL_LINES);
    //glTranslatef(0,0,2);
    glColor3f(0.5,1.0,0.0);

    glVertex3f(0,0,0);
    glVertex3f(0,0,1);

    glVertex3f(0,0,1);
    glVertex3f(0,1,1);

    glVertex3f(0,1,1);
    glVertex3f(0,1,0);

    glVertex3f(0,1,0);
    glVertex3f(0,0,0);

    glVertex3f(0,0,0);
    glVertex3f(1,0,0);

    glVertex3f(1,0,0);
    glVertex3f(1,0,1);

    glVertex3f(1,0,1);
    glVertex3f(0,0,1);

    glVertex3f(1,0,1);
    glVertex3f(1,1,1);

    glVertex3f(1,1,1);
    glVertex3f(0,1,1);

    glVertex3f(1,1,1);
    glVertex3f(1,1,0);

    glVertex3f(1,1,0);
    glVertex3f(0,1,0);

    glVertex3f(1,1,0);
    glVertex3f(1,0,0);
    glEnd();

}

void Opengl_Widget::angleButton_clicked(float *matrix)
{
    affine::matrixMultiply(mat,matrix);
    glLoadMatrixf(mat);
    QOpenGLWidget::update();
}

void Opengl_Widget::reflectionXBtn_clicked()
{
    float *matrix=new float[16];
    affine::reflectionXY(matrix);
    affine::matrixMultiply(mat,matrix);
    glLoadMatrixf(mat);
    QOpenGLWidget::update();
}

void Opengl_Widget::reflectionYBtn_clicked()
{
    float *matrix=new float[16];
    affine::reflectionYZ(matrix);
    affine::matrixMultiply(mat,matrix);
    glLoadMatrixf(mat);
    QOpenGLWidget::update();
}

void Opengl_Widget::reflectionZBtn_clicked()
{
    float *matrix=new float[16];
    affine::reflectionZX(matrix);
    affine::matrixMultiply(mat,matrix);
    glLoadMatrixf(mat);
    QOpenGLWidget::update();
}

void Opengl_Widget::ScaleChange(float a, float b, float c)
{
    float *matrix=new float[16];
    affine::dilatation(a,b,c,matrix);
    affine::matrixMultiply(mat,matrix);
    glLoadMatrixf(mat);
    QOpenGLWidget::update();
}

void Opengl_Widget::coodr_move(float l, float m, float v)
{
    float *matrix=new float[16];
    affine::translation(l,m,v,matrix);
    affine::matrixMultiply(mat,matrix);
    glLoadMatrixf(mat);
    QOpenGLWidget::update();
}
