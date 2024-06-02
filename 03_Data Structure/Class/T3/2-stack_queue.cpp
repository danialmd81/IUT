// دانیال مبینی  40130023
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
            temp->value = INT_MIN;
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

template <typename T>
class stack
{
private:
    int capacity, top;
    array<T> *myStack;

public:
    stack(int capacity)
    {
        top = -1;
        myStack = new array<T>(capacity);
        this->capacity = capacity;
    }
    void push(T value)
    {
        if (top >= (capacity - 1))
        {
            cout << "Stack Overflow";
        }
        else
        {
            (*myStack)[++top] = value;
            cout << value << " pushed into stack\n";
        }
    }
    T pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow";
            return -1;
        }
        else
        {
            return (*myStack)[top--];
        }
    }
    int length()
    {
        return top + 1;
    }
    int search(T value)
    {
        if (top < 0)
        {
            cout << "Stack is Empty\n";
            return top;
        }
        else
        {
            for (int i = top; i >= 0; i--)
            {
                if ((*myStack)[i] == value)
                {
                    return i;
                }
            }
            return -2;
        }
    }
};

template <typename T>
class queue
{
private:
    int capacity, last, first;
    array<T> *myQueue;

public:
    queue(int capacity)
    {
        first = -1;
        last = -1;
        myQueue = new array<T>(capacity);
        this->capacity = capacity;
    }
    void enqueue(T value)
    {
        if ((first == 0 && last == capacity - 1) ||
            ((last + 1) % capacity == first))
        {
            printf("\nQueue is Full");
            return;
        }

        else if (first == -1)
        {
            first = last = 0;
            (*myQueue)[last] = value;
        }

        else if (last == capacity - 1 && first != 0)
        {
            last = 0;
            (*myQueue)[last] = value;
        }

        else
        {
            last++;
            (*myQueue)[last] = value;
        }
    }
    T dequeue()
    {
        if (first == -1)
        {
            printf("\nQueue is Empty");
            return T(INT_MIN);
        }

        T data = (*myQueue)[first];
        (*myQueue)[first] = T(INT_MIN);
        if (first == last)
        {
            first = -1;
            last = -1;
        }
        else if (first == capacity - 1)
            first = 0;
        else
            first++;

        return data;
    }
    int length()
    {
        if (first > last)
        {
            return capacity - (first - last) + 1;
        }
        else
            return last - first + 1;
    }
    int search(T value)
    {
        if (first == -1)
        {
            printf("\nQueue is Empty");
            return first;
        }
        else
        {
            if (first > last)
            {
                for (int i = first; i != last + 1; i++)
                {

                    if ((*myQueue)[i] == value)
                    {
                        return i;
                    }
                    if (i == capacity - 1)
                    {
                        i = 0;
                    }
                }
            }
            else
            {
                for (int i = first; i <= last; i++)
                {
                    if ((*myQueue)[i] == value)
                    {
                        return i;
                    }
                }
            }

            return -2;
        }
    }
};

int main()
{
    stack<char> s(10);
    for (int i = 'a'; i < 107; i++)
    {
        s.push(i);
        cout << s.length() << "\n";
    }
    cout << s.search('c') << "\n";
    for (int i = 'a'; i < 107; i++)
    {
        cout << s.pop() << " ";
    }
    cout << "\n"
         << s.search('c');

    queue<char> que1(10);
    for (int i = 'a'; i < 107; i++)
    {
        que1.enqueue(i);
        cout << que1.length() << "\n";
    }
    int size = que1.length();
    cout << que1.search('c') << "\n";
    for (int j = 0; j < size; j++)
    {
        cout << que1.dequeue() << " ";
    }
    cout << '\n';
    for (int i = 'a'; i < 107; i++)
    {
        que1.enqueue(i);
        cout << que1.length() << "\n";
    }
    cout << que1.dequeue() << " ";
    cout << que1.dequeue() << " ";
    cout << que1.dequeue() << " ";
    que1.enqueue('a');
    cout << que1.length() << "\n"
         << que1.search('c') << "\n"
         << que1.search('d') << "\n"
         << que1.search('e');
}