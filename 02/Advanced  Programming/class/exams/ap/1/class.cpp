#include <iostream>
#include <map>
#include "exception_class.h"

using namespace std;

template <typename K, typename V>
class class_class
{
private:
    multimap<K, V> class_list;

public:
    class_class(int size)
    {
    }
    void insert(K key, V value)
    {
        if (class_list.find(key) == class_list.end())
            class_list.insert(pair<K, V>(key, value));
        else
        {
            exception_class exc(key);
            throw exc;
        }
    }
    void ubdate(K key, V value)
    {
        if (class_list.find(key) != class_list.end())
            class_list.insert(key, value);
        else
        {
            exception_class exc(key);
            throw exc;
        }
    }
};

int main()
{
    class_class<string, float> man(5);
    try
    {
        string name;
        float value;
        for (size_t i = 0; i < 5; i++)
        {
            cin >> name >> value;
            man.insert(name, value);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}