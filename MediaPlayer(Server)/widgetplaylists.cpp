#include "widgetplaylists.h"

WidgetPlayLists::WidgetPlayLists(MusicFile *file, QWidget *parent) : mMusicFile(file)
{
    this->setFixedWidth(parent->height() / 2);//, parent->height());

    createLabels();
    createSearchField();
    createComboBox();
    createButtons();
    createList();
    createLayouts();
    createWidgetAddPlaylist();
    createMap();
    loadMap();

    QObject::connect(mListWidget, &QListWidget::itemDoubleClicked, file, &MusicFile::setMediaData);
}

WidgetPlayLists::~WidgetPlayLists()
{
    delete mMap;
}

void WidgetPlayLists::createLabels()
{
    mLabelPlaylist = new QLabel("Playlists");
    mLabelTrack = new QLabel("Tracks");
    mLabelSearch = new QLabel("Search");
}

void WidgetPlayLists::createSearchField()
{
    mEditSearch = new QLineEdit;
}

void WidgetPlayLists::createComboBox()
{
    mComboboxPlaylists = new QComboBox(this);
    mComboboxPlaylists->setFocusPolicy(Qt::NoFocus);
    QObject::connect(mComboboxPlaylists, &QComboBox::currentTextChanged, this, &WidgetPlayLists::chooseAnotherPlaylist);
}

void WidgetPlayLists::createButtons()
{
    mButtonAddPlayList = new QPushButton(this);
    mButtonAddPlayList->setIcon(QIcon(":/images/add.png"));
    mButtonAddPlayList->setIconSize(mButtonAddPlayList->size());
    mButtonAddPlayList->setFocusPolicy(Qt::NoFocus);
    mButtonAddPlayList->setFixedSize(30,30);
    QObject::connect(mButtonAddPlayList, &QPushButton::clicked, this, &WidgetPlayLists::onButtonAddPlaylistPressed);

    mButtonRemovePlayList = new QPushButton(this);
    mButtonRemovePlayList->setIcon(QIcon(":/images/remove.png"));
    mButtonRemovePlayList->setIconSize(mButtonRemovePlayList->size());
    mButtonRemovePlayList->setFocusPolicy(Qt::NoFocus);
    mButtonRemovePlayList->setFixedSize(30,30);
    QObject::connect(mButtonRemovePlayList, &QPushButton::clicked, this, &WidgetPlayLists::onButtonRemovePlaylistPressed);

    mButtonAddFiles = new QPushButton(this);
    mButtonAddFiles->setIcon(QIcon(":/images/add.png"));
    mButtonAddFiles->setIconSize(mButtonAddFiles->size());
    mButtonAddFiles->setFocusPolicy(Qt::NoFocus);
    mButtonAddFiles->setFixedSize(30,30);
    QObject::connect(mButtonAddFiles, &QPushButton::clicked, this, &WidgetPlayLists::onButtonAddTracks);

    mButtonRemoveFiles = new QPushButton(this);
    mButtonRemoveFiles->setIcon(QIcon(":/images/remove.png"));
    mButtonRemoveFiles->setIconSize(mButtonRemoveFiles->size());
    mButtonRemoveFiles->setFocusPolicy(Qt::NoFocus);
    mButtonRemoveFiles->setFixedSize(30,30);
    QObject::connect(mButtonRemoveFiles, &QPushButton::clicked, this, &WidgetPlayLists::onButtonRemoveTracks);


    mButtonSearch = new QPushButton(this);
    mButtonSearch->setIcon(QIcon(":/images/search.png"));
    mButtonSearch->setIconSize(mButtonSearch->size());
    mButtonSearch->setFocusPolicy(Qt::NoFocus);
    mButtonSearch->setFixedSize(30,30);
    QObject::connect(mButtonSearch, &QPushButton::clicked, this, &WidgetPlayLists::onButtonSearch);
}

void WidgetPlayLists::createList()
{
    mListWidget = new QListWidget(this);
    mListWidget->setFocusPolicy(Qt::NoFocus);
}

void WidgetPlayLists::createLayouts()
{
    mLayoutForSearch = new QHBoxLayout;
    mLayoutForSearch->addWidget(mEditSearch);
    mLayoutForSearch->addWidget(mButtonSearch);

    mLayoutForPlaylists = new QHBoxLayout;
    mLayoutForPlaylists->addWidget(mComboboxPlaylists);
    mLayoutForPlaylists->addWidget(mButtonAddPlayList);
    mLayoutForPlaylists->addWidget(mButtonRemovePlayList);

    mLayoutForTracksButtons = new QVBoxLayout;
    mLayoutForTracksButtons->addWidget(mButtonAddFiles);
    mLayoutForTracksButtons->addWidget(mButtonRemoveFiles, 1, Qt::AlignTop);

    mLayoutForTracks = new QHBoxLayout;
    mLayoutForTracks->addWidget(mListWidget);
    mLayoutForTracks->addLayout(mLayoutForTracksButtons);

    mMainLayout = new QVBoxLayout;
    mMainLayout->addWidget(mLabelSearch);
    mMainLayout->addLayout(mLayoutForSearch);
    mMainLayout->addWidget(mLabelPlaylist);
    mMainLayout->addLayout(mLayoutForPlaylists);
    mMainLayout->addWidget(mLabelTrack);
    mMainLayout->addLayout(mLayoutForTracks);

    this->setLayout(mMainLayout);
}

