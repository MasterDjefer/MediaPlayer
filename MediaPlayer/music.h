#ifndef MUSIC_H
#define MUSIC_H
#include "mediadata.h"
#include "artist.h"
#include "title.h"
#include "genre.h"
#include "year.h"

class Music : public MediaData
{
private:
    Artist *mArtist;
    Title* mTitle;
    Genre* mGenre;
    Year* mYear;

public:
    Music();
    virtual ~Music();
    MediaType type() const;
    void init(const QString artist, const QString title, const QString genre, const QString year);
    Artist* artist();
    Title* title();
    Genre* genre();
    Year* year();
private:
    void allocData();
};

#endif // MUSIC_H
