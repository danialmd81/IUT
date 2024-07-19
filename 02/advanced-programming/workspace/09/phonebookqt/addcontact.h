#ifndef ADDCONTACT_H
#define ADDCONTACT_H

#include <QDialog>
#include <QMessageBox>
#include "phoneBook.h"
#include "contact.h"
#include <iostream>
#include <vector>
#include "addnumber.h"

namespace Ui
{
    class AddContact;
}

class AddContact : public QDialog
{
    Q_OBJECT

public:
    explicit AddContact(QWidget *parent = nullptr);

    ~AddContact();

    bool getContact_added() const;

    std::vector<QString> getName_list() const;

    std::vector<QString> getNumber_list() const;

    QString getName() const;

    QString getCell() const;

    QString getWork() const;

    QString getHome() const;

private slots:
    void on_add_number_Button_clicked();

    void on_done_Button_clicked();

    void on_CancelButton_clicked();

private:
    PhoneBook *book;

    Ui::AddContact *ui;

    AddNumber *add_num;

    bool contact_added;

    std::vector<QString> name_list;

    std::vector<QString> number_list;

    QString name, cell, work, home;
};

#endif // ADDCONTACT_H
