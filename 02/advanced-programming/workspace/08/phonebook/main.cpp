#include "PhoneBook.h"
#include <iostream>

using namespace std;

int main()
{
    try
    {
        PhoneBook book;
        Contact *contact;
        string name, newName, cell, work, home, name_phone, new_name_phone, name_phone_number;
        int position;
        char input;
        while (input != '!')
        {
            cout << "Phone Book:\n"
                 << "1_Add Contact.\n"                       // Done
                 << "2_Delete Contact.\n"                    // Done
                 << "3_Edit Contact:\n"                      // Done
                 << "4_Favorite:\n"                          // Done
                 << "5_Show All Contacts In Sorted Order.\n" // Done
                 << "6_Show All Contact's Number.\n"         // Done
                 << "7_Search.\n"                            // Done
                 << "!END.\n";
            cin >> input;
            switch (input)
            {
            case '1':
                cout << "Name:";
                cin >> name;
                cout << "Cell:";
                cin >> cell;
                cout << "Work:";
                cin >> work;
                cout << "Home:";
                cin >> home;
                contact = new Contact{cell, work, home};
                while (1)
                {
                    cout << "@_RETURN.\n";
                    cout << "Name Phone:";
                    cin >> name_phone;
                    if (name_phone == "@")
                    {
                        break;
                    }
                    cout << name_phone << ":";
                    cin >> name_phone_number;
                    contact->AddPhone(name_phone, name_phone_number);
                }
                book.AddContact(name, *contact);
                break;
            case '2':
                cout << "Name:";
                cin >> name;
                book.DeleteContact(name);
                break;
            case '3':
                cout << "Edit:\n"
                     << "Name:";
                cin >> name;
                cout << "1_Change Name.\n"
                     << "2_Add Phone.\n"
                     << "3_Delete phone.\n"
                     << "4_Edit Phone Name:\n"
                     << "5_Edit Phone Number.\n"
                     << "@_RETURN.\n";
                cin >> input;
                switch (input)
                {
                case '1':
                    cout << "New Name:";
                    cin >> newName;
                    book.ChangeName(name, newName);
                    break;
                case '2':
                    while (1)
                    {
                        cout << "@_RETURN.\n";
                        cout << "Name Phone:";
                        cin >> name_phone;
                        if (name_phone == "@")
                        {
                            break;
                        }
                        cout << name_phone << ":";
                        cin >> name_phone_number;
                        book.AddPhone(name, name_phone, name_phone_number);
                    }
                    break;
                case '3':
                    cout << "Name Phone:";
                    cin >> name_phone;
                    book.DeletePhone(name, name_phone);
                    break;
                case '4':
                    cout << "Name Phone:";
                    cin >> name_phone;
                    cout << "New Name Phone:";
                    cin >> new_name_phone;
                    book.EditPhoneName(name, name_phone, new_name_phone);
                    break;
                case '5':
                    cout << "Name Phone:";
                    cin >> name_phone;
                    cout << name_phone << ":";
                    cin >> name_phone_number;
                    book.EditPhoneNumber(name, name_phone, name_phone_number);
                    break;
                case '@':
                    break;
                default:
                    cout << "Choose Corectly.\n";
                    break;
                }
                break;
            case '4':
                cout << "Favorite:\n"
                     << "1_Add Contact To Favorite List.\n"
                     << "2_Delete Contact From Favorite List.\n"
                     << "3_Edit Contact Order In Favorite List.\n"
                     << "4_Show Favorite List.\n"
                     << "@RETURN.\n";
                cin >> input;
                switch (input)
                {
                case '1':
                    cout << "Name:";
                    cin >> name;
                    book.AddFavorite(name);
                    break;
                case '2':
                    cout << "Name:";
                    cin >> name;
                    book.DeleteFavorite(name);
                    break;
                case '3':
                    cout << "Name:";
                    cin >> name;
                    cout << "Position:";
                    cin >> position;
                    book.FavoriteOrder(name, position);
                    break;
                case '4':
                    book.ShowFavorite();
                    break;
                case '@':
                    break;
                default:
                    cout << "Choose Corectly.\n";
                    break;
                }
                break;
            case '5':
                book.ShowSorted();
                break;
            case '6':
                cout << "Name:";
                cin >> name;
                book.ShowAllContactNumber(name);
                break;
            case '7':
                cout << "Name:";
                cin >> name;
                book.Search(name);
                break;
            case '!':
                break;
            default:
                cout << "Choose Corectly.\n";
                break;
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what();
    }
}
