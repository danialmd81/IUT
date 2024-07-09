#include "hash_table.hpp"

using namespace std;

template <class T>
My_Hash_table<T>::Node::Node()
{
    key = "";
    next = nullptr;
}

template <class T>
My_Hash_table<T>::Node::Node(std::string key, T value)
{
    this->key = key;
    this->value = value;
    next = nullptr;
}

template <class T>
My_Hash_table<T>::My_Hash_table()
{
}

template <class T>
int My_Hash_table<T>::hash(string &key)
{
    return hash_function(key) % (SIZE + 1);
}

template <class T>
void My_Hash_table<T>::set(string key, T value)
{
    int index = hash(key);
    nodeptr newNode(new Node(key, value));
    if (hash_table[index] == nullptr)
    {

        hash_table[index] = newNode;
    }
    else
    {
        nodeptr temp = hash_table[index];
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

template <class T>
optional<T> My_Hash_table<T>::get(string key)
{
    int index = hash(key);
    nodeptr temp = hash_table[index];
    while (temp != nullptr)
    {
        if (temp->key == key)
        {
            return temp->value;
        }
        temp = temp->next;
    }
    return nullopt;
}