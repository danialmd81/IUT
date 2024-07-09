#include <iostream>
#include <map>
#include <vector>
#include "DontFind.h"

using namespace std;

class Contact
{
private:
    map<string, string> contact;
    DontFind dont;

public:
    Contact(const string &cell = "", const string &work = "", const string &home = "")
    {
        contact["CELL"] = cell;
        contact["WORK"] = work;
        contact["HOME"] = home;
    }
    void AddPhone(const string &name, const string &namePhone)
    {
        contact[name] = namePhone;
    }
    void DeletePhone(const string &name)
    {
        contact.erase(name);
    }
    void EditPhoneName(const string &name, const string &newNamePhone)
    {

        auto node = contact.extract(name);
        if (node.empty())
            // throw d;
            cout << dont.what();
        node.key() = newNamePhone;
        contact.insert(move(node));
    }
    void EditPhoneNumber(const string &name, const string &namePhone)
    {
        auto node = contact.extract(name);
        if (node.empty())
            cout << dont.what();
        node.mapped() = namePhone;
        contact.insert(move(node));
    }
    void showContact()
    {
        for (auto &&i : contact)
        {
            cout << i.first << ':' << i.second << '\n';
        }
    }
    void showContact(vector<string> *list)
    {
        for (auto &&i : contact)
        {
            list->push_back(i.first);
            list->push_back(i.second);
        }
    }
};
