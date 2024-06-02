#include "showsorted.h"
#include "ui_showsorted.h"

ShowSorted::ShowSorted(vector<vector<string>> list, QWidget *parent) : QDialog(parent), ui(new Ui::ShowSorted)
{
    ui->setupUi(this);
    QStringList headers;
    headers.append("Contact Name");
    headers.append("Phone");
    headers.append("Phone Number");
    model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels(headers);
    for (int contact = 0; contact < list.size(); contact++)
    {
        QStandardItem *item = new QStandardItem(QString::fromStdString(list.at(contact).at(0)));
        model->invisibleRootItem()->appendRow(item);

        for (int count = 1, i = 0; count < list.at(contact).size(); count++)
        {
            if (count % 2 == 1)
            {
                item->setChild(i, 1, new QStandardItem(QString::fromStdString(list.at(contact).at(count))));
            }
            if (count % 2 == 0)
            {
                item->setChild(i, 2, new QStandardItem(QString::fromStdString(list.at(contact).at(count))));
                i++;
            }
        }
    }

    ui->treeView->setModel(model);
}

ShowSorted::~ShowSorted()
{
    delete ui;
}

void ShowSorted::on_pushButton_clicked()
{
    accept();
}

void ShowSorted::on_OkButton_clicked()
{
    accept();
}
