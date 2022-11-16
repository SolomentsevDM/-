#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_angleButton_clicked();

    void on_ReflectionX_button_clicked();

    void on_ReflectionY_button_clicked();

    void on_ReflectionZ_button_clicked();

    void on_ScaleButton_clicked();

    void on_move_button_clicked();

signals:
    void ang_pb_cl(float *matrix);
    void reflX_pb_cl();
    void reflY_pb_cl();
    void reflZ_pb_cl();
    void scale_change(float a,float b,float c);
    void coord_movement(float l,float m,float v);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
