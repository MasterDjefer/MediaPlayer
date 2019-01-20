#include "widgetvolume.h"

WidgetVolume::WidgetVolume(MusicFile *file, QWidget *parent) : QWidget(parent), isSoundOn(true), mVolumeValue(volumeMax)
{
    this->setFixedSize(150, 50);
    createItems();

    QObject::connect(mSliderVolume, &QSlider::valueChanged, file, &MusicFile::setVolume);
    QObject::connect(file, &MusicFile::volumeChanged, mSliderVolume, &QSlider::setValue);
}

void WidgetVolume::createItems()
{
    mMainLayout = new QHBoxLayout;

    mButtonSound = new QPushButton;
    mButtonSound->setFocusPolicy(Qt::NoFocus);
    mButtonSound->setIcon(QIcon(":/images/soundOn.png"));
    mButtonSound->setFixedSize(30,30);
    mButtonSound->setIconSize(QSize(mButtonSound->width(), mButtonSound->height()));
    QObject::connect(mButtonSound, &QPushButton::clicked, this, &WidgetVolume::onButtonVolumePressed);

    mSliderVolume = new QSlider;
    mSliderVolume->setFocusPolicy(Qt::NoFocus);
    mSliderVolume->setRange(volumeMin, volumeMax);
    mSliderVolume->setValue(volumeMax);
    mSliderVolume->setFixedSize(100, 30);
    mSliderVolume->setOrientation(Qt::Horizontal);
    QObject::connect(mSliderVolume, &QSlider::valueChanged, this, &WidgetVolume::onSliderMove);


    mMainLayout->addWidget(mButtonSound);
    mMainLayout->addWidget(mSliderVolume);
    this->setLayout(mMainLayout);
}

void WidgetVolume::setSound(bool sound, int volume)
{
    isSoundOn = sound;
    mVolumeValue = volume;
}

bool WidgetVolume::getSound()
{
    return isSoundOn;
}

int WidgetVolume::getVolume()
{
    return mVolumeValue;
}

void WidgetVolume::onSliderMove()
{
    if (mSliderVolume->value() == 0)
        this->mButtonSound->setIcon(QIcon(":/images/soundOff.png"));
    else
        this->mButtonSound->setIcon(QIcon(":/images/soundOn.png"));
}

void WidgetVolume::onButtonVolumePressed()
{
    if (isSoundOn)
    {
        mButtonSound->setIcon(QIcon(":/images/soundOff.png"));
        mVolumeValue = mSliderVolume->value();
        mSliderVolume->setValue(0);
    }
    else
    {
        mButtonSound->setIcon(QIcon(":/images/soundOn.png"));
        mSliderVolume->setValue(mVolumeValue);
    }
    isSoundOn = !isSoundOn;
}
