#include "Library.hpp"

void Library::write()
{
    ofstream output("library.json");
    if (output.is_open())
    {
        cereal::JSONOutputArchive out(output);
        this->save(out);
        out.setNextName("users");
        out.startNode();
        for (int i = 0; i < users.getLength(); i++)
        {
            string name = "user ";
            out.setNextName((name + users.at(i)->username_re()).c_str());
            out.startNode();
            users.at(i)->save(out);
            out.finishNode();
        }
        out.finishNode();
        out.setNextName("books");
        out.startNode();
        for (int i = 0; i < books.getLength(); i++)
        {
            string name = "book ";
            out.setNextName((name + books.at(i)->title_re()).c_str());
            out.startNode();
            books.at(i)->save(out);
            out.finishNode();
        }
        out.finishNode();
        out.finishNode();
        output.close();
    }
}

void Library::read()
{
    ifstream input("library.json");
    if (input.is_open())
    {
        cereal::JSONInputArchive in(input);
        this->load(in);
        in.startNode();
        for (int i = 0; i < users_length; i++)
        {
            in.startNode();
            User *new_user = new User;
            new_user->load(in);
            users.append(new_user);
            in.finishNode();
        }
        in.finishNode();
        in.startNode();
        for (int i = 0; i < books_length; i++)
        {
            in.startNode();
            Book *new_book = new Book;
            new_book->load(in);
            books.append(new_book);
            in.finishNode();
        }
        in.finishNode();
        in.finishNode();
        input.close();
    }
}

