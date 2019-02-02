#include "playlistmap.h"

PlaylistMap::PlaylistMap()
{
    mMap = new QMap<QString, QSet<QString> >;
    mMap->clear();
    mDataBase = new PlaylistsDatabase;
    mDataBase->readFromDB(mMap);//problem here
    //this->showMap();
}

PlaylistMap::~PlaylistMap()
{
    mDataBase->clearDB();
    mDataBase->writeToDB(mMap);
    delete mMap;
    delete mDataBase;
}

void PlaylistMap::addPlaylist(QString playlistName)
{
    mMap->insert(playlistName, {});
}

void PlaylistMap::addTracks(QString playlistName, QStringList tracks)
{
    if (!mMap->contains(playlistName))
        mMap->insert(playlistName, {});
    for (int i = 0; i < tracks.size(); ++i)
    {
        mMap->find(playlistName)->insert(tracks.at(i));
    }
}

QStringList PlaylistMap::tracks(QString key)
{
    QStringList list(mMap->value(key).toList());
    return list;
}

void PlaylistMap::removeList(QString key)
{
    mMap->remove(key);
}

void PlaylistMap::removeElement(QString key, QString value)
{
    mMap->find(key)->remove(value);
}

void PlaylistMap::showMap()
{
    for (QMap<QString, QSet<QString> >::iterator it = mMap->begin(); it != mMap->end(); ++it)
    {
        qDebug() << it.key();
        for (QSet<QString>::iterator i = it.value().begin(); i != it.value().end(); ++i)
        {
            qDebug () << *i;
        }
    }
}

QMap<QString, QSet<QString> > *PlaylistMap::map()
{
    return mMap;
}
