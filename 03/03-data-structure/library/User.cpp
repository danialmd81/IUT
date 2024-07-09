#include "User.hpp"
#include "Linkedlist.cpp" //for linking error in template multifiles

using namespace std;

string &User::name_re()
{
    return name;
}
string &User::family_name_re()
{
    return family_name;
}
string &User::ID_code_re()
{
    return ID_code;
}
string &User::username_re()
{
    return username;
}
string &User::password_re()
{
    return password;
}

LinkedList<string> &User::user_books_re()
{
    return user_books;
}

Time &User::reserve_time_re()
{
    return reserve_time;
}

int &User::penalty_re()
{
    return penalty;
}

bool User::sign_in(string username, string password)
{
    if (this->username == username && this->password == password)
        return true;
    return false;
}

void User::taking_book(string book)
{
    user_books.append(book);
    return;
}

ostream &operator<<(ostream &out, User &user)
{
    out << "name:" << user.name << endl
        << "family name:" << user.family_name << endl
        << "ID code:" << user.ID_code << endl
        << "username:" << user.username << endl
        << "password:" << user.password << endl
        << "penalty: " << user.penalty << endl
        << "user books:" << endl;
    for (int i = 0; i < user.user_books.getLength(); i++)
    {
        out << user.user_books.at(i) << endl;
    }

    return out;
}
