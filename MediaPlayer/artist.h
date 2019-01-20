#ifndef ARTIST_H
#define ARTIST_H
#include "musicinfo.h"

class Artist : public MusicInfo
{
public:
    Artist(const QString name);
    QString toString() const;
};

#endif // ARTIST_H
