
#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) : QDialog(parent), ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::WriteFile()
{
    std::ofstream out_file;
    std::string name = user.username.toStdString() + ".txt";
    out_file.open(name);
    if (out_file.is_open())
    {
        out_file << user;
        out_file.close();
    }
    else
    {
    }
}

void Register::on_register_Button_clicked()
{
    if (ui->age_lineEdit->text().size() == 0 || ui->name_lineEdit->text().size() == 0 ||
        ui->fam_lineEdit->text().size() == 0 || ui->user_lineEdit->text().size() == 0 ||
        ui->pass_lineEdit->text().size() == 0 || ui->ema_lineEdit->text().size() == 0 ||
        !ui->male_checkBox->isChecked() && !ui->female_checkBox->isChecked() ||
        ui->male_checkBox->isChecked() && ui->female_checkBox->isChecked())
    {
        QMessageBox::warning(this, "ERROR", "Field or Fields is or are Empty.");
    }
    else
    {
        user.name = ui->name_lineEdit->text();
        user.family_name = ui->fam_lineEdit->text();
        user.username = ui->user_lineEdit->text();
        user.password = ui->pass_lineEdit->text();
        user.age = ui->age_lineEdit->text();
        user.email = ui->ema_lineEdit->text();
        if (ui->male_checkBox->isChecked())
            user.gender = "Male";
        if (ui->female_checkBox->isChecked())
            user.gender = "Female";
        std::ifstream check_file;
        std::string name = user.username.toStdString() + ".txt";
        check_file.open(name);
        if (check_file.is_open())
        {
            QMessageBox::warning(this, "ERROR", "Username had been taken.");
        }
        else
        {
            WriteFile();
            this->hide();
        }
    }
}

void Register::on_cancel_Button_clicked()
{
    this->hide();
}
