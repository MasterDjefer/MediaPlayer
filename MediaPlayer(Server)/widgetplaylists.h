#ifndef WIDGETPLAYLISTS_H
#define WIDGETPLAYLISTS_H

#include <QWidget>
#include <QDebug>
#include <QListWidget>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include <QFileDialog>
#include <QStringList>
#include <algorithm>
#include <QMessageBox>

#include "widgetaddplaylist.h"
#include "musicfile.h"
#include "playlistmap.h"


class WidgetPlayLists : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetPlayLists(MusicFile* file, QWidget *parent = 0);
    ~WidgetPlayLists();

private:
    QLabel *mLabelPlaylist;
    QLabel *mLabelTrack;
    QLabel *mLabelSearch;
    QLineEdit *mEditSearch;
    QPushButton *mButtonSearch;
    QComboBox *mComboboxPlaylists;
    QListWidget *mListWidget;
    QPushButton *mButtonAddPlayList;
    QPushButton *mButtonRemovePlayList;
    QPushButton *mButtonAddFiles;
    QPushButton *mButtonRemoveFiles;
    WidgetAddPlaylist *mWidgetAddPlaylist;
    MusicFile *mMusicFile;

    QHBoxLayout *mLayoutForSearch;
    QHBoxLayout *mLayoutForTracks;
    QVBoxLayout *mLayoutForTracksButtons;
    QHBoxLayout *mLayoutForPlaylists;
    QVBoxLayout *mMainLayout;

    PlaylistMap *mMap;

private:
    void createLabels();
    void createSearchField();
    void createComboBox();
    void createButtons();
    void createList();
    void createLayouts();
    void createWidgetAddPlaylist();
    void createMap();
    void loadMap();
public:
    QString currentItem();
    QString mediaPath(QString fullPath);
    QString nextTrack();

private:
    int findTrack(QString track);
    bool isPlaylistExist(QString playlistName);

private slots:
    void onButtonAddPlaylistPressed();
    void onButtonRemovePlaylistPressed();
    void onPlaylistCreated(QString playlistName);
    void onButtonAddTracks();
    void onButtonRemoveTracks();
    void onButtonSearch();
    void chooseAnotherPlaylist();

};

#endif // WIDGETPLAYLISTS_H
