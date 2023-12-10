#include "mainwindow.h"
#include "./ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , myWatch(new stopwatch)
{
    ui->setupUi(this);
    connect(myWatch, &stopwatch::isStart, myWatch, &stopwatch::start);
    connect(myWatch, &stopwatch::update, this, &MainWindow::drawTime);
    connect(ui->btnClear, &QPushButton::clicked, myWatch, &stopwatch::reset);
    connect(ui->btnClear, &QPushButton::clicked, this, [&](){ui->TimeIndication->setText("0");});
    connect(ui->btnCircle, &QPushButton::clicked, this, &MainWindow::addText);
        qDebug() << "Run";

        ui->TimeIndication->setText("0");
};



MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_BtnStartStop_clicked()
{
    bool chkd = ui->BtnStartStop->isChecked();
     if(chkd)
     {
         ui->BtnStartStop->setText("Стоп");
         ui->btnCircle->setEnabled(true);
     }
     else{
         ui->BtnStartStop->setText("Старт");
         ui->btnCircle->setEnabled(false);
     }
     emit myWatch->isStart(chkd);
}


void MainWindow::drawTime()
{
        ui->TimeIndication->setText(QString::number(myWatch->getTime()));
}

void MainWindow::addText()
{
    ui->textBrowser->insertPlainText(myWatch->lapString());
}
