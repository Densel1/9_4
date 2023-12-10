#include "stopwatch.h"
#include "mainwindow.h"
#include <QDebug>

stopwatch::stopwatch(QObject *parent)
    : QObject{parent},
      myTimer(new QTimer)
{
    connect(myTimer,&QTimer::timeout,this,&stopwatch::tic);
}


void stopwatch::start(bool chk){
    qDebug() << "start" << chk;
    if(chk){
//        myTime = 0;
        myTimer->start(100);
    }
    else{
        myTimer->stop();
    }
}

QString stopwatch::lapString()
{
    lapTime = myTime - prevLapTime;
    prevLapTime = myTime;
    QString s = "";
    QTextStream qs(&s);
    qs << "Круг " << lapCounter << ", время:" << lapTime << " сек" << Qt::endl;
    lapCounter++;
    return s;
}

void stopwatch::tic()
{
    myTime+=0.1;
    emit update();
}

void stopwatch::reset(){
    myTime = 0;
    lapCounter = 0;
    qDebug() << "reset";
}
