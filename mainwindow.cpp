#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QRegularExpression>
#include<QRegularExpressionValidator>
#include<Opengl_Widget.h>
#include<affine.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QRegularExpression reg("-{0,1}[0-9]{1,3}");
    QRegularExpressionValidator *validator=new QRegularExpressionValidator(reg,this);
    ui->setupUi(this);
    ui->In_angleX->setValidator(validator);
    ui->In_angleY->setValidator(validator);
    ui->In_angleZ->setValidator(validator);
    QRegularExpression reg_scale("[0-9]{1,2}\\.{0,1}[0-9]{1,2}");
    QRegularExpressionValidator *validator_scale=new QRegularExpressionValidator(reg_scale,this);
    ui->ScaleValX->setValidator(validator_scale);
    ui->ScaleValY->setValidator(validator_scale);
    ui->ScaleValZ->setValidator(validator_scale);
    QRegularExpression reg_tr("-{0,1}[0-2]{1,2}\\.[0-9]{1,3}");
    QRegularExpressionValidator *validator_tr=new QRegularExpressionValidator(reg_tr,this);
    ui->transpX->setValidator(validator_tr);
    ui->transpY->setValidator(validator_tr);
    ui->transpZ->setValidator(validator_tr);
    connect(this,&MainWindow::ang_pb_cl,ui->opengl_widget,&Opengl_Widget::angleButton_clicked);
    connect(this,&MainWindow::reflX_pb_cl,ui->opengl_widget,&Opengl_Widget::reflectionXBtn_clicked);
    connect(this,&MainWindow::reflY_pb_cl,ui->opengl_widget,&Opengl_Widget::reflectionYBtn_clicked);
    connect(this,&MainWindow::reflZ_pb_cl,ui->opengl_widget,&Opengl_Widget::reflectionZBtn_clicked);
    connect(this,&MainWindow::scale_change,ui->opengl_widget,&Opengl_Widget::ScaleChange);
    connect(this,&MainWindow::coord_movement,ui->opengl_widget,&Opengl_Widget::coodr_move);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_angleButton_clicked()
{
    float *matrix=new float[16];
    float *matrix2=new float[16];
    affine::rotationY(ui->In_angleY->text().toFloat(),matrix);
    affine::rotationZ(ui->In_angleZ->text().toFloat(),matrix2);
    affine::matrixMultiply(matrix,matrix2);
    affine::rotationX(ui->In_angleX->text().toFloat(),matrix2);
    affine::matrixMultiply(matrix2,matrix);
    emit ang_pb_cl(matrix2);
}


void MainWindow::on_ReflectionX_button_clicked()
{
    emit reflX_pb_cl();
}


void MainWindow::on_ReflectionY_button_clicked()
{
    emit reflY_pb_cl();
}


void MainWindow::on_ReflectionZ_button_clicked()
{
    emit reflZ_pb_cl();
}


void MainWindow::on_ScaleButton_clicked()
{
    emit scale_change(ui->ScaleValX->text().toFloat(),ui->ScaleValY->text().toFloat(),ui->ScaleValZ->text().toFloat());
}


void MainWindow::on_move_button_clicked()
{
    emit coord_movement(ui->transpX->text().toFloat(),ui->transpY->text().toFloat(),ui->transpZ->text().toFloat());
}

