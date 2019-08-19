#include <QTime>
#include <QTimer>

#include "DigitalClock.h"

DigitalClock::DigitalClock(QWidget *parent) : QLCDNumber (parent)
{
    setSegmentStyle(Flat);
    setDigitCount(8);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &DigitalClock::showTime);
    timer->start(1000);

    showTime();

    setWindowTitle("Digital Clock");
    resize(150, 60);
}

void DigitalClock::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm:ss");


    display(text);
}
