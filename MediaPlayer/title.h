#ifndef TITLE_H
#define TITLE_H
#include "musicinfo.h"

class Title : public MusicInfo
{
public:
    Title(const QString title);
    QString toString() const;
};

#endif // TITLE_H
