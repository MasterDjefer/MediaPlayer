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
    sockAddr.sin_port = htons(mPort);
    sockAddr.sin_addr.s_addr = (inet_addr(mIpAddress));

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

        if (sock < 0)
        {
            qDebug() << "client sock error";
            throw -1;
        }

        FILE* file;
        static bool flag = true;
        if (flag)
        {
            file = fopen("D:/music1.mp3", "wb");
        }
        else
        {
            file = fopen("D:/music2.mp3", "wb");
        }
        flag = !flag;

        char buffer[100000];
        int size = sizeof(buffer);
        memset(buffer, 0, size);

        while (true)
        {
            int res = recv(clientSock, buffer, size, 0);
            if (res <= 0)
            {
                qDebug() << "disconnect";
                fclose(file);
                closesocket(clientSock);
                emit musicReceived();
                break;
            }

//            qDebug() << "wrote " << res << " bytes";
            fwrite(buffer,res, 1,file);
            memset(buffer, 0, size);
        }
    }
}

const char* Server::mIpAddress = "192.168.1.131";
const int Server::mPort = 12345;
int Server::sock = -1;
