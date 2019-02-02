#ifndef WIDGETPLAYBACKRATE_H
#define WIDGETPLAYBACKRATE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <cmath>
#include <QDebug>

#include "musicfile.h"

class WidgetPlaybackRate : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetPlaybackRate(MusicFile *file, QWidget *parent = 0);

private:
    QPushButton *mButtonRateInc;
    QPushButton *mButtonRateDec;
    QHBoxLayout *mMainLayout;
    QLabel *mLabelRate;
    qreal mPlaybackRate;
    const QString mRateSpeed;

    void createItems();
public:
    qreal getPlaybackRate();
    void setPlaybackRate(qreal value);

signals:
    void playbackRateChange(qreal value);

public slots:
    void onButtonPlaybackRateInc();
    void onButtonPlaybackRateDec();
    void onPlaybackChange();
};

#endif // WIDGETPLAYBACKRATE_H
