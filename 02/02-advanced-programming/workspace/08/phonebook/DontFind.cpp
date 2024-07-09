#include<exception>

using namespace std;

class DontFind : public exception
{
public:
    const char *what() const throw()
    {
        return "There is no contact with this name.\n";
    }
};