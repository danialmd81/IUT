#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    close();
}

void MainWindow::on_add_Button_clicked()
{
    add = new AddContact;
    add->setModal(true);
    add->exec();
    if (add->getContact_added())
    {
        contact = new Contact{add->getCell().toStdString(), add->getWork().toStdString(), add->getHome().toStdString()};
        for (int i = 0; i < add->getName_list().size(); i++)
        {
            contact->AddPhone(add->getName_list()[i].toStdString(), add->getNumber_list()[i].toStdString());
        }
        book.AddContact(add->getName().toStdString(), *contact);
    }
    delete add;
}

void MainWindow::on_delButton_clicked()
{
    if (book.DeleteContact(ui->DeletelineEdit->text().toStdString()))
    {
        QMessageBox::information(this, "Delete", "Contact Deleted.", "Ok");
    }
    else
    {
        QMessageBox::warning(this, "Delete Error", "There is no contact with this name");
    }
}

void MainWindow::on_editButton_clicked()
{
    edit = new EditContact(&book);
    edit->setModal(true);
    edit->exec();
    delete edit;
}

void MainWindow::on_favButton_clicked()
{
    fav = new Favorite(&book);
    fav->setModal(true);
    fav->exec();
    delete fav;
}

void MainWindow::on_contact_number_Button_clicked()
{
    std::vector<std::string> list;
    if (ui->NamelineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Contact NameLine is Empty.");
    }
    else
    {
        if (!book.ShowAllContactNumber(ui->NamelineEdit->text().toStdString(), &list))
        {
            QMessageBox::warning(this, "Error", "There is no contact with this name");
        }
        else
        {
            show_con = new ShowContactNum(list);
            show_con->setModal(true);
            show_con->exec();
            delete show_con;
        }
    }
}

void MainWindow::on_show_all_sorted_Button_clicked()
{
    std::vector<std::vector<std::string>> list;
    if (!book.ShowSorted(&list))
    {
        QMessageBox::warning(this, "Error", "Phone Book Is Empty.");
    }
    else
    {
        show_sort = new ShowSorted(list);
        show_sort->setModal(true);
        show_sort->exec();
        delete show_sort;
    }
}

void MainWindow::on_searchButton_clicked()
{
    if (ui->search_lineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Search Box is Empty.");
    }
    else
    {
        std::vector<std::vector<std::string>> list;
        book.Search(ui->search_lineEdit->text().toStdString(), &list);
        show_sort = new ShowSorted(list);
        show_sort->setModal(true);
        show_sort->exec();
        delete show_sort;
    }
}

void MainWindow::on_delConButton_clicked()
{
}

void MainWindow::on_conNumConButton_clicked()
{
}

void MainWindow::on_searchConButton_clicked()
{
}

void MainWindow::on_SaveButton_clicked()
{
    // ofstream file("PhoneBook.txt", ios::out | ios::trunc);
    // file << book;
    // file.close();
    // book.Saved();

    // ofstream file;
    // file.open("Phone Book.txt", ios::out | ios::trunc);
    // file.write((char *)&book, sizeof(PhoneBook));
    // file.close();

    // FILE *file = fopen("Phone Book.txt", "w+");
    // fwrite(&book, sizeof(PhoneBook), 1, file);
    // fclose(file);

    ofstream file;
    file.open("Phone Book.txt", ios::out | ios::trunc);
    file << book;
    file.close();
    QMessageBox::information(this, "Save", "Phone Book Saved.");
}

void MainWindow::on_LoadButton_clicked()
{
    // ifstream file("PhoneBook.txt", ios::in);
    // file >> book;
    // file.close();

    // book.loaded();

    // ifstream file;
    // file.open("Phone Book.txt", ios::in);
    // file.read((char *)&book, sizeof(PhoneBook));
    // file.close();

    // FILE *file = fopen("Phone Book.txt", "r");
    // fread(&book, sizeof(PhoneBook), 1, file);
    // fclose(file);

    ifstream file;
    file.open("Phone Book.txt", ios::in);
    if (file.is_open())
    {
        QMessageBox::information(this, "Load", "Phone Book Loaded");
        file >> book;
        file.close();
    }
    else
    {
        QMessageBox::warning(this, "Error", "There is No Phone Book to Load.");
    }
}

void MainWindow::on_ImportButton_clicked()
{
    QFileDialog browse;
    browse.setFileMode(QFileDialog::ExistingFile);
    browse.setAcceptMode(QFileDialog::AcceptOpen);
    QString name;
    name = browse.getOpenFileName();
    ifstream file;
    file.open(name.toStdString(), ios::in);
    if (file.is_open())
    {
        QMessageBox::information(this, "Load", "Phone Book Loaded");
        file >> book;
        file.close();
    }
    else
    {
        QMessageBox::warning(this, "Error", "There is No Phone Book to Load.");
    }
}

void MainWindow::on_ExportButton_clicked()
{
    QFileDialog browse;
    browse.setFileMode(QFileDialog::ExistingFile);
    browse.setAcceptMode(QFileDialog::AcceptSave);
    QString name;
    name = browse.getSaveFileName();
    ofstream file;
    file.open(name.toStdString(), ios::out | ios::trunc);
    file << book;
    file.close();
    QMessageBox::information(this, "Save", "Phone Book Saved.");
}

void MainWindow::on_close_Button_clicked()
{
    close();
}
