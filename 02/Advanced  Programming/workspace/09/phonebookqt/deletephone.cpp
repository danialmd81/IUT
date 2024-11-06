#include "deletephone.h"
#include "ui_deletephone.h"

DeletePhone::DeletePhone(QWidget *parent) : QDialog(parent), ui(new Ui::DeletePhone)
{
    ui->setupUi(this);
    deleted = false;
}

DeletePhone::~DeletePhone()
{
    delete ui;
}

void DeletePhone::on_buttonBox_accepted()
{
    close();
}

void DeletePhone::on_pushButton_clicked()
{
    close();
}

void DeletePhone::on_OkButton_clicked()
{
    if (ui->lineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Phone name is empty.");
    }
    else
    {
        phone_name = ui->lineEdit->text();
        deleted = true;
        accept();
    }
}

void DeletePhone::on_CancelButton_2_clicked()
{
    reject();
}

QString DeletePhone::getPhone_name() const
{
    return phone_name;
}

bool DeletePhone::getDeleted() const
{
    return deleted;
}
