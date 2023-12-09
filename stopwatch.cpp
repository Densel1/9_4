#include "stopwatch.h"
#include "mainwindow.h"
#include <QDebug>

stopwatch::stopwatch(QObject *parent)
    : QObject{parent},
      myTimer(new QTimer)
{
    connect(myTimer,&QTimer::timeout,this,&stopwatch::update);
}


void stopwatch::start(bool chk){
    //ui->btnStart;
    qDebug() << "start" << chk;
    if(chk){
        myTime = 0;
        myTimer->start(100);
    }
    else{
        myTimer->stop();
    }
}
void stopwatch::stop(){
    qDebug() << "stop";
}
void stopwatch::reset(){
    qDebug() << "reset";
}
/*
void stopwatch::update()
{
    myTime+=0.1;
}
*/
