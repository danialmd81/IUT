#include "AVLTree.hpp"

using namespace std;

template <class T>
AVL::Node<T>::Node(string key, T value)
{
    this->key = key;
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
    this->height = 0;
}

template <class T>
int AVLTree<T>::maxChildHeight(AVL::Node<T> *left, AVL::Node<T> *right)
{
    if (left == nullptr && right == nullptr)
    {
        return -1;
    }
    else if (left == nullptr)
    {
        return right->height;
    }
    else if (right == nullptr)
    {
        return left->height;
    }
    int leftH = left->height;
    int rightH = right->height;
    return leftH > rightH ? leftH : rightH;
}

// 0 -> none
// 1 -> zig
// 2 -> zag
template <class T>
int AVLTree<T>::isZigZag(AVL::Node<T> *node)
{
    if (node->right == nullptr && node->left == nullptr)
        return 0;
    else if (node->right == nullptr)
        return 1;
    else if (node->left == nullptr)
        return 2;

    return node->left->height >= node->right->height ? 1 : 2;
}

template <class T>
AVL::Node<T> *AVLTree<T>::rightRotate(AVL::Node<T> *node)
{
    AVL::Node<T> *newRoot = node->left;
    AVL::Node<T> *temp = newRoot->right;

    newRoot->right = node;
    node->left = temp;

    node->height = 1 + maxChildHeight(node->left, node->right);
    newRoot->height = 1 + maxChildHeight(newRoot->left, newRoot->right);

    return newRoot;
}

template <class T>
AVL::Node<T> *AVLTree<T>::leftRotate(AVL::Node<T> *node)
{
    AVL::Node<T> *newRoot = node->right;
    AVL::Node<T> *temp = newRoot->left;

    newRoot->left = node;
    node->right = temp;

    node->height = 1 + maxChildHeight(node->left, node->right);
    newRoot->height = 1 + maxChildHeight(newRoot->left, newRoot->right);

    return newRoot;
}

template <class T>
AVL::Node<T> *AVLTree<T>::balance(AVL::Node<T> *node)
{

    if (isZigZag(node) == 1 && isZigZag(node->left) == 1)
    {
        return rightRotate(node);
    }
    if (isZigZag(node) == 2 && isZigZag(node->right) == 2)
    {
        return leftRotate(node);
    }
    if (isZigZag(node) == 1 && isZigZag(node->left) == 2)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (isZigZag(node) == 2 && isZigZag(node->right) == 1)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    node->height = 1 + maxChildHeight(node->left, node->right);
    return node;
}

template <class T>
int AVLTree<T>::getBalanceFactor(AVL::Node<T> *node)
{
    AVL::Node<T> *left = node->left;
    AVL::Node<T> *right = node->right;

    if (left == nullptr && right == nullptr)
    {
        return 0;
    }
    else if (right == nullptr)
    {
        return left->height + 1;
    }
    else if (left == nullptr)
    {
        return -right->height - 1;
    }

    return left->height - right->height;
}

template <class T>
AVL::Node<T> *AVLTree<T>::insert(AVL::Node<T> *node, string key, T value)
{
    if (node == nullptr)
    {
        return new AVL::Node<T>(key, value);
    }

    if (key > node->key)
    {
        node->right = insert(node->right, key, value);
    }
    else if (key < node->key)
    {
        node->left = insert(node->left, key, value);
    }
    else
        return node;

    int maxHeight = maxChildHeight(node->left, node->right);
    node->height = maxHeight + 1;

    int balanceFactor = getBalanceFactor(node);

    if (abs(balanceFactor) > 1)
    {
        isHeightInvariantViolated = true;
        return balance(node);
    }

    return node;
}

template <class T>
T &AVLTree<T>::find(AVL::Node<T> *node, string key)
{
    if (node == nullptr)
    {
        throw logic_error("tree is empty");
    }
    string currentKey = node->key;

    if (key == currentKey)
    {
        return node->value;
    }
    else if (key > currentKey)
    {
        return find(node->right, key);
    }
    else
    {
        return find(node->left, key);
    }
}

template <class T>
AVLTree<T>::AVLTree()
{
    root = nullptr;
    isHeightInvariantViolated = false;
}

template <class T>
void AVLTree<T>::insert(string key, T value)
{
    root = insert(root, key, value);

    if (isHeightInvariantViolated)
    {
        isHeightInvariantViolated = false;
    }
}

template <class T>
T &AVLTree<T>::find(string key)
{
    return find(root, key);
}

template <class T>
void AVLTree<T>::printInorder(AVL::Node<T> *node)
{
    if (node == nullptr)
        return;

    printInorder(node->left);

    cout << *node->value << endl;

    printInorder(node->right);
}

template <class T>
void AVLTree<T>::printInorder()
{
    return printInorder(root);
}