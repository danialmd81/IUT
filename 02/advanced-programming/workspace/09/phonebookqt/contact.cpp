#include <algorithm>
#include <vector>
#include <map>
#include <exception>
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <QStringList>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

using namespace std;

class Contact
{
public:
    Contact(const string &cell = "", const string &work = "", const string &home = "")
    {

        phone.first = "CELL";
        phone.second = cell;
        contact.push_back(phone);
        phone.first = "WORK";
        phone.second = work;
        contact.push_back(phone);
        phone.first = "HOME";
        phone.second = home;
        contact.push_back(phone);
    }

    void AddPhone(const string &name, const string &namePhone)
    {
        phone.first = name;
        phone.second = namePhone;
        contact.push_back(phone);
    }

    void DeletePhone(const string &name)
    {
        vector<pair<string, string>>::iterator err;
        for (int i = 0; i < contact.size(); i++)
        {
            if (contact[i].first == name)
            {
                err = contact.begin() + i;
                contact.erase(err);
            }
        }
    }

    bool EditPhoneName(const string &name, const string &newNamePhone)
    {
        for (int i = 0; i < contact.size(); i++)
        {
            if (contact[i].first == name)
            {
                phone.first = newNamePhone;
                phone.second = contact[i].second;
                contact[i] = phone;
                return true;
            }
        }
        return false;
    }

    bool EditPhoneNumber(const string &name, const string &namePhone)
    {
        vector<pair<string, string>>::iterator err;
        for (int i = 0; i < contact.size(); i++)
        {
            if (contact[i].first == name)
            {
                phone.first = contact[i].first;
                phone.second = namePhone;
                contact[i] = phone;
                return true;
            }
        }
        return false;
    }

    void showContact(vector<string> *list)
    {
        for (auto &&i : contact)
        {
            list->push_back(i.first);
            list->push_back(i.second);
        }
    }

    // void read(const QJsonObject &json)
    // {
    //     char name[10] = "phone";
    //     char num[10] = "num";
    //     for (char i = '0'; i < '9'; i++)
    //     {
    //         name[5] = i;
    //         num[3] = i;
    //         if (json.contains(name) && json[name].isString() && json.contains(num) && json[num].isString())
    //         {
    //             contact[json[name].toString().toStdString()] = json[num].toString().toStdString();
    //         }
    //     }
    // }
    // void write(QJsonObject &json) const
    // {
    //     QJsonArray name_list, num_list;
    //     char a = '0';
    //     char name[10] = "phone";
    //     char num[10] = "num";
    //     for (auto &&i : contact)
    //     {
    //         name[5] = a;
    //         num[3] = a;
    //         json[name] = QString::fromStdString(i.first);
    //         json[num] = QString::fromStdString(i.second);
    //         a++;
    //     }
    // }
    friend ostream &operator<<(ostream &out, Contact &c)
    {
        out << "contact:\n";
        for (auto &&i : c.contact)
        {
            out << i.first;
            out << "\n";
            out << i.second;
            out << "\n";
        }
        out << "contact end\n";
        return out;
    }

    // friend void operator>>(istream &in, Contact &c)
    // {
    //     string set_point, read, name, num;
    //     for (; getline(in, set_point) && set_point != "contact end";)
    //     {
    //         if (set_point == "contact:")
    //         {
    //             for (; set_point != "contact end" && set_point != "contact:";)
    //             {
    //                 in >> name;
    //                 in >> num;
    //                 c.AddPhone(name, num);
    //             }
    //         }
    //     }
    // }

private:
    vector<pair<string, string>> contact;
    pair<string, string> phone;
};