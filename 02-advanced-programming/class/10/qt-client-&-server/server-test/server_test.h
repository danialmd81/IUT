#ifndef SERVER_TEST_H
#define SERVER_TEST_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

class server_test : public QObject
{
    Q_OBJECT
public:
    explicit server_test(QObject *parent = nullptr);
signals:

public slots:
    void newConnection();
private:
    QTcpServer *server;

};

#endif // SERVER_TEST_H
