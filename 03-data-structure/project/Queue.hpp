#pragma once
#include <iostream>
#include <exception>


namespace QUE
{
    template <class T>
    class Node
    {
    public:
        T value;
        Node *next;

        Node(T value);
    };
} // namespace QUE for Queue Node

template <class T>
class Queue
{
private:
    QUE::Node<T> *first;
    QUE::Node<T> *last;
    int length;

public:
    Queue();
    int getLength();
    void enqueue(T &value);
    T dequeue();
    T &top();
};
