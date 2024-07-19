#include "editphonename.h"
#include "ui_editphonename.h"

EditPhoneName::EditPhoneName(QWidget *parent) : QDialog(parent),
                                                ui(new Ui::EditPhoneName)
{
    ui->setupUi(this);
    phone_name_edited = false;
}

EditPhoneName::~EditPhoneName()
{
    delete ui;
}

void EditPhoneName::on_ok_Button_clicked()
{
    if (ui->name_lineEdit->text().isEmpty() || ui->new_name_lineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Field or Fields is or are Empty.");
    }
    else
    {
        Phone_name = ui->name_lineEdit->text().toStdString();
        new_phone_name = ui->new_name_lineEdit->text().toStdString();
        phone_name_edited = true;
        accept();
    }
}

void EditPhoneName::on_CancelButton_clicked()
{
    reject();
}

bool EditPhoneName::getPhone_name_edited() const
{
    return phone_name_edited;
}

std::string EditPhoneName::getNew_phone_name() const
{
    return new_phone_name;
}

std::string EditPhoneName::getPhone_name() const
{
    return Phone_name;
}
