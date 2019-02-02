#include "widgetprogress.h"

WidgetProgress::WidgetProgress(MusicFile *file, QWidget *parent) : QWidget(parent)
{
    this->resize(parent->width(), 30);
    createItems();
    createTimes();

    QObject::connect(file, &MusicFile::durationChanged, this, &WidgetProgress::mediaDurationChange);
    QObject::connect(file, &MusicFile::positionChanged, this, &WidgetProgress::mediaPositionChange);
    QObject::connect(mSliderProgress, &QSlider::sliderMoved, file, &MusicFile::setPosition);
}

WidgetProgress::~WidgetProgress()
{
    delete mDuration;
    delete mCurrentPosition;
}

void WidgetProgress::setPosition(int pos)
{
    mSliderProgress->setValue(pos);
}

void WidgetProgress::createItems()
{
    mSliderProgress = new QSlider;
    mSliderProgress->setFocusPolicy(Qt::NoFocus);
    mSliderProgress->setOrientation(Qt::Horizontal);
    mSliderProgress->setFixedHeight(30);

    mProgress = new QLabel("00:00:00/00:00:00");
    mMainLayout = new QHBoxLayout;


    mMainLayout->addWidget(mSliderProgress);
    mMainLayout->addWidget(mProgress);
    this->setLayout(mMainLayout);
}

void WidgetProgress::createTimes()
{
    mDuration = new Time;
    mCurrentPosition = new Time;
}

void WidgetProgress::mediaDurationChange(qint64 duration)
{
    mSliderProgress->setMaximum(duration);
    mDuration->setTime(duration);
    mProgress->setText(mDuration->toString());
    mCurrentPosition->setTime(0);
    mProgress->setText("00:00:00/" + mDuration->toString());
}

void WidgetProgress::mediaPositionChange(qint64 position)
{
    if (!mCurrentPosition->isTimeSet() || !mDuration->isTimeSet())
        return;
    mSliderProgress->setValue(position);
    mCurrentPosition->setTime(position);
    mProgress->setText(mCurrentPosition->toString() + "/" + mDuration->toString());
}
