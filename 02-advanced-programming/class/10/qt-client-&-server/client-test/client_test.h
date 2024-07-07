#ifndef CLIENT_TEST_H
#define CLIENT_TEST_H
#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QAbstractSocket>

class client_test : public QObject
{
    Q_OBJECT
public:
    explicit client_test(QObject *parent = nullptr);
    void test();
signals:
public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();
private: QTcpSocket *socket;
};

#endif // CLIENT_TEST_H
