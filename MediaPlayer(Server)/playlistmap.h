#ifndef PLAYLISTMAP_H
#define PLAYLISTMAP_H
#include <QMap>
#include <QVector>
#include <QSet>
#include <QStringList>
#include <algorithm>
#include <QDebug>

#include "playlistsdatabase.h"

class PlaylistMap
{
private:
    QMap<QString, QSet<QString> >* mMap;
    PlaylistsDatabase *mDataBase;

public:
    PlaylistMap();
    ~PlaylistMap();
    void addPlaylist(QString playlistName);
    void addTracks(QString playlistName, QStringList tracks);
    QStringList tracks(QString key);
    void removeList(QString key);
    void removeElement(QString key, QString value);
    void showMap();
    QMap<QString, QSet<QString> >* map();

    //QStringList playlistsFromDB();
};

#endif // PLAYLISTMAP_H
