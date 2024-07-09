#include <iostream>
#include <typeinfo>
#include <exception>

using namespace std;

template <class T>
class Node
{
private:
    int num;
    bool full;
    T data;
    Node *left, *right;

public:
    Node(T &dat, int &n)
    {
        if (typeid(dat) != typeid(this->data))
        {
            bad_typeid typ;
            throw typ;
        }
        else
        {
            num = n;
            full = 0;
            data = dat;
            left = NULL;
            right = NULL;
        }
    }

    void print_node()
    {
        cout << data;
    }
    template <class U>
    friend class ComplateBinaryTree;
};
