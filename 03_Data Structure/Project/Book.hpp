#pragma once
#include "Queue.hpp"
#include "Time.hpp"
#include "User.hpp"
#include <cereal/archives/json.hpp>
#include <iostream>

class Book
{
private:
    bool assigned = false;
    std::string title, genre, date_of_publication, author_name, user_who_borrowed_book;
    Time assign_time; // yyyymmddThhmmss
    Queue<User *> reserve_queue;

public:
    Book(){};
    std::string &title_re();
    std::string &genre_re();
    std::string &date_of_publication_re();
    std::string &author_name_re();
    std::string &user_who_borrowed_book_re();
    Time &assign_time_re();
    Queue<User *> &queue();
    bool &assign();
    /// @brief ///
    friend std::ostream &operator<<(std::ostream &out, Book &book);
    template <class Archive>
    void save(Archive &ar)
    {
        int length = reserve_queue.getLength();
        ar(CEREAL_NVP(title), CEREAL_NVP(genre), CEREAL_NVP(date_of_publication), CEREAL_NVP(author_name), CEREAL_NVP(user_who_borrowed_book), CEREAL_NVP(assigned), CEREAL_NVP(assign_time.to_iso_string()), cereal::make_nvp("reserve_queue length", length));
        for (int i = 0; i < length; i++)
        {
            cereal::prologue(ar, "rq");
            reserve_queue.dequeue()->save(ar);
            cereal::epilogue(ar, "rq");
        }
    }

    template <class Archive>
    void load(Archive &ar)
    {
        std::string time;
        ar(title, genre, date_of_publication, author_name, user_who_borrowed_book, assigned, time);
        if (assigned)
            assign_time.from_iso_string(time);
        int length;
        ar(length);
        for (int i = 0; i < length; i++)
        {
            cereal::prologue(ar, "rq");
            User *new_user = new User;
            new_user->load(ar);
            reserve_queue.enqueue(new_user);
            cereal::epilogue(ar, "rq");
        }
    }
};
