#ifndef SERVER_H
#define SERVER_H
#include <QObject>
#include <QDebug>

#include <QThread>
#include <cstring>

#include <winsock2.h>


class Server : public QObject
{
    Q_OBJECT

private:
    static const char* mIpAddress;
    static const int mPort;
    static int sock;

    QThread *mThread;

public:
    Server();
    ~Server();

private:
    void acceptConnection();

signals:
    void clientConnected();
    void musicReceived();

};

#endif // SERVER_H
