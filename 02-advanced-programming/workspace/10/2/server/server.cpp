#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent) : QMainWindow(parent), ui(new Ui::Server)
{
    ui->setupUi(this);
    server = new QTcpServer();

    if (server->listen(QHostAddress::Any, 8080))
    {
        connect(server, &QTcpServer::newConnection, this, &Server::newConnection);
        connect(this, &Server::newMessage, this, &Server::displayMessage);
        ui->statusbar->showMessage("Server is listening...");
    }
    else
    {
        QMessageBox::critical(this, "QTCPServer",
                              QString("Unable to start the server: %1.").arg(server->errorString()));
        exit(EXIT_FAILURE);
    }
}

Server::~Server()
{
    foreach (QTcpSocket *socket, socket_set)
    {
        socket->close();
        socket->deleteLater();
    }
    foreach (std::thread *thr_p, thread_set)
    {
        delete thr_p;
    }
    server->close();
    server->deleteLater();

    delete ui;
}

void Server::newConnection()
{
    while (server->hasPendingConnections())
    {
        thr = new std::thread([&]() { appendToSocketList(server->nextPendingConnection()); });
        thr->join();
        thread_set.insert(thr);
        //        appendToSocketList(server->nextPendingConnection());
    }
}

void Server::appendToSocketList(QTcpSocket *socket)
{
    socket_set.insert(socket);
    connect(socket, &QTcpSocket::readyRead, this, &Server::readSocket);
    connect(socket, &QTcpSocket::disconnected, this, &Server::discardSocket);
    connect(socket, SIGNAL(QTcpSocket::error(QAbstractSocket::SocketError)), this, SLOT(MainWindow::displayError));
    ui->sendBox->addItem(QString::number(socket->socketDescriptor()));
    displayMessage(
        QString("INFO :: Client with socket id:%1 has just entered the room").arg(socket->socketDescriptor()));
}

void Server::readSocket()
{
    QTcpSocket *socket = reinterpret_cast<QTcpSocket *>(sender());
    QByteArray buffer;
    QDataStream socketStream(socket);
    socketStream.startTransaction();
    socketStream >> buffer;
    if (!socketStream.commitTransaction())
    {
        QString message = QString("%1 :: Waiting for more data to come..").arg(socket->socketDescriptor());
        emit newMessage(message);
        return;
    }
    buffer = buffer.mid(128);
    QString message =
        QString("%1 :: %2").arg(socket->socketDescriptor()).arg(QString::fromStdString(buffer.toStdString()));
    sendMessage(socket, "message recived.");
    emit newMessage(message);
}

void Server::discardSocket()
{
    QTcpSocket *socket = reinterpret_cast<QTcpSocket *>(sender());
    QSet<QTcpSocket *>::iterator it = socket_set.find(socket);
    if (it != socket_set.end())
    {
        displayMessage(QString("INFO :: A client has just left the room").arg(socket->socketDescriptor()));
        socket_set.remove(*it);
    }
    refreshComboBox();

    socket->deleteLater();
}

void Server::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError)
    {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, "QTCPServer",
                                 "The host was not found. Please check the host name and port settings.");
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, "QTCPServer",
                                 "The connection was refused by the peer. Make sure QTCPServer is running, and check "
                                 "that the host name and port settings are correct.");
        break;
    default:
        QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
        QMessageBox::information(this, "QTCPServer",
                                 QString("The following error occurred: %1.").arg(socket->errorString()));
        break;
    }
}

void Server::on_sendButton_clicked()
{
    QString receiver = ui->sendBox->currentText();
    if (receiver == "All")
    {
        foreach (QTcpSocket *socket, socket_set)
        {
            sendMessage(socket);
        }
    }
    else
    {
        foreach (QTcpSocket *socket, socket_set)
        {
            if (socket->socketDescriptor() == receiver.toLongLong())
            {
                sendMessage(socket);
                break;
            }
        }
    }
    ui->messageEdit->clear();
}

void Server::sendMessage(QTcpSocket *socket, QString str)
{
    if (socket)
    {
        if (socket->isOpen())
        {
            str += ui->messageEdit->text();
            QDataStream socketStream(socket);
            QByteArray header;
            header.prepend(QString("fileType:message,fileName:null,fileSize:%1;").arg(str.size()).toUtf8());
            header.resize(128);
            QByteArray byteArray = str.toUtf8();
            byteArray.prepend(header);
            socketStream << byteArray;
        }
        else
            QMessageBox::critical(this, "QTCPServer", "Socket doesn't seem to be opened");
    }
    else
        QMessageBox::critical(this, "QTCPServer", "Not connected");
}

void Server::displayMessage(const QString &str)
{
    ui->messageBrowser->append(str);
}

void Server::refreshComboBox()
{
    ui->sendBox->clear();
    ui->sendBox->addItem("All");
    foreach (QTcpSocket *socket, socket_set)
        ui->sendBox->addItem(QString::number(socket->socketDescriptor()));
}
