#include "mediafile.h"

MediaFile::MediaFile()
{

}

void MediaFile::setMediaFile(const QString fileName)
{
    this->setMedia(QUrl::fromLocalFile(fileName));
}

MediaFile::FileType MediaFile::type(const QString type)
{
    return type.contains(".mp3") ? musicFile : videoFile;
}
