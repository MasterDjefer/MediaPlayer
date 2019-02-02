#ifndef TIME_H
#define TIME_H
#include <QString>
#include <cmath>

class Time
{
    bool timeSet;
    enum
    {
        secInMin = 60,
        secInHour = 3600
    };
private:
    int mHours;
    int mMinutes;
    int mSeconds;
private:
    void setZero();
public:
    Time();
    void setTime(int miliSeconds);
    bool isTimeSet() const;
    QString toString();
};

#endif // TIME_H
