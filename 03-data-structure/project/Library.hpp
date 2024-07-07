#pragma once
#include "AVLTree.cpp"    //for linking error in template multifiles
#include "Linkedlist.cpp" //for linking error in template multifiles
#include "Queue.cpp"      //for linking error in template multifiles
#include "User.hpp"
#include "Admin.hpp"
#include "Book.hpp"
#include "progressBar.hpp"

#include <chrono>
#include <thread>

using std::chrono::milliseconds;
using std::this_thread::sleep_for;

#define receiving_book_deadline 3   // deadline for receiving the available book for the booker // مهلت دریافت کتاب موجود برای رزرو کننده
#define loan_period_for_book 10     // Loan period for each book //مدت زمان امانت برای هر کتاب
#define penalty_for_late_delivery 5 // Penalty for late delivery of books //جریمه تاخیر در تحویل کتاب

class Library
{
private:
    int books_length, users_length;
    LinkedList<Book *> books;
    LinkedList<User *> users;
    Time time;
    Admin admin;
    User *user = nullptr;

public:
    Library(){};
    void start();
    void read();
    void write();
    template <class Archive>
    void save(Archive &archive)
    {
        archive(cereal::make_nvp("users length", users.getLength()), cereal::make_nvp("books length", books.getLength()));
    }
    template <class Archive>
    void load(Archive &archive)
    {
        archive(users_length, books_length);
    }

private:
    // user
    void user_page();
    void sign_in();
    /// @brief
    void user_option();
    void take_book_from_library(); // false return:= it will reserve book instead
    void book_time_extend_request();
    void hand_over_book();
    void my_books_list();

    Book *search(string &book_name);

    // admin
    void admin_page();
    /// @brief
    void admin_option();
    void add_book();
    bool add_book(string &title);
    void assign_existing_book_to_user();
    void take_book_from_user();
    void extend_user_time(); // if there is no booker in queue
    void user_details();

    // for both
    void add_user();
    bool add_user(string &username);
    void list_all_books();
    void sorted_list_all_books_by_name();
};
