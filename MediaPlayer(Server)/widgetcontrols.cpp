#include "widgetcontrols.h"

WidgetControls::WidgetControls(MusicFile *file, QWidget *parent) : QWidget(parent),
                            mMusicFile(file), isRunning(false), isRepeating(false)
{
    //this->resize(500,500);

    createButtons();
    createWidgetVolume();
    createWidgetPlaybackRate();
    createWidgetProgress();
    createLayouts();

    QObject::connect(mMusicFile, &MusicFile::positionChanged, this, &WidgetControls::onPositionChange);

    this->setWindowFlags(Qt::CustomizeWindowHint);
    this->setFixedWidth(QApplication::desktop()->screenGeometry().width());
    this->setFixedHeight(126);
    this->move(0, QApplication::desktop()->screenGeometry().height() - this->height());
}

bool WidgetControls::running()
{
    return isRunning;
}


QIcon WidgetControls::getPlayIcon()
{
    return mButtonPlay->icon();
}

qreal WidgetControls::getPlaybackRate()
{
    return mWidgetPlaybackRate->getPlaybackRate();
}

QIcon WidgetControls::getReplayIcon()
{
    return mButtonReplay->icon();
}

bool WidgetControls::repeating()
{
    return isRepeating;
}

void WidgetControls::setButtonPlayIcon(QIcon icon)
{
    mButtonPlay->setIcon(icon);
}

void WidgetControls::setPlaybackRate(qreal value)
{
    mWidgetPlaybackRate->setPlaybackRate(value);
}

void WidgetControls::setButtonReplayIcon(QIcon icon)
{
    mButtonReplay->setIcon(icon);
}

void WidgetControls::setRepeating(bool repeating)
{
    isRepeating = repeating;
}

bool WidgetControls::getSound()
{
    return mWidgetVolume->getSound();
}

int WidgetControls::getVolume()
{
    return mWidgetVolume->getVolume();
}

void WidgetControls::setSound(bool sound, int volume)
{
    mWidgetVolume->setSound(sound, volume);
}
void WidgetControls::createButtons()
{
    mButtonPlay = new QPushButton(this);
    mButtonPlay->setFocusPolicy(Qt::NoFocus);
    mButtonPlay->setFixedSize(30,30);
    mButtonPlay->setIcon(QIcon(":/images/play.png"));
    mButtonPlay->setIconSize(mButtonPlay->size());
    QObject::connect(mButtonPlay, &QPushButton::clicked, this, &WidgetControls::onButtonPlayPressed);

    mButtonStop = new QPushButton(this);
    mButtonStop->setFocusPolicy(Qt::NoFocus);
    mButtonStop->setFixedSize(30,30);
    mButtonStop->setIcon(QIcon(":/images/stop.png"));
    mButtonStop->setIconSize(mButtonPlay->size());
    QObject::connect(mButtonStop, &QPushButton::clicked, this, &WidgetControls::onButtonStopPressed);

    mButtonReplay = new QPushButton(this);
    mButtonReplay->setFocusPolicy(Qt::NoFocus);
    mButtonReplay->setFixedSize(30,30);
    mButtonReplay->setIcon(QIcon(":/images/repeat.png"));
    mButtonReplay->setIconSize(mButtonReplay->size());
    QObject::connect(mButtonReplay, &QPushButton::clicked, this, &WidgetControls::onButtonReplayPressed);
}



void WidgetControls::createWidgetVolume()
{
    mWidgetVolume = new WidgetVolume(this->mMusicFile, this);
}

void WidgetControls::createWidgetPlaybackRate()
{
    mWidgetPlaybackRate = new WidgetPlaybackRate(mMusicFile, this);
}

void WidgetControls::createWidgetProgress()
{
    mWidgetProgress = new WidgetProgress(mMusicFile, this);
}



void WidgetControls::createLayouts()
{
    mLayoutForControlPanel = new QHBoxLayout;
    mMainLayout = new QVBoxLayout;

    mLayoutForControlPanel->addWidget(mButtonPlay);
    mLayoutForControlPanel->addWidget(mButtonStop);
    mLayoutForControlPanel->addWidget(mWidgetPlaybackRate);
    mLayoutForControlPanel->addWidget(mButtonReplay);
    mLayoutForControlPanel->addWidget(mWidgetVolume, 0, Qt::AlignRight);

    mMainLayout->addWidget(mWidgetProgress);
    mMainLayout->addLayout(mLayoutForControlPanel);

    this->setLayout(mMainLayout);
}

void WidgetControls::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Space:
            onButtonPlayPressed();
            break;
        case Qt::Key_Up:
            upKeyPressed();
            break;
        case Qt::Key_Down:
            downKeyPressed();
            break;
        case Qt::Key_Left:
            leftKeyPressed();
            break;
        case Qt::Key_Right:
            rightKeyPressed();
            break;
        case Qt::Key_Escape:
            emit escPressed();
            break;
    }
}



void WidgetControls::onButtonPlayPressed()
{
    if (mMusicFile->media().isNull())
        return;
    if (isRunning)
    {
        mButtonPlay->setIcon(QIcon(":/images/play.png"));
        mMusicFile->pause();
    }
    else
    {
        mButtonPlay->setIcon(QIcon(":/images/pause.png"));
        mMusicFile->play();
    }
    isRunning = !isRunning;
}

void WidgetControls::onButtonStopPressed()
{
    mMusicFile->stop();
    isRunning = false;
    mButtonPlay->setIcon(QIcon(":/images/play.png"));
}

void WidgetControls::onButtonReplayPressed()
{
    if (isRepeating)
    {
        mButtonReplay->setIcon(QIcon(":/images/repeat.png"));
    }
    else
    {
        mButtonReplay->setIcon(QIcon(":/images/repeatPressed.png"));
    }
    isRepeating = !isRepeating;
}



void WidgetControls::onFileChange()
{
    isRunning = false;
    mButtonPlay->setIcon(QIcon(":/images/play.png"));
}

void WidgetControls::onPositionChange(qint64 position)
{
    if (mMusicFile->media().isNull())
        return;
    if (position == mMusicFile->duration() && position != 0)
    {
        if (isRepeating)
        {
            mMusicFile->play();
        }
        else
        {
            mWidgetProgress->setPosition(0);
            isRunning = false;
            mButtonPlay->setIcon(QIcon(":/images/play.png"));
        }
    }
}

void WidgetControls::upKeyPressed()
{
    mMusicFile->setVolume(mMusicFile->volume() + 5);
}

void WidgetControls::downKeyPressed()
{
    mMusicFile->setVolume(mMusicFile->volume() - 5);
}

void WidgetControls::leftKeyPressed()
{
    if (mMusicFile->position() != 0)
        mMusicFile->setPosition(mMusicFile->position() - 5000);
}

void WidgetControls::rightKeyPressed()
{
    if (mMusicFile->position() + 5000 <= mMusicFile->duration())
        mMusicFile->setPosition(mMusicFile->position() + 5000);
}
