#ifndef WIDGETCONTROLS_H
#define WIDGETCONTROLS_H

#include <QApplication>
#include <QDesktopWidget>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QKeyEvent>
#include <QDebug>

#include "musicfile.h"
#include "widgetinfo.h"
#include "widgetvolume.h"
#include "widgetplaybackrate.h"
#include "widgetprogress.h"

class WidgetControls : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetControls(MusicFile* file, QWidget *parent = 0);
private:
    MusicFile *mMusicFile;
    bool isRunning;
    bool isRepeating;
    QPushButton *mButtonPlay;
    QPushButton *mButtonStop;
    QPushButton *mButtonReplay;
    WidgetVolume *mWidgetVolume;
    WidgetPlaybackRate *mWidgetPlaybackRate;
    WidgetProgress *mWidgetProgress;

    QHBoxLayout *mLayoutForControlPanel;
    QVBoxLayout *mMainLayout;

public:
    bool running();
    QIcon getPlayIcon();
    qreal getPlaybackRate();
    QIcon getReplayIcon();
    bool repeating();
    void setButtonPlayIcon(QIcon icon);
    void setPlaybackRate(qreal value);
    void setButtonReplayIcon(QIcon icon);
    void setRepeating(bool repeating);
    bool getSound();
    int getVolume();
    void setSound(bool sound, int volume);
private:
    void createButtons();
    void createWidgetVolume();
    void createWidgetPlaybackRate();
    void createWidgetProgress();
    void createLayouts();
    void keyPressEvent(QKeyEvent *event);

    void upKeyPressed();
    void downKeyPressed();
    void leftKeyPressed();
    void rightKeyPressed();

private slots:
    void onButtonPlayPressed();
    void onButtonStopPressed();
    void onButtonReplayPressed();
    void onFileChange();
    void onPositionChange(qint64 position);
signals:
    void escPressed();
};

#endif // WIDGETCONTROLS_H
