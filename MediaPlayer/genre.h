#ifndef GENRE_H
#define GENRE_H
#include "musicinfo.h"


class Genre : public MusicInfo
{
public:
    Genre(const QString genre);
    QString toString() const;
};

#endif // GENRE_H
