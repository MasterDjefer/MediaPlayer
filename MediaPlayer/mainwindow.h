#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QDesktopWidget>
#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QStatusBar>
#include <QDebug>
#include <QSlider>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QVideoWidget>
#include <QMediaPlaylist>
#include <QFrame>

#include <QHBoxLayout>
#include <QVBoxLayout>

#include "musicfile.h"
#include "widgetinfo.h"
#include "widgetvolume.h"
#include "widgetplaybackrate.h"
#include "widgetprogress.h"
#include "myvideowidget.h"
#include "widgetcontrols.h"

#include "widgetplaylists.h"

#include "server.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    bool isRunning;
    bool isRepeating;
    bool isFullScreen;
    bool isWidgetPlaylistVisible;
    QPushButton *mButtonPlay;
    QPushButton *mButtonStop;
    QPushButton *mButtonReplay;
    QPushButton *mButtonShowPlaylist;
    MusicFile *mMusicFile;
    WidgetInfo *mWidgetInfo;
    WidgetVolume *mWidgetVolume;
    WidgetPlaybackRate *mWidgetPlaybackRate;
    WidgetProgress *mWidgetProgress;
    MyVideoWidget* mVideoWidget;
    WidgetControls *mWidgetControls;
    WidgetPlayLists *mWidgetPlaylist;

    QLabel *mLabelMusic;

    QHBoxLayout *mLayoutForControlPanel;
    QVBoxLayout *mMainLayout;
    QHBoxLayout *mLayout;

    Server *mServer;
private:
    void createMenu();
    void createButtons();
    void createLabel();
    void createMusicFile();
    void createWidgetInfo();
    void createWidgetVolume();
    void createWidgetPlaybackRate();
    void createWidgetProgress();
    void createVideoWidget();
    void createWidgetControls();
    void createWidgetPlaylist();
    void createLayouts();
    void createServer();
    void keyPressEvent(QKeyEvent* event);
    void moveEvent(QMoveEvent *event);
    void setWidgetsFromControls();
    void setControlsFromWidgets();

private slots:
    void onButtonPlayPressed();
    void onButtonStopPressed();
    void onButtonReplayPressed();
    void onButtonPlaylist();
    void onOpenFile();
    void onFileChange();
    void onPositionChange(qint64 position);
    void videoWidgetLeftMouseClicked();
    void videoWidgetDoubleClicked();
    void videoWidgetEscapePressed();
    void videoWidgetSpacePressed();
    void upKeyPressed();
    void downKeyPressed();
    void leftKeyPressed();
    void rightKeyPressed();
    void fullScreenMouseDown();
    void fullScreenMouseUp();
    void onWidgetControlsEscPressed();

    void onMusicReceived();
    void onClientConnected();
};

#endif // MAINWINDOW_H
