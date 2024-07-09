#ifndef CHANGENAME_H
#define CHANGENAME_H

#include <QDialog>
#include <QMessageBox>

namespace Ui
{
    class CHangeName;
}

class CHangeName : public QDialog
{
    Q_OBJECT

public:
    explicit CHangeName(QWidget *parent = nullptr);
    ~CHangeName();


    QString getNewName() const;

    bool getChanged() const;

private slots:
    void on_OkButton_clicked();

    void on_CancelButton_clicked();

private:
    Ui::CHangeName *ui;
    QString newName;
    bool changed;
};

#endif // CHANGENAME_H
