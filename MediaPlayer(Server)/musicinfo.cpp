#include "musicinfo.h"

MusicInfo::MusicInfo(const QString data)
{
    setData(data);
}

MusicInfo::~MusicInfo()
{
}

QString MusicInfo::data() const
{
    return mData;
}

void MusicInfo::setData(const QString data)
{
    if (data == "")
    {
        mData = "none";
    }
    else
        mData = data;
}
