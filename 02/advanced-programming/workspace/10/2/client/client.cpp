#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) : QMainWindow(parent), ui(new Ui::Client)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &Client::readSocket);
    connect(this, &Client::newMessage, this, &Client::displayMessage);
    connect(socket, SIGNAL(QTcpSocket::error(QAbstractSocket::SocketError)), this, SLOT(Client::displayError));
    connect(socket, &QTcpSocket::disconnected, this, &Client::discardSocket);

    socket->connectToHost(QHostAddress::LocalHost, 8080);

    if (socket->waitForConnected())
        ui->statusbar->showMessage("Connected to Server");
    else
    {
        QMessageBox::critical(this, "QTCPClient",
                              QString("The following error occurred: %1.").arg(socket->errorString()));
        exit(EXIT_FAILURE);
    }
}

Client::~Client()
{
    if (socket->isOpen())
        socket->close();
    delete ui;
}

void Client::readSocket()
{
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
    // on_sendButton_clicked("message recived."); //for thread testing uncomment this.
    emit newMessage(message);
}

void Client::discardSocket()
{
    socket->deleteLater();
    socket = nullptr;

    ui->statusbar->showMessage("Disconnected!");
}

void Client::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError)
    {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, "QTCPClient",
                                 "The host was not found. Please check the host name and port settings.");
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, "QTCPClient",
                                 "The connection was refused by the peer. Make sure QTCPServer is running, and check "
                                 "that the host name and port settings are correct.");
        break;
    default:
        QMessageBox::information(this, "QTCPClient",
                                 QString("The following error occurred: %1.").arg(socket->errorString()));
        break;
    }
}

void Client::on_sendButton_clicked(QString str)
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
            ui->messageEdit->clear();
        }
        else
            QMessageBox::critical(this, "QTCPClient", "Socket doesn't seem to be opened");
    }
    else
        QMessageBox::critical(this, "QTCPClient", "Not connected");
}

void Client::displayMessage(const QString &str)
{
    ui->messageBrowser->append(str);
}
