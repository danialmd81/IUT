#include "favorite.h"
#include "ui_favorite.h"

Favorite::Favorite(PhoneBook *boo, QWidget *parent) : QDialog(parent), ui(new Ui::Favorite)
{
    ui->setupUi(this);
    book = boo;
}

Favorite::~Favorite()
{
    delete ui;
}

void Favorite::on_addButton_clicked()
{
    if (ui->NameEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Name Field is empty");
    }
    else
    {
        if (book->AddFavorite(ui->NameEdit->text().toStdString()))
        {
            QMessageBox::information(this, "Favorite", "Contact Added to Favorite List.");
        }
        else
        {
            QMessageBox::warning(this, "Favorite Error", "There is no contact with this name");
        }
    }
}

void Favorite::on_delButton_clicked()
{
    if (ui->NameEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Name Field is empty");
    }
    else
    {
        if (book->DeleteFavorite(ui->NameEdit->text().toStdString()))
        {
            QMessageBox::information(this, "Favorite", "Contact Deleted fromFavorite List.");
        }
        else
        {
            QMessageBox::warning(this, "Favorite Error", "There is no contact with this name");
        }
    }
}

void Favorite::on_editButton_clicked()
{
    if (ui->NameEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Name Field is empty");
    }
    else
    {
        if (book->FavoriteOrder(ui->NameEdit->text().toStdString(), position))
        {
            QMessageBox::information(this, "Favorite", "Contact Order in Favorite List Changed.");
        }
        else
        {
            QMessageBox::warning(this, "Favorite Error", "There is no contact with this name");
        }
    }
}

void Favorite::on_PositionSpinBox_valueChanged(int arg1)
{
    position = arg1;
}

void Favorite::on_showButton_clicked()
{
    std::vector<std::vector<std::string>> list;
    if (book->ShowFavorite(&list))
    {
        show = new ShowSorted(list);
        show->setModal(true);
        show->exec();
        delete show;
    }
    else
    {
        QMessageBox::warning(this, "Error", "Favorite List is Empty.");
    }
}

void Favorite::on_DoneButton_clicked()
{
    accept();
}
