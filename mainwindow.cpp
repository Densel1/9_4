#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
 //   myTimer = new QTimer;
 //   myTimer->setInterval(100);
   // connect(myTimer,SIGNAL(timeout()),this, SLOT(&MainWindow::handle_Tim()));
 //  qDebug() << "Connecting";
};


void MainWindow::handle_Tim()
{
    ui->lineEdit->setText(QString::number(currTime));
 //   currTime++;
//    qDebug() << "text";
}


MainWindow::~MainWindow()
{
    delete ui;
}



//void MainWindow::on_pushButton_clicked()
//{
//   if(ui->pushButton->text() == "Старт")
//   {
//       ui->pushButton->setText("Стоп");
//  //     myTimer->stop();
//   }
//   else
//   {
//       ui->pushButton->setText("Старт");
//   //    myTimer->start();
//   }
//}


