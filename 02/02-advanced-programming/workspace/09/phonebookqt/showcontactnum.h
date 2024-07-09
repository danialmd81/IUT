#ifndef SHOWCONTACTNUM_H
#define SHOWCONTACTNUM_H

#include <QDialog>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QStringList>
#include <QDebug>
#include <vector>
#include <string>
namespace Ui
{
    class ShowContactNum;
}

class ShowContactNum : public QDialog
{
    Q_OBJECT

public:
    explicit ShowContactNum(std::vector<std::string> list, QWidget *parent = nullptr);

    ~ShowContactNum();

private slots:
    void on_OkButton_clicked();

private:
    Ui::ShowContactNum *ui;
    QStandardItemModel *model;
};

#endif // SHOWCONTACTNUM_H
