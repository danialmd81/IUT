#ifndef EDITEPHONENUM_H
#define EDITEPHONENUM_H

#include <QDialog>
#include <QMessageBox>

namespace Ui
{
    class EditePhoneNum;
}

class EditePhoneNum : public QDialog
{
    Q_OBJECT

public:
    explicit EditePhoneNum(QWidget *parent = nullptr);
    ~EditePhoneNum();

    bool getEdited() const;

    std::string getName() const;

    std::string getNum() const;

private slots:
    void on_ok_Button_clicked();

    void on_cancel_Button_clicked();

private:
    Ui::EditePhoneNum *ui;
    bool edited;
    std::string name, num;
};

#endif // EDITEPHONENUM_H
