#include "addcontact.h"
#include "ui_addcontact.h"

AddContact::AddContact(QWidget *parent) : QDialog(parent), ui(new Ui::AddContact)
{
    ui->setupUi(this);
    contact_added = false;
}

AddContact::~AddContact()
{
    delete ui;
}

void AddContact::on_add_number_Button_clicked()
{

    add_num = new AddNumber;
    add_num->setModal(true);
    add_num->exec();
    if (add_num->getAdd_num())
    {
        number_list.push_back(QString::fromStdString(add_num->getNumber()));
        name_list.push_back(QString::fromStdString(add_num->getName()));
    }
}

void AddContact::on_done_Button_clicked()
{
    if (ui->name_lineEdit->text().isEmpty() || ui->cell_lineEdit->text().isEmpty() || ui->work_lineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Field or Fields is or are Empty.", "OK");
    }
    else
    {
        name = ui->name_lineEdit->text();
        cell = ui->cell_lineEdit->text();
        work = ui->work_lineEdit->text();
        home = ui->home_lineEdit->text();
        contact_added = true;
        accept();
    }
}

void AddContact::on_CancelButton_clicked()
{
    reject();
}

QString AddContact::getHome() const
{
    return home;
}

QString AddContact::getWork() const
{
    return work;
}

QString AddContact::getCell() const
{
    return cell;
}

QString AddContact::getName() const
{
    return name;
}

std::vector<QString> AddContact::getNumber_list() const
{
    return number_list;
}

std::vector<QString> AddContact::getName_list() const
{
    return name_list;
}

bool AddContact::getContact_added() const
{
    return contact_added;
}
