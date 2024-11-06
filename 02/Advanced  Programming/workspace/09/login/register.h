#ifndef REGISTER_H
#define REGISTER_H
#include <QDialog>
#include <fstream>
#include <QMessageBox>
#include "users.h"

namespace Ui
{
    class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    void WriteFile();
    ~Register();

private slots:
    void on_register_Button_clicked();

    void on_cancel_Button_clicked();

    void on_male_checkBox_stateChanged(int arg1);

private:
    Ui::Register *ui;
    Users user;
};

#endif // REGISTER_H
