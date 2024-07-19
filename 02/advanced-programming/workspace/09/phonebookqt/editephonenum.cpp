#include "editephonenum.h"
#include "ui_editephonenum.h"

EditePhoneNum::EditePhoneNum(QWidget *parent) : QDialog(parent),
                                                ui(new Ui::EditePhoneNum)
{
    ui->setupUi(this);
    edited = false;
}

EditePhoneNum::~EditePhoneNum()
{
    delete ui;
}

void EditePhoneNum::on_ok_Button_clicked()
{
    if (ui->name_lineEdit->text().isEmpty() || ui->number_lineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Field or Fields is or are Empty.");
    }
    else
    {
        name = ui->name_lineEdit->text().toStdString();
        num = ui->number_lineEdit->text().toStdString();
        edited = true;
        accept();
    }
}

void EditePhoneNum::on_cancel_Button_clicked()
{
    reject();
}

std::string EditePhoneNum::getNum() const
{
    return num;
}

std::string EditePhoneNum::getName() const
{
    return name;
}

bool EditePhoneNum::getEdited() const
{
    return edited;
}
