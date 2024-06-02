#pragma once
#include <iostream>
#include <exception>
#include <cereal/archives/json.hpp>

namespace Linked
{
    template <class T>
    class Node
    {
    public:
        T value;
        Node *next;
        Node(T value);
    };
} // namespace LinkedList Node

template <class T>
class LinkedList
{
private:
    Linked::Node<T> *head;
    Linked::Node<T> *tail;
    int length;

public:
    LinkedList();
    ~LinkedList();
    void printList();
    int &getLength();
    void delete_node(int index);
    void append(T value);
    T &at(int index);
};
