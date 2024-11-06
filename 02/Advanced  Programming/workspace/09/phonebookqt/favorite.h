#ifndef FAVORITE_H
#define FAVORITE_H

#include <QDialog>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QStringList>
#include "phoneBook.h"
#include "contact.h"
#include "showsorted.h"

namespace Ui
{
    class Favorite;
}

class Favorite : public QDialog
{
    Q_OBJECT

public:
    explicit Favorite(PhoneBook *boo, QWidget *parent = nullptr);
    ~Favorite();

private slots:
    void on_addButton_clicked();

    void on_delButton_clicked();

    void on_editButton_clicked();

    void on_showButton_clicked();

    void on_DoneButton_clicked();

    void on_PositionSpinBox_valueChanged(int arg1);

private:
    Ui::Favorite *ui;
    QStandardItemModel *model;
    PhoneBook *book;
    ShowSorted *show;
    std::string Name;
    int position;
};

#endif // FAVORITE_H
