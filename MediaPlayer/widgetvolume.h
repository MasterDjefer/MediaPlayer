#ifndef WIDGETVOLUME_H
#define WIDGETVOLUME_H

#include <QWidget>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>

#include "musicfile.h"

class WidgetVolume : public QWidget
{
    Q_OBJECT
    enum VolumeRange
    {
        volumeMin = 0,
        volumeMax = 100
    };

public:
    explicit WidgetVolume(MusicFile* file, QWidget *parent = 0);
private:
    bool isSoundOn;
    int mVolumeValue;
    QPushButton *mButtonSound;
    QSlider *mSliderVolume;
    QHBoxLayout *mMainLayout;

    void createItems();

public:
    void setSound(bool sound, int volume);
    bool getSound();
    int getVolume();

private slots:
    void onSliderMove();
    void onButtonVolumePressed();

};

#endif // WIDGETVOLUME_H
