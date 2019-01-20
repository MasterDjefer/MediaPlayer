#include "year.h"

Year::Year(const QString year) : MusicInfo(year)
{
}

QString Year::toString() const
{
    return QString("Year: " + mData);
}
