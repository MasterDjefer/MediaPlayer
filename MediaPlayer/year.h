#ifndef YEAR_H
#define YEAR_H
#include "musicinfo.h"

class Year : public MusicInfo
{
public:
    Year(const QString year);
    QString toString() const;
};

#endif // YEAR_H
