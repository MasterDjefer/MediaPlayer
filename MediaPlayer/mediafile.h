#ifndef MEDIAFILE_H
#define MEDIAFILE_H
#include <QMediaPlayer>

class MediaFile : public QMediaPlayer
{
public:
    enum FileType
    {
        musicFile,
        videoFile
    };
    MediaFile();
    void setMediaFile(const QString fileName);
    static FileType type(const QString type);
};

#endif // MEDIAFILE_H
