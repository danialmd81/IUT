/// دانیال مبینی  40130023
// محمد صادق هاتفی  40133073
#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    Node *next;
    T value;

    Node()
    {
        this->value = T(INT_MIN);
        this->next = nullptr;
    }
    Node(T value)
    {
        this->value = value;
        this->next = nullptr;
    }
};

template <typename T>
class array
{
private:
    Node<T> *head;
    Node<T> *tail;
    int length;
    int capacity;

public:
    array(int capacity)
    {
        length = 0;
        this->capacity = capacity;
        for (int i = 0; i < capacity; i++)
        {
            Node<T> *newNode = new Node<T>;
            if (i == 0)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    T &operator[](int index)
    {
        if (index < 0 || index >= capacity)
            throw bad_array_new_length();
        Node<T> *temp = head;
        for (int i = 0; i < index; ++i)
        {
            temp = temp->next;
        }
        return temp->value;
    }
    void empty()
    {
        Node<T> *temp = head;
        for (int i = 0; i < capacity; i++)
        {
            temp->value = T(INT_MIN);
            temp = temp->next;
        }
        length = 0;
    }
    int size()
    {
        length = 0;
        Node<T> *temp = head;
        for (int i = 0; i < capacity; i++)
        {
            if (temp->value != T(INT_MIN))
                length++;
            temp = temp->next;
        }
        return length;
    }
};

int main()
{
    array<char> a(10);
    for (int i = 'a', j = 0; j < 10; i++, j++)
    {
        a[j] = i;
        cout << a.size() << "\n";
    }
    for (int j = 0; j < 10; j++)
    {
        cout << a[j] << " ";
    }
    a.empty();
    cout << a.size() << "\n";
    try
    {
        a[-1];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    a[0] = 'a';
    cout << a[0] << "\n";
}