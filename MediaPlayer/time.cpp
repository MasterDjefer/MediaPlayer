#include "time.h"

Time::Time() : timeSet(false)
{

}

void Time::setTime(int miliSeconds)
{
    timeSet = true;
    setZero();
    int duration = ceil(miliSeconds / 1000.0);

    mHours = duration / secInHour;
    if (mHours != 0)
    {
        duration -= mHours * secInHour;
    }
    mMinutes = duration / secInMin;
    if (mMinutes != 0)
    {
        duration -= mMinutes * secInMin;
    }
    mSeconds = duration;
}

bool Time::isTimeSet() const
{
    return timeSet;
}

void Time::setZero()
{
    mHours = 0;
    mMinutes = 0;
    mSeconds = 0;
}


QString Time::toString()
{
    QString h = QString::number(mHours);
    QString m = QString::number(mMinutes);
    QString s = QString::number(mSeconds);
    QString data = (h.size() == 1 ? "0" + h : h) + ":" +
                   (m.size() == 1 ? "0" + m : m) + ":" +
                   (s.size() == 1 ? "0" + s : s);
    return data;
}
