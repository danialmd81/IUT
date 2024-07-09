#ifndef SHOWSORTED_H
#define SHOWSORTED_H

#include <QMessageBox>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QStringList>
#include <QDialog>
#include <vector>
#include <string>

using namespace std;

namespace Ui
{
    class ShowSorted;
}

class ShowSorted : public QDialog
{
    Q_OBJECT

public:
    explicit ShowSorted(vector<vector<string>> list, QWidget *parent = nullptr);
    ~ShowSorted();

private slots:
    void on_pushButton_clicked();

    void on_OkButton_clicked();

private:
    Ui::ShowSorted *ui;
    QStandardItemModel *model;
};

#endif // SHOWSORTED_H
