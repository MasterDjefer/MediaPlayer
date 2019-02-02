#include "server.h"

Server::Server()
{
    WSADATA wsaData;
    int res = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (res != 0)
    {
        qDebug() << "wsadata error";
        throw -1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        qDebug() << "sock error";
        throw -1;
    }

    sockaddr_in sockAddr;
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_port = htons(32532);
    sockAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    res = bind(sock, (sockaddr*)&sockAddr, sizeof(sockAddr));
    if (res < 0)
    {
        qDebug() << "bind error";
        throw -1;
    }

    res = listen(sock, 5);
    if (res < 0)
    {
        qDebug() << "listen error";
        throw -1;
    }

    class MyThread : public QThread
    {
    private:
        Server* mParent;

    public:
        MyThread(Server* server) : mParent(server)
        {
        }

        virtual void run() override
        {
            mParent->acceptConnection();
        }
    };

    mThread = new MyThread(this);
    mThread->start();

//    std::thread socketThread(acceptConnection);
    //    socketThread.detach();
}

Server::~Server()
{
    mThread->terminate();
    closesocket(sock);
    delete mThread;
}

void Server::acceptConnection()
{
    while (true)
    {
        qDebug() << "waiting...";
        int clientSock = accept(sock, NULL, NULL);
        emit clientConnected();
        qDebug() << "connected!";




        char buffer[100000];
        int size = sizeof(buffer);
        memset(buffer, 0, size);

        char msgReceive[] = "receiving\0";
        char msgSent[] = "sent\0";
        char msgClose[] = "close\0";
        char msgPlay[] = "play\0";
        char msgPause[] = "pause\0";
        char msgRewindLeft[] = "left\0";
        char msgRewindRight[] = "right\0";
        char msgVolumeUp[] = "volumeUp\0";
        char msgVolumeDown[] = "volumeDown\0";

        FILE* file;
        static bool flag = true;

        while (true)
        {
            int res = recv(clientSock, buffer, size, 0);

            char receivedCommand[200];
            memset(receivedCommand, 0, 200);
            memcpy(receivedCommand, buffer, res);
            qDebug() << receivedCommand;

            if (!memcmp(buffer, msgReceive, strlen(msgReceive)))
            {
                if (flag)
                {
                    file = fopen("D:/music1.mp3", "wb");
                }
                else
                {
                    file = fopen("D:/music2.mp3", "wb");
                }
                flag = !flag;

                while (true)
                {
                    memset(buffer, 0, size);
                    res = recv(clientSock, buffer, size, 0);
                    if (!memcmp(buffer + res - 4, msgSent, strlen(msgSent)))
                    {
                        memset(buffer + res - 4, 0, 4);
                        res -= 4;
                        qDebug() << "wrote " << res << " bytes";
                        fwrite(buffer,res, 1,file);

                        qDebug() << "received";
                        fclose(file);
                        emit musicReceived();
                        break;
                    }

                    qDebug() << "wrote " << res << " bytes";
                    fwrite(buffer,res, 1,file);
                }
            } else
            if (!memcmp(buffer, msgClose, strlen(msgClose)))
            {
                closesocket(clientSock);
                break;
            } else
            if (!memcmp(buffer, msgPlay, strlen(msgPlay)))
            {
                emit musicPlay();
            }else
            if (!memcmp(buffer, msgPause, strlen(msgPause)))
            {
                emit musicPause();
            } else
            if (!memcmp(buffer, msgRewindLeft, strlen(msgRewindLeft)))
            {
                emit musicRewindLeft();
            } else
            if (!memcmp(buffer, msgRewindRight, strlen(msgRewindRight)))
            {
                emit musicRewindRight();
            }
            else
            if (!memcmp(buffer, msgVolumeUp, strlen(msgVolumeUp)))
            {
                emit musicVolumeUp();
            }
            else
            if (!memcmp(buffer, msgVolumeDown, strlen(msgVolumeDown)))
            {
                emit musicVolumeDown();
            }
        }
    }
}

int Server::sock = -1;
