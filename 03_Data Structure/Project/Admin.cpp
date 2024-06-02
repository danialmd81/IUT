#include "Admin.hpp"

using namespace std;

Admin::Admin()
{
    this->username = "admin";
    this->password = "1234";
}

bool Admin::sign_in(string username, string password)
{
    if (this->username == username && this->password == password)
        return true;
    return false;
}
