#ifndef WIDGETPROGRESS_H
#define WIDGETPROGRESS_H

#include <QWidget>
#include <QSlider>
#include <QLabel>
#include <QHBoxLayout>
#include <QDebug>

#include "musicfile.h"
#include "time.h"

class WidgetProgress : public QWidget
{
    Q_OBJECT
public:
    WidgetProgress(MusicFile* file, QWidget *parent = 0);
    ~WidgetProgress();

private:
    QSlider *mSliderProgress;
    QLabel *mProgress;
    QHBoxLayout *mMainLayout;
    Time *mCurrentPosition;
    Time *mDuration;

public:
    void setPosition(int pos);

private:
    void createItems();
    void createTimes();
private slots:
    void mediaDurationChange(qint64 duration);
    void mediaPositionChange(qint64 position);
    //void mediaSetted();
};

#endif // WIDGETPROGRESS_H
