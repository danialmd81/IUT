#include <iostream>
#include <exception>

using namespace std;

struct PopException : public exception
{
    const char *what() const throw()
    {
        return "Buffer is empty";
    }
};