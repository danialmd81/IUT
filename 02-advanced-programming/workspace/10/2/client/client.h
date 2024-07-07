#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QHostAddress>
#include <QMainWindow>
#include <QMessageBox>
#include <QMetaType>
#include <QStandardPaths>
#include <QString>
#include <QTcpSocket>


namespace Ui
{
class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT

  public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();

  signals:
    void newMessage(QString);

  private slots:
    void readSocket();
    void discardSocket();
    void displayError(QAbstractSocket::SocketError socketError);
    void displayMessage(const QString &str);
    void on_sendButton_clicked(QString str = "");

  private:
    Ui::Client *ui;
    QTcpSocket *socket;
};

#endif // MAINWINDOW_H
