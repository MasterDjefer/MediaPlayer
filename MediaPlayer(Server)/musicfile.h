#ifndef MUSICFILE_H
#define MUSICFILE_H
#include <QMediaMetaData>
#include <QListWidgetItem>
#include "music.h"
#include "mediafile.h"

class MusicFile : public MediaFile
{
    Q_OBJECT
private:
    Music* mMusic;

public:
    MusicFile();
    ~MusicFile();
    Music* music();
public slots:
    void metaDataAvailable(bool);
    void setMediaData(QListWidgetItem* item);
signals:
    void metaDataChanged(MediaData* music);
    void mediaSetted();
};

#endif // MUSICFILE_H
