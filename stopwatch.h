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
public:
    explicit stopwatch(QObject *parent = nullptr);

public slots:
    void start(bool chk = false);
    void stop();
    void reset();

signals:
    void isStart(bool start = false);
    void update();
    void onReset();

};

#endif // STOPWATCH_H
