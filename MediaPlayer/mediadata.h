#ifndef MEDIADATA_H
#define MEDIADATA_H


class MediaData
{
public:
    enum MediaType
    {
        music,
        video
    };
    virtual MediaType type() const = 0;
};

#endif // MEDIADATA_H
