#pragma once
#include <iostream>
#include <exception>

namespace AVL
{
    template <class T>
    class Node
    {
    public:
        std::string key;
        T value;
        AVL::Node<T> *left;
        AVL::Node<T> *right;
        int height;

        Node(std::string key, T value);
    };
} // namespace for AVLTree Node

template <class T>
class AVLTree
{
private:
    AVL::Node<T> *root;
    bool isHeightInvariantViolated;

    int maxChildHeight(AVL::Node<T> *left, AVL::Node<T> *right);

    int isZigZag(AVL::Node<T> *node);

    AVL::Node<T> *rightRotate(AVL::Node<T> *node);

    AVL::Node<T> *leftRotate(AVL::Node<T> *node);

    AVL::Node<T> *balance(AVL::Node<T> *node);

    int getBalanceFactor(AVL::Node<T> *node);

    AVL::Node<T> *insert(AVL::Node<T> *node, std::string key, T value);

    T &find(AVL::Node<T> *node, std::string key);

    void printInorder(AVL::Node<T> *node);

public:
    AVLTree();

    void insert(std::string key, T value);

    T &find(std::string key);

    void printInorder();
};
