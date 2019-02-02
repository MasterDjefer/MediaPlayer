#include "widgetplaybackrate.h"

WidgetPlaybackRate::WidgetPlaybackRate(MusicFile *file, QWidget *parent) : QWidget(parent),
                                                                           mPlaybackRate(1.0),
                                                                            mRateSpeed("x")
{
    this->setFixedSize(100, 50);

    createItems();
    QObject::connect(mButtonRateDec, &QPushButton::clicked, this, &WidgetPlaybackRate::onButtonPlaybackRateDec);
    QObject::connect(mButtonRateInc, &QPushButton::clicked, this, &WidgetPlaybackRate::onButtonPlaybackRateInc);
    QObject::connect(this, &WidgetPlaybackRate::playbackRateChange, this, &WidgetPlaybackRate::onPlaybackChange);

    QObject::connect(this, &WidgetPlaybackRate::playbackRateChange, file, &MusicFile::setPlaybackRate);
}

void WidgetPlaybackRate::createItems()
{
    mButtonRateInc = new QPushButton;
    mButtonRateInc->setFocusPolicy(Qt::NoFocus);
    mButtonRateInc->setFixedSize(30, 30);
    mButtonRateInc->setIcon(QIcon(":images/rateInc.png"));
    mButtonRateInc->setIconSize(mButtonRateInc->size());

    mButtonRateDec = new QPushButton;
    mButtonRateDec->setFocusPolicy(Qt::NoFocus);
    mButtonRateDec->setFixedSize(30, 30);
    mButtonRateDec->setIcon(QIcon(":images/rateDec.png"));
    mButtonRateDec->setIconSize(mButtonRateInc->size());

    mLabelRate = new QLabel(QString::number(mPlaybackRate) + ".0" + mRateSpeed);

    mMainLayout = new QHBoxLayout;

    mMainLayout->addWidget(mButtonRateDec);
    mMainLayout->addWidget(mButtonRateInc);
    mMainLayout->addWidget(mLabelRate);
    this->setLayout(mMainLayout);
}

qreal WidgetPlaybackRate::getPlaybackRate()
{
    return mPlaybackRate;
}

void WidgetPlaybackRate::setPlaybackRate(qreal value)
{
    mPlaybackRate = value;
    onPlaybackChange();
}

void WidgetPlaybackRate::onButtonPlaybackRateInc()
{
    if (mPlaybackRate > 4)
        return;

    mPlaybackRate += 0.1;
    emit playbackRateChange(mPlaybackRate);
}

void WidgetPlaybackRate::onButtonPlaybackRateDec()
{
    if (mPlaybackRate < 0.2)
    {
        return;
    }

    mPlaybackRate -= 0.1;
    emit playbackRateChange(mPlaybackRate);
}

void WidgetPlaybackRate::onPlaybackChange()
{
    if (QString::number(mPlaybackRate).size() == 1)
    {
        mLabelRate->setText(QString::number(mPlaybackRate) + ".0" + mRateSpeed);
        return;
    }
    mLabelRate->setText(QString::number(mPlaybackRate) + mRateSpeed);
}
