#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <iostream>
#include <fstream>
#include <QMessageBox>
#include <QMainWindow>
#include "register.h"
QT_BEGIN_NAMESPACE
namespace Ui
{
    class LoginWindow;
}
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_register_Button_clicked();
    void on_login_Button_clicked();

    void on_showpass_checkBox_stateChanged(int arg1);

private:
    Ui::LoginWindow *ui;
    Register *reg;
};
#endif // LOGINWINDOW_H
