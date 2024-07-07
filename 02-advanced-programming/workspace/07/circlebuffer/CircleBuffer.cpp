#include <iostream>
#include "Node.h"
#include "Exception.h"

using namespace std;

#define SIZE 10

template <typename T>
class CircleBuffer
{
private:
    Node<T> *head;
    Node<T> *pop;
    Node<T> *push;
    int pu_size, po_size;

public:
    CircleBuffer() : po_size{0}, pu_size{0}
    {
        head = NULL;
        pop = NULL;
        push = NULL;
    }
    void push_back(T &val)
    {
        if (pu_size == SIZE)
        {
            throw PushException();
        }
        if (!head)
        {
            head = new Node{val};
            push = head;
            pop = head;
            pu_size++;
        }
        else
        {
            push->next = new Node{val};
            push = push->next;
            pu_size++;
            po_size--;
        }
    }
    void pop_front()
    {
        if (po_size == pu_size + 1)
        {
            throw PopException();
        }
        else
        {
            cout << pop->value << endl;
            pop = pop->next;
            delete head;
            head = pop;
            po_size++;
            pu_size--;
        }
    }
};
