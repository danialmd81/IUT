#ifndef ADDNUMBER_H
#define ADDNUMBER_H

#include <QDialog>
#include <string>
#include <qmessagebox.h>

namespace Ui
{
    class AddNumber;
}

class AddNumber : public QDialog
{
    Q_OBJECT

public:
    explicit AddNumber(QWidget *parent = nullptr);
    ~AddNumber();

    bool getAdd_num() const;

    std::string getName() const;

    std::string getNumber() const;

private slots:
    void on_done_Button_clicked();

    void on_can_Button_clicked();

private:
    Ui::AddNumber *ui;

    bool add_num;

    std::string name, number;
};

#endif // ADDNUMBER_H
