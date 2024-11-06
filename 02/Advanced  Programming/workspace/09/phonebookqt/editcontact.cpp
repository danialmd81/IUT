#include "editcontact.h"
#include "ui_editcontact.h"

EditContact::EditContact(PhoneBook *boo, QWidget *parent) : QDialog(parent), ui(new Ui::EditContact)
{
    ui->setupUi(this);
    book = boo;
}

EditContact::~EditContact()
{
    delete ui;
}

void EditContact::on_ChangeNameButton_clicked()
{
    if (ui->NamelineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Name Field is empty");
    }
    else if (ui->NewNameEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "New Name Field is empty");
    }
    else
    {
        if (book->ChangeName(ui->NamelineEdit->text().toStdString(), ui->NewNameEdit->text().toStdString()))
        {
            QMessageBox::information(this, "Edite", "Contact Name Changed.");
        }
        else
        {
            QMessageBox::warning(this, "Error", "There is No Contact With This Name.");
        }
    }
}

void EditContact::on_AddPhoneButton_clicked()
{
    if (ui->NamelineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Name Field is empty");
    }
    else
    {
        add_num = new AddNumber;
        add_num->setModal(true);
        add_num->exec();
        if (add_num->getAdd_num())
        {
            book->AddPhone(ui->NamelineEdit->text().toStdString(), add_num->getName(), add_num->getNumber());
        }
        delete add_num;
    }
}

void EditContact::on_DelPhoneButton_clicked()
{
    if (ui->NamelineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Name Field is Empty.");
    }
    else if (ui->DelEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Phone Field is Empty.");
    }
    else
    {
        if (book->DeletePhone(ui->NamelineEdit->text().toStdString(), ui->DelEdit->text().toStdString()))
        {
            QMessageBox::information(this, "Edite", "Contact Phone Deleted.");
        }
        else
        {
            QMessageBox::warning(this, "Error", "There is No Contact With This Name.");
        }
    }
}

void EditContact::on_EditPhoneNameButton_clicked()
{
    if (ui->NamelineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Name Field is empty");
    }
    else
    {
        edit_phone_name = new EditPhoneName;
        edit_phone_name->setModal(true);
        edit_phone_name->exec();
        if (edit_phone_name->getPhone_name_edited())
        {
            if (book->EditPhoneName(ui->NamelineEdit->text().toStdString(), edit_phone_name->getPhone_name(), edit_phone_name->getNew_phone_name()))
            {
                QMessageBox::information(this, "Edite", "Contact Phone Name Changed.");
            }
            else
            {
                QMessageBox::warning(this, "Error", "There is No Contact With This Name.");
            }
        }
        delete edit_phone_name;
    }
}

void EditContact::on_EditPhoneNumButton_clicked()
{
    if (ui->NamelineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Name Field is empty");
    }
    else
    {
        edit_phone_num = new EditePhoneNum;
        edit_phone_num->setModal(true);
        edit_phone_num->exec();
        if (edit_phone_num->getEdited())
        {
            if (book->EditPhoneNumber(ui->NamelineEdit->text().toStdString(), edit_phone_num->getName(), edit_phone_num->getNum()))
            {
                QMessageBox::information(this, "Edite", "Contact Phone Number Changed.");
            }
            else
            {
                QMessageBox::warning(this, "Error", "There is No Contact With This Name.");
            }
        }
        delete edit_phone_num;
    }
}

void EditContact::on_DoneButton_clicked()
{
    accept();
}

void EditContact::on_DelPhButton_clicked()
{
}

void EditContact:: on_CancelButton_clicked()
{
}
