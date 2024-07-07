#include <iostream>

using namespace std;

class S
{
private:
    float data;
    S()
    {
    }
    static S *instance1;
    static S *instance2;

public:
    S(const S &obj) = delete;
    static S *get_instance()
    {
        if (instance1 == nullptr)
        {
            instance1 = new S;
            return instance1;
        }
        else if (instance2 == nullptr)
        {
            instance2 = new S;
            return instance2;
        }
        else
        {
            return instance1;
        }
    }
    float &value()
    {
        return data;
    }
};

S *S::instance1 = nullptr;
S *S::instance2 = nullptr;

int main()
{
    S *s1 = S::get_instance();
    s1->value() = 1;
    S *s2 = S::get_instance();
    s2->value() = 2;
    S *s3 = S::get_instance();
    std::cout << s1->value() << s2->value() << s3->value();
}