#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>

class stopwatch : public QObject
{
    Q_OBJECT
private:
    QTimer *myTimer;
    float myTime = 0;
    float prevLapTime = 0;
    float lapTime;
    unsigned short lapCounter = 0;

public:
    explicit stopwatch(QObject *parent = nullptr);
    float getTime()
    {
        return myTime;
    }
    QString lapString();

public slots:

    void start(bool chk = false);
    void reset();
   void tic();

signals:
    void isStart(bool start = false);
    void update();
    void onReset();

};

#endif // STOPWATCH_H
