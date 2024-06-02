#include "changename.h"
#include "ui_changename.h"

CHangeName::CHangeName(QWidget *parent) : QDialog(parent), ui(new Ui::CHangeName)
{
    ui->setupUi(this);
    changed = false;
}

CHangeName::~CHangeName()
{
    delete ui;
}

void CHangeName::on_OkButton_clicked()
{
    if (ui->lineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Field is Empty.");
    }
    else
    {
        newName = ui->lineEdit->text();
        changed = true;
        accept();
    }
}

void CHangeName::on_CancelButton_clicked()
{
    reject();
}

bool CHangeName::getChanged() const
{
    return changed;
}

QString CHangeName::getNewName() const
{
    return newName;
}
