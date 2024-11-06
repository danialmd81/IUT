#include "addnumber.h"
#include "ui_addnumber.h"

AddNumber::AddNumber(QWidget *parent) : QDialog(parent), ui(new Ui::AddNumber)
{
    ui->setupUi(this);
    add_num = false;
}

AddNumber::~AddNumber()
{
    delete ui;
}

void AddNumber::on_done_Button_clicked()
{
    if (ui->num_lineEdit->text().isEmpty() || ui->name_lineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "ERROR", "Field or Fields is or are Empty.", "OK");
    }
    else
    {
        name = ui->name_lineEdit->text().toStdString();
        number = ui->num_lineEdit->text().toStdString();
        add_num = true;
        accept();
    }
}

void AddNumber::on_can_Button_clicked()
{
    reject();
}

std::string AddNumber::getNumber() const
{
    return number;
}

std::string AddNumber::getName() const
{
    return name;
}

bool AddNumber::getAdd_num() const
{
    return add_num;
}
