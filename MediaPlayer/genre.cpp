#include "genre.h"

Genre::Genre(const QString genre) : MusicInfo(genre)
{
}

QString Genre::toString() const
{
    return QString("Genre: " + mData);
}
