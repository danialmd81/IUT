#include "showcontactnum.h"
#include "ui_showcontactnum.h"

ShowContactNum::ShowContactNum(std::vector<std::string> list, QWidget *parent) : QDialog(parent), ui(new Ui::ShowContactNum)
{
    ui->setupUi(this);
    QStringList headers;
    headers.append("Contact Name");
    headers.append("Phone");
    headers.append("Phone Number");
    model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels(headers);
    QStandardItem *item = new QStandardItem(QString::fromStdString(list.at(0)));
    model->invisibleRootItem()->appendRow(item);
    for (int count = 1, i = 0; count < list.size(); count++)
    {

        if (count % 2 == 1)
        {
            item->setChild(i, 1, new QStandardItem(QString::fromStdString(list.at(count))));
        }
        if (count % 2 == 0)
        {
            item->setChild(i, 2, new QStandardItem(QString::fromStdString(list.at(count))));
            i++;
        }
    }
    ui->treeView->setModel(model);

/////////////////////////////////////////////////////////////////////////////////
    // Dialog::init()
    //     {
    //         QStringList headers;
    //         headers.append("Name");
    //         headers.append("Value");
    //         model.setHorizontalHeaderLabels(headers);
    //         ui->treeView->setModel(&model);
    //         foreach (QFileInfo info, list)
    //         {
    //             if (info.isFile())
    //             {
    //                 addFile(model.invisibleRootItem(), info);
    //             }
    //         }
    //     }

    // QStandardItem *item = new QStandardItem(info.fileName());
    // root->appendRow(item);

    // item->setChild(0,0, new QStandardItem("Size"));
    // item->setChild(0,1, new QStandardItem(QString::number(info.size())));

    // item->setChild(1,0, new QStandardItem("Created"));
    // item->setChild(1,1, new QStandardItem(info.birthTime().toString()));

    // item->setChild(2,0, new QStandardItem("Modified"));
    // item->setChild(2,1, new QStandardItem(info.lastModified().toString()));

    // item->setChild(3,0, new QStandardItem("Accessed"));
    // item->setChild(3,1, new QStandardItem(info.lastRead().toString()));

    // item->setChild(4,0, new QStandardItem("Readable"));
    // item->setChild(4,1, new QStandardItem(info.isReadable() ? "Yes" : "No"));

    // item->setChild(5,0, new QStandardItem("Writable"));
    // item->setChild(5,1, new QStandardItem(info.isWritable() ? "Yes" : "No"));

    // item->setChild(6,0, new QStandardItem("Path"));
    // item->setChild(6,1, new QStandardItem(info.path()));
}

ShowContactNum::~ShowContactNum()
{
    delete ui;
}

void ShowContactNum::on_OkButton_clicked()
{
    accept();
}
