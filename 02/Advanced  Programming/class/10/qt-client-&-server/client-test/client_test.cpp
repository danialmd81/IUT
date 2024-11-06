#include "client_test.h"

client_test::client_test(QObject *parent)
    : QObject{parent}
{

}
void client_test::test(){
    socket  = new QTcpSocket(this);
    connect(socket,SIGNAL(connected()),this,SLOT(connected()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
    connect(socket,SIGNAL(bytesWritten(qint64)),this,SLOT(bytesWritten(qint64)));
    qDebug() << "connecting...";
    socket->connectToHost(QHostAddress::LocalHost,8080);
    if(!socket->waitForConnected(1000)){
        qDebug() << "Error: " << socket->errorString();
    }
}

void client_test::connected(){
qDebug() << "connected";
}

void client_test::disconnected(){
qDebug() << "disconnected";

}

void client_test::bytesWritten(qint64 bytes){
qDebug() << "we wrote: ";
}

void client_test::readyRead(){
qDebug() << "reading...";
qDebug() << socket->readAll();
}
