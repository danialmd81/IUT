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
#include "contact.h"

using namespace std;

class PhoneBook
{
public:
    bool AddContact(const string &name, const Contact &contact)
    {
        phone_book[name] = contact;
    }

    bool DeleteContact(const string &name)
    {
        auto it = phone_book.find(name);
        if (it == phone_book.end())
        {
            // throw d;
            // cout << dont.what();
            return false;
        }
        else
        {
            phone_book.erase(name);
            return true;
        }
    }

    bool ChangeName(const string name, string newName)
    {
        auto node = phone_book.extract(name);
        if (node.empty())
        {
            // throw d;
            // cout << dont.what();
            return false;
        }

        else
        {
            node.key() = newName;
            phone_book.insert(move(node));
            return true;
        }
    }

    bool AddPhone(const string &name, const string &name_phone, const string &name_phone_number)
    {
        auto node = phone_book.extract(name);
        if (node.empty())
        {
            return false;
            // throw d;
            // cout << dont.what();
        }

        else
        {
            node.mapped().AddPhone(name_phone, name_phone_number);
            phone_book.insert(move(node));
            return true;
        }
    }

    bool DeletePhone(const string &name, const string &name_phone)
    {
        auto node = phone_book.extract(name);
        if (node.empty())
        {
            // throw d;
            // cout << dont.what();
            return false;
        }

        else
        {
            node.mapped().DeletePhone(name_phone);
            phone_book.insert(move(node));
            return true;
        }
    }

    bool EditPhoneName(const string &name, const string &name_phone, const string &new_name_phone)
    {
        auto node = phone_book.extract(name);
        if (node.empty())
        {
            // throw d;
            // cout << dont.what();
            return false;
        }

        else
        {
            node.mapped().EditPhoneName(name_phone, new_name_phone);
            phone_book.insert(move(node));
            return true;
        }
    }

    bool EditPhoneNumber(const string &name, const string &name_phone, const string &name_phone_number)
    {
        auto node = phone_book.extract(name);
        if (node.empty())
        {
            // throw d;
            // cout << dont.what();
            return false;
        }

        else
        {
            node.mapped().EditPhoneName(name_phone, name_phone_number);
            phone_book.insert(move(node));
            return true;
        }
    }

    bool ShowAllContactNumber(const string &name, vector<string> *list)
    {
        auto it = phone_book.find(name);
        if (it == phone_book.end())
        {
            // throw d;
            // cout << dont.what();
            return false;
        }
        else
        {
            list->push_back(name);
            it->second.showContact(list);
            return true;
        }
    }

    bool ShowSorted(vector<vector<string>> *list)
    {
        vector<string> contactName;
        for (auto &&i : phone_book)
        {
            contactName.push_back(i.first);
        }
        if (!contactName.empty())
        {
            sort(contactName.begin(), contactName.end());
            for (auto &&i : contactName)
            {
                auto it = phone_book.find(i);
                vector<string> v;
                v.push_back(it->first);
                it->second.showContact(&v);
                list->push_back(v);
            }
            return true;
        }
        else
        {
            return false;
        }
    }

    bool AddFavorite(const string &name)
    {
        auto it = phone_book.find(name);
        if (it == phone_book.end())
        {
            // throw d;
            // cout << dont.what();
            return false;
        }

        else
        {
            favoriteList.push_back(name);
            return true;
        }
    }

    bool DeleteFavorite(const string &name)
    {
        auto it = find(favoriteList.begin(), favoriteList.end(), name);
        if (it == favoriteList.end())
        {
            // throw d;
            // cout << dont.what();
            return true;
        }

        else
        {
            favoriteList.erase(it);
            return true;
        }
    }

    bool FavoriteOrder(const string &name, const int &pos)
    {
        int p = 0;
        for (auto &&i : favoriteList)
        {
            if (i == name)
                break;
            p++;
        }

        if (p == favoriteList.size())
        {
            // throw d;
            // cout << dont.what();
            return false;
        }

        else
        {
            string temp = favoriteList.at(pos);
            favoriteList.at(pos) = name;
            favoriteList.at(p) = temp;
            return true;
        }
    }

    bool ShowFavorite(vector<vector<string>> *list)
    {
        if (favoriteList.size() == 0)
        {
            return false;
        }
        else
        {
            for (auto &&i : favoriteList)
            {
                auto it = phone_book.find(i);
                vector<string> v;
                v.push_back(i);
                it->second.showContact(&v);
                list->push_back(v);
            }
            return true;
        }
    }

    void Search(string name, vector<vector<string>> *list)
    {
        for (; name.size() > 0;)
        {
            auto it = phone_book.find(name);
            if (it == phone_book.end())
            {
                name.pop_back();
                continue;
            }
            else
            {
                vector<string> v;
                v.push_back(it->first);
                it->second.showContact(&v);
                list->push_back(v);
            }
            name.pop_back();
        }
    }

    // void read(const QJsonObject &json)
    // {
    // }
    // void write(QJsonObject &json) const
    // {
    // }

    friend ostream &operator<<(ostream &out, PhoneBook &p)
    {
        out << "phone book:\n";
        for (auto &&i : p.phone_book)
        {
            out << i.first;
            out << "\n";
            out << i.second;
        }
        out << "phone book end\n";
        out << "favorite list:\n";
        for (auto &&i : p.favoriteList)
        {
            out << i << "\n";
        }
        out << "favorite list end\n";
        return out;
    }
    friend istream &operator>>(istream &in, PhoneBook &p)
    {
        string set_point, fav_name, phone_name, phone_num, contact_name;
        Contact contact;
        for (; getline(in, set_point) && set_point != "favorite list end";)
        {
            if (set_point == "phone book:" && getline(in, set_point))
            {
                for (; set_point != "phone book:" && set_point != "phone book end"; getline(in, set_point))
                {
                    contact_name = set_point;
                    getline(in, set_point);
                    if (set_point == "contact:" && getline(in, set_point))
                    {
                        for (; set_point != "contact:" && set_point != "contact end"; getline(in, set_point))
                        {
                            phone_name = set_point;
                            getline(in, set_point);
                            phone_num = set_point;
                            if (phone_name == "CELL")
                            {
                                contact.EditPhoneNumber(phone_name, phone_num);
                            }
                            else if (phone_name == "WORK")
                            {
                                contact.EditPhoneNumber(phone_name, phone_num);
                            }
                            else if (phone_name == "HOME")
                            {
                                contact.EditPhoneNumber(phone_name, phone_num);
                            }
                            else
                            {
                                contact.AddPhone(phone_name, phone_num);
                            }
                        }
                    }
                    p.AddContact(contact_name, contact);
                    //                    getline(in, set_point);
                }
            }
            if (set_point == "favorite list:" && getline(in, set_point))
            {
                for (; set_point != "favorite list:" && set_point != "favorite list end"; getline(in, set_point))
                {
                    fav_name = set_point;
                    p.AddFavorite(fav_name);
                }
            }
        }
        return in;
    }
    // void Saved()
    // {
    //     ofstream phone_file;
    //     phone_file.open("Phone Book.txt", ios::out | ios::trunc | ios::binary);
    //     phone_file.write((char *)this, sizeof(PhoneBook));
    //     phone_file.seekp(0, ios::beg);
    //     phone_file.close();
    // }

    // bool loaded()
    // {
    //     ifstream phone_file;
    //     phone_file.open("Phone Book.txt", ios::in | ios::binary);
    //     phone_file.read(reinterpret_cast<char *>(this), sizeof(PhoneBook));
    //     phone_file.close();
    // }

private:
    map<string, Contact> phone_book;
    vector<string> favoriteList;
};
