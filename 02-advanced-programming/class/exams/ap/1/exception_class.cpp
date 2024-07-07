#include <exception>
#include <iostream>

using namespace std;

template <typename T>
class exception_class : public exception
{
private:
    string messages;
    T key;

public:
    exception_class(T ke)
    {
        key = ke;
        messages = "unknown key";
    }
    T get()
    {
        return key;
    }
    const char *what() const noexcept override
    {
        return messages.c_str();
    }

    ~exception_class()
    {
    }
};