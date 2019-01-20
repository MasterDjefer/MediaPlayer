#ifndef WIDGETINFO_H
#define WIDGETINFO_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

#include "music.h"

class WidgetInfo : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetInfo(QWidget *parent);
    QVBoxLayout *mMainLayout;
    QLabel *mLabelArtist;
    QLabel *mLabelTitle;
    QLabel *mLabelGenre;
    QLabel *mLabelYear;
public:
    void setZero();
private:
    void allocData();
    void setLabels();
public slots:
    void setMusic(MediaData *mediaData);
};

#endif // WIDGETINFO_H
