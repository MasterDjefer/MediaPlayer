#include "musicfile.h"

MusicFile::MusicFile()
{
    mMusic = new Music;
    QObject::connect(this, &MusicFile::metaDataAvailableChanged,
                     this, &MusicFile::metaDataAvailable);
}

MusicFile::~MusicFile()
{
    delete mMusic;
}


Music *MusicFile::music()
{
    return mMusic;
}

void MusicFile::metaDataAvailable(bool)
{
    mMusic->init(this->metaData(QMediaMetaData::Author).toString(),
                 this->metaData(QMediaMetaData::Title).toString(),
                 this->metaData(QMediaMetaData::Genre).toString(),
                 this->metaData(QMediaMetaData::Year).toString());
    if (MediaFile::type(this->currentMedia().canonicalUrl().toString()) == MediaFile::musicFile)
        emit metaDataChanged(mMusic);
    else
        emit metaDataChanged(nullptr);
}

void MusicFile::setMediaData(QListWidgetItem *item)
{
    this->setMediaFile(item->text());
    emit mediaSetted();
}



