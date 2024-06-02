#pragma once
#include <iostream>

class Admin
{
private:
    std::string username, password;

public:
    Admin();
    bool sign_in(std::string username, std::string password);
};
