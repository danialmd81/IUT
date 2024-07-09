#include "Linkedlist.hpp"

using namespace std;

template <class T>
Linked::Node<T>::Node(T value)
{
    this->value = value;
    next = nullptr;
}

template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    Linked::Node<T> *temp = head;
    while (head)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
}

template <class T>
void LinkedList<T>::printList()
{
    Linked::Node<T> *temp = head;
    while (temp != nullptr)
    {
        cout << temp->value << endl;
        temp = temp->next;
    }
}

template <class T>
int &LinkedList<T>::getLength()
{
    return length;
}

template <class T>
void LinkedList<T>::append(T value)
{
    Linked::Node<T> *newNode = new Linked::Node<T>(value);
    if (length == 0)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

template <class T>
void LinkedList<T>::delete_node(int index)
{
    if (index < 0 || index >= length)
        return;
    Linked::Node<T> *temp = head;
    if (index == 0)
    {
        if (length == 0)
            return;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
        }
        delete temp;
        length--;
        return;
    }
    if (index == length - 1)
    {
        if (length == 0)
            return;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Linked::Node<T> *pre = head;
            while (temp->next)
            {
                pre = temp;
                temp = temp->next;
            }
            tail = pre;
            tail->next = nullptr;
        }
        delete temp;
        length--;
        return;
    }

    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }
    Linked::Node<T> *prev = temp;
    temp = prev->next;
    prev->next = temp->next;
    delete temp;
    length--;
}

template <class T>
T &LinkedList<T>::at(int index)
{
    if (index < 0 || index >= length)
    {
        throw range_error("out of range");
    }
    Linked::Node<T> *temp = head;

    for (int i = 0; i < index; ++i)
    {
        temp = temp->next;
    }
    return temp->value;
}
