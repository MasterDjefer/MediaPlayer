#ifndef MUSICINFO_H
#define MUSICINFO_H
#include <QString>
#include <QDebug>

class MusicInfo
{
protected:
    QString mData;
public:
    MusicInfo(const QString data);
    virtual ~MusicInfo();
    QString data() const;
    void setData(const QString data);
    virtual QString toString() const = 0;
};

#endif // MUSICINFO_H