void WidgetPlayLists::createWidgetAddPlaylist()
{
    mWidgetAddPlaylist = new WidgetAddPlaylist;
    QObject::connect(mWidgetAddPlaylist, &WidgetAddPlaylist::playListCreated, this, &WidgetPlayLists::onPlaylistCreated);
}

void WidgetPlayLists::createMap()
{
    mMap = new PlaylistMap;
}

void WidgetPlayLists::loadMap()
{
    mComboboxPlaylists->addItems(QStringList(mMap->map()->keys()));
}

QString WidgetPlayLists::currentItem()
{
    if (mListWidget->currentRow() == -1)
    {
        return QString("");
    }
    else
        return mListWidget->currentItem()->text();
}

QString WidgetPlayLists::mediaPath(QString fullPath)
{
    return fullPath.remove(0, 8);
}

int WidgetPlayLists::findTrack(QString track)
{
    for (int i = 0; i < mListWidget->count(); ++i)
    {
        if (mListWidget->item(i)->text() == track)
        {
            return i;
        }
    }

    return -1;
}

QString WidgetPlayLists::nextTrack()
{
    if (mListWidget->currentRow() == -1 || mListWidget->count() == 0)
    {
        return QString("");
    }

    int currentItemIndex = findTrack(mediaPath(mMusicFile->media().canonicalUrl().toString()));
    if (currentItemIndex == mListWidget->count() - 1 || currentItemIndex == -1)
    {
        return QString("");
    }

    mListWidget->setCurrentRow(currentItemIndex + 1);
    return mListWidget->item(currentItemIndex + 1)->text();
}

bool WidgetPlayLists::isPlaylistExist(QString playlistName)
{
    bool flag = false;
    for (int i = 0; i < mComboboxPlaylists->count(); ++i)
    {
        if (mComboboxPlaylists->itemText(i) == playlistName)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

void WidgetPlayLists::onButtonAddPlaylistPressed()
{
    mWidgetAddPlaylist->exec();
}

void WidgetPlayLists::onButtonRemovePlaylistPressed()
{
    if (mComboboxPlaylists->currentIndex() != -1)
    {
        mMap->removeList(mComboboxPlaylists->currentText());
        mComboboxPlaylists->removeItem(mComboboxPlaylists->currentIndex());
        mListWidget->clear();

        if (mComboboxPlaylists->currentIndex() != -1)
        {
            mListWidget->addItems(mMap->tracks(mComboboxPlaylists->currentText()));
        }
    }
}

void WidgetPlayLists::onPlaylistCreated(QString playlistName)
{
    if (!isPlaylistExist(playlistName))
    {
        mComboboxPlaylists->addItem(playlistName);
        mComboboxPlaylists->setCurrentIndex(mComboboxPlaylists->count() - 1);
        mMap->addPlaylist(playlistName);
    }
}

void WidgetPlayLists::onButtonAddTracks()
{
    if (mComboboxPlaylists->currentIndex() != -1)
    {
        QStringList fileNames = QFileDialog::getOpenFileNames(this, "Open file", "E://", "Music(*.mp3);;Video(*.mp4);");
        if (fileNames.isEmpty())
        {
            return;
        }
        mListWidget->clear();
        mMap->addTracks(mComboboxPlaylists->currentText(), fileNames);
        mListWidget->addItems(mMap->tracks(mComboboxPlaylists->currentText()));
        mListWidget->setCurrentRow(0);
    }
}

void WidgetPlayLists::onButtonRemoveTracks()
{
    if (mComboboxPlaylists->currentIndex() != -1 && mListWidget->currentRow() != -1)
    {
        mMap->removeElement(mComboboxPlaylists->currentText(), mListWidget->currentItem()->text());
        mListWidget->clear();
        mListWidget->addItems(mMap->tracks(mComboboxPlaylists->currentText()));
        if (mListWidget->count() != -1)
        {
            mListWidget->setCurrentRow(0);
        }
    }
}

void WidgetPlayLists::onButtonSearch()
{
    QStringList searchedList;
    QString searchedTrack = mEditSearch->text();
    if (searchedTrack == "")
    {
        QMessageBox::information(this, "Searching", "Input something!");
        return;
    }
    searchedTrack.toLower();

    QList<QString> playlistNames = mMap->map()->keys();

    std::for_each(playlistNames.begin(), playlistNames.end(), [&](QString playlistName)
    {
        QSet<QString> trackNames = mMap->map()->value(playlistName);

        std::for_each(trackNames.begin(), trackNames.end(), [&](QString trackName)
        {
            QString temp = trackName;
            trackName.toLower();
            if (trackName.contains(searchedTrack))
            {
                searchedList.push_back(temp);
            }
        });
    });
    if (searchedList.isEmpty())
    {
        QMessageBox::information(this, "Searching", searchedTrack + " not found");
        return;
    }

    mComboboxPlaylists->setCurrentIndex(-1);
    mListWidget->clear();
    mListWidget->addItems(searchedList);
}

void WidgetPlayLists::chooseAnotherPlaylist()
{
    mListWidget->clear();
    mListWidget->addItems(mMap->tracks(mComboboxPlaylists->currentText()));
}
