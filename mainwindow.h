#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;

 //   int currTime = 0;
    stopwatch *myWatch;
    float myTime = 0;
    QString myText = "";
    unsigned short lapCounter = 0;
//private slots:

//void on_pushButton_clicked();
signals:
void handle_Tim();

private slots:
void on_BtnStartStop_clicked();
void drawTime();
void addText();

};
#endif // MAINWINDOW_H
