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
    connect(ui->btnClear, &QPushButton::clicked, this, [&](){myTime = 0;
               lapCounter = 0;
               ui->TimeIndication->setText(QString::number(myTime));});
    connect(ui->btnCircle, &QPushButton::clicked, this, addText);
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
        myTime+=0.1;
        ui->TimeIndication->setText(QString::number(myTime));
}

void MainWindow::addText()
{
    QString s = "";
    QTextStream qs(&s);
    qs << "Круг " << lapCounter++ << ", время:" << myTime << " сек" << Qt::endl;

    ui->textBrowser->insertPlainText(s);
}