void Library::start()
{
label:
    try
    {
        system("cls");
        string input;
        cout << "\033[1;32m"
             << "|IUT Library System|"
             << "\033[0m" << endl;
        cout << " 1_Admin\n 2_User\n 3_Exit\n"
             << ">>";
        cin >> input;
        if (input == "1" || input == "Admin")
        {
            return admin_page();
        }
        else if (input == "2" || input == "User")
        {
            return user_page();
        }
        else if (input == "3" || input == "Exit")
        {
            return;
        }
        else
        {
            cout << "\033[1;31m"
                 << "Invalid Input"
                 << "\033[0m";
            sleep_for(milliseconds(800));
            return start();
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        sleep_for(milliseconds(800));
        goto label;
    }
}

///@brief///

void Library::admin_page()
{
    system("cls");
    string username, password;
    cout << "\033[1;32m"
         << "|Login Admin|"
         << "\033[0m" << endl
         << "\033[0;36m"
         << "Username:"
         << "\033[0m";
    cin >> username;
    if (username == "0")
    {
        return start();
    }
    cout << "\033[0;36m"
         << "Password:"
         << "\033[0m";
    cin >> password;
    if (admin.sign_in(username, password))
    {
        cout << "\033[0;32m"
             << "Welcome Admin"
             << "\033[0m";
        printProgressBar(800);
        // sleep_for(milliseconds(800));
        return admin_option();
    }
    else
    {
        cout << "\033[0;31m"
             << "Username or Password is Wrong"
             << "\033[0m";
        sleep_for(milliseconds(800));
        return admin_page();
    }
}

void Library::admin_option()
{
    try
    {
        string input;
        system("cls");
        cout << "\033[1;32m"
             << "|Admin Menu|"
             << "\033[0m" << endl
             << endl
             << " 1_add book\n 2_add user\n 3_assign book\n 4_take book\n 5_extend reserve time\n 6_list all books\n 7_user details\n 0_logot\n 00_exit\n";
        cout << ">>";
        cin >> input;
        if (input == "1" || input == "add book")
        {
            printProgressBar(800);
            return add_book();
        }
        else if (input == "2" || input == "add user")
        {
            printProgressBar(800);
            add_user();
            return admin_option();
        }
        else if (input == "3" || input == "assign book")
        {
            return assign_existing_book_to_user();
        }
        else if (input == "4" || input == "take book")
        {
            printProgressBar(800);
            return take_book_from_user();
        }
        else if (input == "5" || input == "extend reserve time")
        {
            return extend_user_time();
        }
        else if (input == "6" || input == "list all books")
        {
            printProgressBar(800);
            list_all_books();
            return admin_option();
        }
        else if (input == "7" || input == "user details")
        {
            printProgressBar(800);
            return user_details();
        }
        else if (input == "0" || input == "logout")
        {
            printProgressBar(800);
            return start();
        }
        else if (input == "00" || input == "exit")
        {
            return;
        }
        else
        {
            cout << "\033[1;31m"
                 << "Invalid Input"
                 << "\033[0m";

            sleep_for(milliseconds(800));
            return admin_option();
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Library::extend_user_time()
{
    string username;
    system("cls");
    cout << "Username:";
    cin >> username;
    for (int i = 0; i < users.getLength(); i++)
    {
        if (users.at(i)->username_re() == username)
            user = users.at(i);
    }
    if (user != nullptr)
    {
        book_time_extend_request();
        return admin_option();
    }
    cout << "\033[0;31m"
         << "Username is wrong\n"
         << "\033[0m";
    system("pause");
    return assign_existing_book_to_user();
}

void Library::add_book()
{
    Book *new_book = new Book;
    system("cls");
    cout << "\033[1;35m"
         << "|Add Book Menu|"
         << "\033[0m" << endl
         << endl;
title_loop:
    cout << "\033[0;34m"
         << "Title:"
         << "\033[0m";
    cin >> new_book->title_re();
    if (add_book(new_book->title_re()))
    {
        cout << "\033[0;34m"
             << "Genre:"
             << "\033[0m";
        cin >> new_book->genre_re();
        cout << "\033[0;34m"
             << "Date of Publication:"
             << "\033[0m";
        cin >> new_book->date_of_publication_re();
        cout << "\033[0;34m"
             << "author name:"
             << "\033[0m";
        cin >> new_book->author_name_re();
        books.append(new_book);
        printProgressBar(800);
        return admin_option();
    }
    cout << "\033[1;31m"
         << "This Title has Taken"
         << "\033[0m" << endl;
    goto title_loop;
}

bool Library::add_book(string &title) // return true if there is no book with same title
{
    for (int i = 0; i < books.getLength(); i++)
    {
        if (books.at(i)->title_re() == title)
            return false;
    }
    return true;
}
// ss
void Library::add_user()
{
    User *new_user = new User;
    system("cls");
    cout << "\033[1;35m"
         << "|Add User Menu|"
         << "\033[0m" << endl
         << endl;
    cout << "\033[0;34m"
         << "Name:"
         << "\033[0m";
    cin >> new_user->name_re();
    cout << "\033[0;34m"
         << "Family Name:"
         << "\033[0m";
    cin >> new_user->family_name_re();
    cout << "\033[0;34m"
         << "ID Code:"
         << "\033[0m";
    cin >> new_user->ID_code_re();
username_loop:
    cout << "\033[0;34m"
         << "Username:"
         << "\033[0m";
    cin >> new_user->username_re();
    if (add_user(new_user->username_re()))
    {
        cout << "\033[0;34m"
             << "Password:"
             << "\033[0m";
        cin >> new_user->password_re();
        users.append(new_user);
        printProgressBar(800);
        return;
    }
    cout << "\033[0;31m"
         << "This Username has Taken\n"
         << "\033[0m";
    goto username_loop;
}

bool Library::add_user(string &username) // return true if there is no user with same username
{
    for (int i = 0; i < users.getLength(); i++)
    {
        if (users.at(i)->username_re() == username)
            return false;
    }
    return true;
}

void Library::assign_existing_book_to_user() // false return:= it will reserve book instead
{
    string username;
    system("cls");
    cout << "\033[1;35m"
         << "|Assign Book|"
         << "\033[0m" << endl
         << endl;
    cout << "\033[0;34m"
         << "Username:"
         << "\033[0m";
    cin >> username;
    for (int i = 0; i < users.getLength(); i++)
    {
        if (users.at(i)->username_re() == username)
            user = users.at(i);
    }
    if (user != nullptr)
    {
        take_book_from_library();
        return admin_option();
    }
    cout << "\033[1;31m"
         << "Username is wrong\n"
         << "\033[0m";
    system("pause");
    return assign_existing_book_to_user();
}

void Library::take_book_from_user()
{
    string username;
    system("cls");
    cout << "\033[1;35m"
         << "|Take Book|"
         << "\033[0m" << endl
         << endl;
    cout << "\033[0;34m"
         << "Username:"
         << "\033[0m";
    cin >> username;
    for (int i = 0; i < users.getLength(); i++)
    {
        if (users.at(i)->username_re() == username)
            user = users.at(i);
    }
    if (user != nullptr)
    {
        hand_over_book();
        return admin_option();
    }
    cout << "\033[1;31m"
         << "Username is wrong\n"
         << "\033[0m";
    system("pause");
    return take_book_from_user();
}

void Library::user_details()
{
    system("cls");
    string username;
    cout << "\033[1;35m"
         << "|User Details|"
         << "\033[0m" << endl
         << endl;
    cout << "\033[0;34m"
         << "Username:"
         << "\033[0m";
    cin >> username;
    for (int i = 0; i < users.getLength(); i++)
    {
        if (users.at(i)->username_re() == username)
        {
            cout << *users.at(i);
            system("pause");
            printProgressBar(800);
            return admin_option();
        }
    }
    cout << "\033[1;31m"
         << "the user you are looking for is not available\n"
         << "\033[0m";
    system("pause");
    printProgressBar(800);
    return admin_option();
}

/// @brief ///

void Library::user_page()
{
    string input;
    system("cls");
    cout << "\033[1;32m"
         << "|User Page|"
         << "\033[0m" << endl
         << endl;
    cout << " 1_sign up\n 2_sign in\n 0_back\n"
         << ">>";
    cin >> input;
    if (input == "1" || input == "sign up")
    {
        printProgressBar(800);
        add_user();
        return user_page();
    }
    else if (input == "2" || input == "sign in")
    {
        printProgressBar(800);
        return sign_in();
    }
    else if (input == "0" || input == "start")
    {
        printProgressBar(800);
        return start();
    }
    else
    {
        cout << "\033[1;31m"
             << "Please Choose Correctly"
             << "\033[0m";
        sleep_for(milliseconds(800));
        return user_page();
    }
}

void Library::sign_in()
{
    system("cls");
    cout << "\033[1;35m"
         << "|Sign In|"
         << "\033[0m" << endl
         << endl;
    string username, password;
    cout << "\033[0;34m"
         << "Username:"
         << "\033[0m";
    cin >> username;
    if (username == "0")
    {
        return start();
    }
    cout << "\033[0;34m"
         << "Password:"
         << "\033[0m";
    cin >> password;
    for (int i = 0; i < users.getLength(); ++i)
    {
        if (users.at(i)->sign_in(username, password))
        {
            cout << "\033[1;36m"
                 << "Welcome "
                 << users.at(i)->name_re()
                 << "\033[0m";
            user = users.at(i);
            printProgressBar(800);
            return user_option();
        }
    }
    cout << "\033[1;31m"
         << "Username or Password is Wrong"
         << "\033[0m";
    printProgressBar(800);
    return sign_in();
}

void Library::user_option()
{
    try
    {
        string input;
        system("cls");
        cout << "\033[1;32m"
             << "|User Menu|"
             << "\033[0m" << endl
             << endl
             << " 1_take book\n 2_hand over book\n 3_extend book time\n 4_my book list\n 5_list all book\n 6_search\n 0_logout\n 00_exit\n"
             << ">>";
        cin >> input;
        if (input == "1" || input == "take book")
        {
            take_book_from_library();
            return user_option();
        }
        else if (input == "2" || input == "hand over book")
        {
            printProgressBar(800);
            hand_over_book();
            return user_option();
        }
        else if (input == "3" || input == "extend book time")
        {
            printProgressBar(800);
            book_time_extend_request();
            return user_option();
        }
        else if (input == "4" || input == "my book list")
        {
            printProgressBar(800);
            return my_books_list();
        }
        else if (input == "5" || input == "list all book")
        {
            list_all_books();
            return user_option();
        }
        else if (input == "6" || input == "search")
        {
            string bookname;
            system("cls");
            cout << "\033[0;35m"
                 << "|Search Book|"
                 << "\033[0m" << endl
                 << endl;
            cout << "\033[0;34m"
                 << "Book Name:"
                 << "\033[0m";
            cin >> bookname;
            Book *book = search((bookname));
            if (book == nullptr)
            {
                cout << "033[1;31m"
                     << "the book you are looking for is not available\n"
                     << "\033[0m";
                system("pause");
                printProgressBar(800);
                return user_option();
            }
            cout << *book;
            system("pause");
            printProgressBar(800);
            return user_option();
        }
        else if (input == "0" || input == "logout")
        {
            user = nullptr;
            printProgressBar(800);
            return user_page();
        }
        else if (input == "00" || input == "exit")
        {
            return;
        }
        else
        {
            cout << "\033[1;31m"
                 << "Invalid Input"
                 << "\033[0m";
            printProgressBar(800);
            return user_option();
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Library::book_time_extend_request()
{
    string bookname;
    system("cls");
    cout << "\033[1;35m"
         << "|Extend Book Time|"
         << "\033[0m" << endl
         << endl;
    cout << "\033[0;34m"
         << "Book Name:"
         << "\033[0m";
    cin >> bookname;
    Book *book = search((bookname));
    if (book == nullptr)
    {
        cout << "\033[1;31m"
             << "the book you are looking for is not available\n"
             << "\033[0m";
        system("pause");
        printProgressBar(800);
        return;
    }
    else if (book->assign())
    {
        cout << *book;
        if (book->queue().getLength())
        {
            cout << "\033[1;31m"
                 << "this book has a reserve queue and can not extend your time\n"
                 << "\033[0m";
            system("pause");
            printProgressBar(800);
            return;
        }
        cout << "\033[1;35m"
             << "your time extended\n"
             << "\033[0m";
        book->assign_time_re().now();
        system("pause");
        printProgressBar(800);
        return;
    }
    cout << "\033[1;31m"
         << "book doesn't assign to anybody so take it first then extend time\n"
         << "\033[0m";
    printProgressBar(800);
    return;
}

void Library::hand_over_book()
{
    int index;
    string bookname;
    system("cls");
    cout << "\033[1;35m"
         << "|Hand Over Book|"
         << "\033[0m" << endl
         << endl;
    cout << "\033[0;34m"
         << "Book Name:"
         << "\033[0m";
    cin >> bookname;
    Book *book = nullptr;
    for (int i = 0; i < user->user_books_re().getLength(); i++)
    {
        if (bookname == user->user_books_re().at(i))
        {
            book = search(bookname);
            index = i;
        }
    }
    if (book == nullptr)
    {
        cout << "\033[1;31m"
             << "the book you are looking for is not available\n"
             << "\033[0m";
        system("pause");
        printProgressBar(800);
        return;
    }
    cout << *book;
    book->assign() = false;
    time.now();
    for (int i = 10; i < book->assign_time_re().day_differ(time); i++) // i=10 because user will recive penalty after 10 day
    {
        user->penalty_re() += penalty_for_late_delivery;
        cout << "\033[1;31m"
             << "you recived a penalty for late delivery " << user->penalty_re()
             << "\033[0m" << endl;
    }
    cout << "\033[1;36m"
         << "the book is unassigned from your list\n"
         << "\033[0m";
    user->user_books_re().delete_node(index);
    system("pause");
    printProgressBar(800);
    return;
}

void Library::take_book_from_library()
{
    string bookname;
    system("cls");
    cout << "\033[1;35m"
         << "|Take Book|"
         << "\033[0m" << endl
         << endl;
    cout << "\033[0;34m"
         << "Book Name:"
         << "\033[0m";
    cin >> bookname;
    Book *book = search((bookname));
    if (book == nullptr)
    {
        cout << "\033[1;31m"
             << "the book you are looking for is not available\n"
             << "\033[0m";
        system("pause");
        printProgressBar(800);
        return;
    }
    else if (book->assign())
    {
        cout << "\033[0;36m"
             << *book
             << "\033[0m";
        if (user->username_re() == book->user_who_borrowed_book_re())
        {
            cout << "\033[1;31m"
                 << "the book you are looking for has been borrowed by you and you can not enter in reserve queue\n"
                 << "\033[0m";
            printProgressBar(800);
            return;
        }
        cout << "\033[1;33m"
             << "the book you are looking for has been borrowed\n"
             << "\033[0m";
        book->queue().enqueue(user);
        user->reserve_time_re().now();
        system("pause");
        printProgressBar(800);
        return;
    }
    else if (!book->queue().getLength())
    {
        cout << "\033[0;36m"
             << *book
             << "\033[0m";
        user->taking_book(book->title_re());
        book->assign() = true;
        book->assign_time_re().now();
        cout << "\033[1;32m"
             << "the book is assigned to your list\n"
             << "\033[0m";
        system("pause");
        printProgressBar(800);
        return;
    }
    cout << *book;
    time.now();
    while (book->queue().top()->reserve_time_re().day_differ(time) > receiving_book_deadline)
    {
        cout << *book->queue().dequeue() << endl
             << "dequeued from queue" << endl;
    }
    if (user->username_re() == book->queue().top()->username_re())
    {
        user->taking_book(book->title_re());
        book->assign() = true;
        book->assign_time_re().now();
        cout << "\033[1;32m"
             << "the book is assigned to your list\n"
             << "\033[0m";
        book->queue().dequeue();
        system("pause");
        printProgressBar(800);
        return;
    }
    if (book->queue().getLength() == 0)
    {
        user->taking_book(book->title_re());
        book->assign() = true;
        book->assign_time_re().now();
        cout << "\033[1;32m"
             << "the book is assigned to your list\n"
             << "\033[0m";
        system("pause");
        printProgressBar(800);
        return;
    }
    cout << "\033[1;33m"
         << "the book you are looking for has been reserved for another user\n"
         << "\033[0m";
    book->queue().enqueue(user);
    user->reserve_time_re().now();
    system("pause");
    printProgressBar(800);
    return;
}

Book *Library::search(string &book_name)
{
    try
    {
        AVLTree<Book *> tree;
        for (int i = 0; i < books.getLength(); i++)
        {
            tree.insert(books.at(i)->title_re(), books.at(i));
        }
        return tree.find(book_name);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return nullptr;
}

void Library::my_books_list()
{
    system("cls");
    cout << "\033[1;35m"
         << "|My Books List|"
         << "\033[0m" << endl
         << endl;
    for (int i = 0; i < user->user_books_re().getLength(); i++)
    {
        cout << user->user_books_re().at(i) << endl;
    }
    system("pause");
    printProgressBar(800);
    return user_option();
}

void Library::list_all_books()
{
    system("cls");
    cout << "\033[1;35m"
         << "|My Books List|"
         << "\033[0m" << endl
         << endl;
    for (int i = 0; i < books.getLength(); i++)
    {
        cout << *books.at(i) << endl;
    }
    string input;
    cout << "\033[0;36m"
         << "show sorted(Y/N)?"
         << "\033[0m";
    cin >> input;
    if (input == "Y" || input == "y")
    {
        return sorted_list_all_books_by_name();
    }
    else if (input == "N" || input == "n")
    {
        printProgressBar(800);
        return;
    }
}

void Library::sorted_list_all_books_by_name()
{
    AVLTree<Book *> tree;
    for (int i = 0; i < books.getLength(); i++)
    {
        tree.insert(books.at(i)->title_re(), books.at(i));
    }
    tree.printInorder();
    system("pause");
    printProgressBar(800);
    return;
}