#include "playlistsdatabase.h"

PlaylistsDatabase::PlaylistsDatabase()
{
    mDatabase = QSqlDatabase::addDatabase(DatabaseHelper::sqlDriver);
    mDatabase.setDatabaseName(DatabaseHelper::dataBaseName);
    mDatabase.open();
    if (!mDatabase.isOpen())
    {
        qDebug() << "Error";
    }

    //dropTables();
    createTables();
}

void PlaylistsDatabase::createTables()
{
    QSqlQuery query;
    query.exec("create table if not exists " + DatabaseHelper::tablePlaylistsName +
               "(id integer primary key, name text);");
    query.exec("create table if not exists " + DatabaseHelper::tableTracksName +
               "(id integer primary key, name text, playlistId integer references " +
               DatabaseHelper::tablePlaylistsName + "(id));");
}

void PlaylistsDatabase::dropTables()
{
    QSqlQuery query;
    query.exec("drop table " + DatabaseHelper::tableTracksName);
    query.exec("drop table " + DatabaseHelper::tablePlaylistsName);
}

void PlaylistsDatabase::showData()
{
    QSqlQuery query;
    query.exec("select " + DatabaseHelper::tablePlaylistsName + ".name, " +
               DatabaseHelper::tableTracksName + ".name from " + DatabaseHelper::tableTracksName +
               " inner join " + DatabaseHelper::tablePlaylistsName + " on " +
               DatabaseHelper::tablePlaylistsName + ".id=" + DatabaseHelper::tableTracksName + ".playlistId");
    if (query.first())
    {
        do
        {
            qDebug() << query.value(0).toString() << " " << query.value(1).toString();
        }while(query.next());
    }
}

QString PlaylistsDatabase::getPlaylistId(QString playlistName)
{
    QSqlQuery query;
    query.exec("select id from " + DatabaseHelper::tablePlaylistsName +
               " where name=" + '\'' + playlistName + '\'');
    if (query.first())
        return query.value(0).toString();
    return "";
}

QString PlaylistsDatabase::getPlaylistName(QString playlistId)
{
    QSqlQuery query;
    query.exec("select name from " + DatabaseHelper::tablePlaylistsName +
               " where id=" + '\'' + playlistId + '\'');
    if (query.first())
        return query.value(0).toString();
    return "";
}

void PlaylistsDatabase::writeToDB(QMap<QString, QSet<QString> > *map)
{
    writePlalistsToDB(QStringList(map->keys()));
    writeTracksToDB(map);
    //this->showData();
}

void PlaylistsDatabase::readFromDB(QMap<QString, QSet<QString> > *map)
{
    QSqlQuery query;
    query.exec("select name from " + DatabaseHelper::tablePlaylistsName);
    if (query.first())
    {
        do
        {
            map->insert(query.value(0).toString(), QSet<QString>());
        }while(query.next());
    }


    //problem here

    query.exec("select name, playlistId from " + DatabaseHelper::tableTracksName);
    if (query.first())
    {
        do
        {
            QString playListName = getPlaylistName(query.value(1).toString());
            //qDebug() << playListName << " " << query.value(0).toString();
            map->find(playListName)->insert(query.value(0).toString());
        }while(query.next());
    }
}

void PlaylistsDatabase::clearDB()
{
    QSqlQuery query;
    query.exec("delete from " + DatabaseHelper::tablePlaylistsName);
    query.exec("delete from " + DatabaseHelper::tableTracksName);
}

void PlaylistsDatabase::writePlalistsToDB(QStringList list)
{
    QSqlQuery query;

    std::for_each(list.begin(), list.end(), [&query](QString playlistName)
    {
        query.exec("insert into " + DatabaseHelper::tablePlaylistsName + "(name) values(" +
                   '\'' + playlistName + '\'' + ")");
    });
}

void PlaylistsDatabase::writeTracksToDB(QMap<QString, QSet<QString> > *map)
{
    QSqlQuery query;

    int index = 1;
    for (QList<QString>::iterator it = map->keys().begin(); it != map->keys().end(); ++it)
    {
        for (QString trackName : map->value(*it))
        {
            query.exec("insert into " + DatabaseHelper::tableTracksName +
                       "(name, playlistId) values(" + '\'' + trackName + '\'' +
                       ", " + QString::number(index) + ");");
        }

        index++;
    }
}
