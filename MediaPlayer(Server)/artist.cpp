#include "artist.h"

Artist::Artist(const QString name) : MusicInfo(name)
{
}

QString Artist::toString() const
{
    return QString("Artist: " + mData);
}
