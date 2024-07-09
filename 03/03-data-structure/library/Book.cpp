#include "Book.hpp"
#include "Queue.cpp" //for linking error in template multifiles

using namespace std;

string &Book::title_re()
{
    return title;
}
string &Book::genre_re()
{
    return genre;
}

string &Book::date_of_publication_re()
{
    return date_of_publication;
}
string &Book::author_name_re()
{
    return author_name;
}

string &Book::user_who_borrowed_book_re()
{
    return user_who_borrowed_book;
}

bool &Book::assign()
{
    return assigned;
}

Time &Book::assign_time_re()
{
    return assign_time;
}

ostream &operator<<(ostream &out, Book &book)
{
    out << "Title:" << book.title << endl
        << "Genre:" << book.genre << endl
        << "Date of Publication:" << book.date_of_publication << endl
        << "Author Name:" << book.author_name << endl;
    if (book.assigned)
    {
        out << book.assign_time_re().to_string() << endl;
    }

    return out;
}

Queue<User *> &Book::queue()
{
    return reserve_queue;
}
