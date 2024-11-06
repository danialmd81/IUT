#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
    delete reg;
}

void LoginWindow::on_register_Button_clicked()
{
    Register regi;
    regi.setModal(true);
    regi.exec();
    // this->hide();
    // reg = new Register(this);
}

void LoginWindow::on_login_Button_clicked()
{
    QString username = ui->user_lineEdit->text();
    QString password = ui->pass_lineEdit->text();
    std::string name = username.toStdString() + ".txt";
    std::ifstream input_file;
    input_file.open(name);
    if (input_file.is_open())
    {
        char c = input_file.get();
        std::string input;
        for (; c != '\n'; c = input_file.get())
        {
            input.push_back(c);
        }
        if (password.toStdString() == input)
        {
            QMessageBox::information(this, "Correct", "Username and Password are Correct.");
            this->close();
        }
        else
        {
            QMessageBox::warning(this, "ERROR", "Password is Incorrect.");
        }
    }
    else
    {
        QMessageBox::warning(this, "ERROR", "Username does not Exist.");
    }
}

void LoginWindow::on_showpass_checkBox_stateChanged(int arg1)
{
    if (arg1)
    {
        QLineEdit::EchoMode a = QLineEdit::EchoMode::Normal;
        ui->pass_lineEdit->setEchoMode(a);
    }
    else
    {
        QLineEdit::EchoMode a = QLineEdit::EchoMode::Password;
        ui->pass_lineEdit->setEchoMode(a);
    }
}
