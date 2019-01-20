#include "widgetinfo.h"

WidgetInfo::WidgetInfo(QWidget *parent) : QWidget(parent)
{
    this->resize(parent->width(), 100);//later i will off this
    allocData();
    setLabels();
    this->setLayout(mMainLayout);
}

void WidgetInfo::setZero()
{
    mLabelArtist->setText("");
    mLabelTitle->setText("");
    mLabelGenre->setText("");
    mLabelYear->setText("");
}

void WidgetInfo::setMusic(MediaData *mediaData)
{
    if (mediaData != nullptr)
    {
        Music* music = static_cast<Music*>(mediaData);

        mLabelArtist->setText(music->artist()->toString());
        mLabelTitle->setText(music->title()->toString());
        mLabelGenre->setText(music->genre()->toString());
        mLabelYear->setText(music->year()->toString());
    }
    else
        setZero();
}

void WidgetInfo::allocData()
{
    mMainLayout = new QVBoxLayout;

    mLabelArtist = new QLabel;
    mLabelTitle = new QLabel;
    mLabelGenre = new QLabel;
    mLabelYear = new QLabel;
}

void WidgetInfo::setLabels()
{
    mMainLayout->addWidget(mLabelArtist);
    mMainLayout->addWidget(mLabelTitle);
    mMainLayout->addWidget(mLabelGenre);
    mMainLayout->addWidget(mLabelYear);
}
