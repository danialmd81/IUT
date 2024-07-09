#ifndef DELETEPHONE_H
#define DELETEPHONE_H

#include <QDialog>
#include <QMessageBox>

namespace Ui
{
    class DeletePhone;
}

class DeletePhone : public QDialog
{
    Q_OBJECT

public:
    explicit DeletePhone(QWidget *parent = nullptr);
    ~DeletePhone();


    bool getDeleted() const;

    QString getPhone_name() const;

private slots:
    void on_buttonBox_accepted();

    void on_pushButton_clicked();

    void on_OkButton_clicked();

    void on_CancelButton_2_clicked();

private:
    Ui::DeletePhone *ui;
    bool deleted;
    QString phone_name;
};

#endif // DELETEPHONE_H
