#ifndef OPENGL_WIDGET_H
#define OPENGL_WIDGET_H

#include<QWidget>
#include<QOpenGLWidget>

class Opengl_Widget : public QOpenGLWidget
{
public:
    Opengl_Widget(QWidget *parent):QOpenGLWidget(parent){};
    static float mat[16];
protected:

    void initializeGL() override;
    void resizeGL(int nWidth, int nHeight)override;
    void paintGL()override;
public slots:
    void angleButton_clicked(float *matrix);
    void reflectionXBtn_clicked();
    void reflectionYBtn_clicked();
    void reflectionZBtn_clicked();
    void ScaleChange(float a,float b,float c);
    void coodr_move(float l,float m,float v);

};
#endif // OPENGL_WIDGET_H
