#ifndef EDITPHONENAME_H
#define EDITPHONENAME_H

#include <QDialog>
#include <QMessageBox>

namespace Ui
{
    class EditPhoneName;
}

class EditPhoneName : public QDialog
{
    Q_OBJECT

public:
    explicit EditPhoneName(QWidget *parent = nullptr);
    ~EditPhoneName();

    std::string getPhone_name() const;

    std::string getNew_phone_name() const;

    bool getPhone_name_edited() const;

private slots:
    void on_ok_Button_clicked();

    void on_CancelButton_clicked();

private:
    Ui::EditPhoneName *ui;
    std::string Phone_name, new_phone_name;
    bool phone_name_edited;
};

#endif // EDITPHONENAME_H
