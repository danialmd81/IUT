#ifndef EDITCONTACT_H
#define EDITCONTACT_H

#include <QDialog>
#include <QMessageBox>
#include "phoneBook.h"
#include "contact.h"
#include "changename.h"
#include "addnumber.h"
#include "deletephone.h"
#include "editephonenum.h"
#include "editphonename.h"

namespace Ui
{
    class EditContact;
}

class EditContact : public QDialog
{
    Q_OBJECT

public:
    explicit EditContact(PhoneBook *boo, QWidget *parent = nullptr);

    ~EditContact();

private slots:
    void on_ChangeNameButton_clicked();

    void on_AddPhoneButton_clicked();

    void on_DelPhoneButton_clicked();

    void on_EditPhoneNameButton_clicked();

    void on_EditPhoneNumButton_clicked();

    void on_DoneButton_clicked();

    void on_CancelButton_clicked();

    void on_DelPhButton_clicked();



private:
    PhoneBook *book;

    Ui::EditContact *ui;

    AddNumber *add_num;

    EditePhoneNum *edit_phone_num;

    EditPhoneName *edit_phone_name;
};

#endif // EDITCONTACT_H
