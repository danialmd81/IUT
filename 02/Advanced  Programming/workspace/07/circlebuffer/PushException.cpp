#include <iostream>
#include <exception>

using namespace std;

struct PushException : public exception
{
    const char *what() const throw()
    {
        return "Buffer is full.";
    }
};