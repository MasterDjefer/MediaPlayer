#ifndef PLAYLISTSDATABASE_H
#define PLAYLISTSDATABASE_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QStringList>
#include <algorithm>
#include <QDebug>

#include "databasehelper.h"

class PlaylistsDatabase
{
private:
    QSqlDatabase mDatabase;

public:
    PlaylistsDatabase();
    QString getPlaylistId(QString playlistName);
    QString getPlaylistName(QString playlistId);

    void showData();
    void writeToDB(QMap<QString, QSet<QString> >* map);
    void readFromDB(QMap<QString, QSet<QString> >* map);
    void clearDB();
private:
    void writePlalistsToDB(QStringList list);
    void writeTracksToDB(QMap<QString, QSet<QString> >* map);
private:
    void createTables();
    void dropTables();

};

#endif // PLAYLISTSDATABASE_H
