#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include    <QFile>
#include <QFileDialog>
#include <QStringList>
#include <QJsonObject>
#include <QJsonDocument>
#include <iostream>
// #include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "phoneBook.h"
#include "contact.h"
#include "addcontact.h"
#include "editcontact.h"
#include "showsorted.h"
#include "showcontactnum.h"
#include "search.h"
#include "favorite.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_add_Button_clicked();

    void on_close_Button_clicked();

    void on_delButton_clicked();

    void on_editButton_clicked();

    void on_favButton_clicked();

    void on_show_all_sorted_Button_clicked();

    void on_contact_number_Button_clicked();

    void on_searchButton_clicked();

    void on_SaveButton_clicked();

    void on_LoadButton_clicked();

    void on_ImportButton_clicked();

    void on_ExportButton_clicked();

    void on_delConButton_clicked();

    void on_conNumConButton_clicked();

    void on_searchConButton_clicked();

private:
    PhoneBook book;
    Contact *contact;
    Ui::MainWindow *ui;
    AddContact *add;
    EditContact *edit;
    ShowSorted *show_sort;
    ShowContactNum *show_con;
    Favorite *fav;
};

#endif // MAINWINDOW_H
