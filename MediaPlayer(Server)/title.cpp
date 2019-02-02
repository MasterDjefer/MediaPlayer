#include "title.h"

Title::Title(const QString title) : MusicInfo(title)
{
}

QString Title::toString() const
{
    return QString("Title: " + mData);
}
