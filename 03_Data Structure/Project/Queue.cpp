#include "Queue.hpp"

using namespace std;

template <class T>
QUE::Node<T>::Node(T value)
{
    this->value = value;
    next = nullptr;
}

template <class T>
Queue<T>::Queue()
{
    first = nullptr;
    last = nullptr;
    length = 0;
}

template <class T>
int Queue<T>::getLength()
{
    return length;
}

template <class T>
void Queue<T>::enqueue(T &value)
{
    QUE::Node<T> *newNode = new QUE::Node<T>(value);
    if (length == 0)
    {
        first = newNode;
        last = newNode;
    }
    else
    {
        last->next = newNode;
        last = newNode;
    }
    length++;
}

template <class T>
T Queue<T>::dequeue()
{
    if (length == 0)
    {
        throw(logic_error("queue is empty"));
    }
    QUE::Node<T> *temp = first;
    T value = first->value;
    if (length == 1)
    {
        first = nullptr;
        last = nullptr;
    }
    else
    {
        first = first->next;
    }
    delete temp;
    length--;
    return value;
}

template <class T>
T &Queue<T>::top()
{
    return first->value;
}