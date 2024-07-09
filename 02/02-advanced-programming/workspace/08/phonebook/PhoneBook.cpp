#include "Contact.h"
#include <algorithm>
#include <vector>
#include <exception>
#include <string>
#include <cstring>

using namespace std;

class PhoneBook
{
private:
    map<string, Contact> phone_book;
    vector<string> favoriteList;
    DontFind dont;

public:
    void AddContact(const string &name, const Contact &contact)
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

    void ChangeName(const string &name, string &newName)
    {
        auto node = phone_book.extract(name);
        if (node.empty())
            // throw d;
            cout << dont.what();
        else
        {
            node.key() = newName;
            phone_book.insert(move(node));
        }
    }

    void AddPhone(const string &name, const string &name_phone, const string &name_phone_number)
    {
        auto node = phone_book.extract(name);
        if (node.empty())
            // throw d;
            cout << dont.what();
        else
        {
            node.mapped().AddPhone(name_phone, name_phone_number);
            phone_book.insert(move(node));
        }
    }

    void DeletePhone(const string &name, const string &name_phone)
    {
        auto node = phone_book.extract(name);
        if (node.empty())
            // throw d;
            cout << dont.what();
        else
        {
            node.mapped().DeletePhone(name_phone);
            phone_book.insert(move(node));
        }
    }

    void EditPhoneName(const string &name, const string &name_phone, const string &new_name_phone)
    {
        auto node = phone_book.extract(name);
        if (node.empty())
            // throw d;
            cout << dont.what();
        else
        {
            node.mapped().EditPhoneName(name_phone, new_name_phone);
            phone_book.insert(move(node));
        }
    }

    void EditPhoneNumber(const string &name, const string &name_phone, const string &name_phone_number)
    {
        auto node = phone_book.extract(name);
        if (node.empty())
            // throw d;
            cout << dont.what();
        else
        {
            node.mapped().EditPhoneName(name_phone, name_phone_number);
            phone_book.insert(move(node));
        }
    }

    void ShowAllContactNumber(const string &name)
    {
        auto it = phone_book.find(name);
        if (it == phone_book.end())
        {
            // throw d;
            cout << dont.what();
        }
        else
            it->second.showContact();
    }

    bool ShowAllContactNumber(const string &name, vector<string> *list)
    {
        auto it = phone_book.find(name);
        if (it == phone_book.end())
        {
            // throw d;
            cout << dont.what();
            return false;
        }
        else
        {
            list->push_back(name);
            it->second.showContact(list);
            return true;
        }
    }

    void ShowSorted()
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
                cout << it->first << ":\n";
                it->second.showContact();
            }
        }
        else
        {
            cout << "Phone Book Is Empty.\n";
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
            cout << dont.what();
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
            cout << dont.what();
            return false;
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
            cout << dont.what();
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

    void ShowFavorite()
    {
        for (auto &&i : favoriteList)
        {
            auto it = phone_book.find(i);
            cout << i << ":\n";
            it->second.showContact();
        }
    }

    void Search(string name)
    {
        vector<vector<string>> *list;
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
                cout << it->first << ":\n";
                it->second.showContact();
            }
            name.pop_back();
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
                cout << it->first << ":\n";
                //                it->second.showContact();
            }
            name.pop_back();
        }
    }
};
