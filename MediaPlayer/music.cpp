#include "music.h"

Music::Music()
{
    allocData();
}

Music::~Music()
{
    delete mArtist;
    delete mTitle;
    delete mGenre;
    delete mYear;
}

MediaData::MediaType Music::type() const
{
    return MediaData::music;
}

void Music::init(const QString artist, const QString title, const QString genre, const QString year)
{
    mArtist->setData(artist);
    mTitle->setData(title);
    mGenre->setData(genre);
    mYear->setData(year);
}

Artist *Music::artist()
{
    return mArtist;
}

Title *Music::title()
{
    return mTitle;
}

Genre *Music::genre()
{
    return mGenre;
}

Year *Music::year()
{
    return mYear;
}

void Music::allocData()
{
    mArtist = new Artist("");
    mTitle = new Title("");
    mGenre = new Genre("");
    mYear = new Year("");
}
