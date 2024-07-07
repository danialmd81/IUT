#pragma once
#include <iostream>
#include <cereal/archives/json.hpp>
#include "LinkedList.hpp"
#include "Time.hpp"

class User
{
private:
    std::string name, family_name, ID_code, username, password;
    LinkedList<std::string> user_books;
    int penalty = 0;
    Time reserve_time;

public:
    User(){};
    std::string &name_re();
    std::string &family_name_re();
    std::string &ID_code_re();
    std::string &username_re();
    std::string &password_re();
    LinkedList<std::string> &user_books_re();
    Time &reserve_time_re();
    int &penalty_re();

    bool sign_in(std::string username, std::string password);
    void taking_book(std::string book);
    /// @brief///
    friend std::ostream &operator<<(std::ostream &out, User &user);
    template <class Archive>
    void save(Archive &ar)
    {
        ar(CEREAL_NVP(name), CEREAL_NVP(family_name), CEREAL_NVP(ID_code), CEREAL_NVP(username), CEREAL_NVP(password), cereal::make_nvp("user books length", user_books.getLength()), CEREAL_NVP(penalty), CEREAL_NVP(reserve_time.to_iso_string()));
        for (int i = 0; i < user_books.getLength(); i++)
        {
            ar(user_books.at(i));
        }
    }
    template <class Archive>
    void load(Archive &ar)
    {
        std::string time;
        int length;
        ar(name, family_name, ID_code, username, password, length, penalty, time);
        reserve_time.from_iso_string(time);
        for (int i = 0; i < length; i++)
        {
            std::string book;
            ar(book);
            user_books.append(book);
        }
    }
};
