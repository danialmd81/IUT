#include "server_test.h"

server_test::server_test(QObject *parent)
    : QObject{parent}
{
    server = new QTcpServer(this);

    connect(server,SIGNAL(newConnection()),
            this,SLOT(newConnection()));

    if(!server->listen(QHostAddress::LocalHost,8080)){
        qDebug() << "Server Could Not Start!";
    }
    else{
        qDebug() << "Server Started!";
    }
}

void server_test::newConnection(){
    QTcpSocket *socket = server->nextPendingConnection();
    socket->write("hello client");
    socket->flush();
    socket->waitForBytesWritten(3000);
    socket->close();

}
