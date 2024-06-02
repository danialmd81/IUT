#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node head = {0, NULL};

Node *createNode(int data);

void printNode(Node *node);

int size();

void push_front(int data);

void push_back(int data);

void pop_front();

void pop_back();

void insert(int data, int index);

void delet(int index);

int search(int data);

Node *max();

int average();

void swap(int index1, int index2);

void print();

int main()
{
    push_back(1);
    push_back(2);
    push_back(3);
    push_back(10);
    push_back(5);
    push_back(6);
    push_back(7);
    push_back(11);
    print();
}
Node *createNode(int data)
{
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory can not be allocated->");
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }
}

void printNode(Node *node)
{
    if (node == NULL)
    {
        printf("node is empty.");
    }
    else
    {
        printf("%d", (*node).data);
    }
}
int size()
{
    int size = 0;
    Node *last = head.next;
    while (last != NULL)
    {
        last = last->next;
        size++;
    }
    return size;
}

void push_front(int data)
{
    Node *newNode = createNode(data);
    newNode->next = head.next;
    head.next = newNode;
}

void push_back(int data)
{
    Node *newNode = createNode(data);
    Node *last = head.next;

    if (head.next == NULL)
    {
        head.next = newNode;
        return;
    }
    else
    {
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newNode;
        return;
    }
}

void pop_front()
{
    Node *temp = head.next;
    if (size() == 0)
    {
        printf("Impossible to delete from empty Singly Linked List");
        return;
    }
    temp = head.next;
    head.next = temp->next;
    free(temp);
}

void pop_back()
{
    Node *OneToLast = head.next;
    Node *last = OneToLast->next;
    if (size() == 0)
    {
        printf("Impossible to delete from empty Singly Linked List");
        return;
    }
    else if (size() == 1)
    {
        head.next = NULL;
        free(OneToLast);
        free(last);
        return;
    }
    else
    {
        while (last->next != NULL)
        {
            OneToLast = OneToLast->next;
            last = last->next;
        }
        free(last);
        OneToLast->next = NULL;
        return;
    }
}
void insert(int data, int index)
{
    Node *newNode = createNode(data);
    Node *temp = head.next;
    if (index >= size())
    {
        printf("invalid input size!\n");
        return;
    }
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void delet(int index)
{
    Node *temp = head.next;
    Node *todelet;
    if (index >= size())
    {
        printf("invalid input size!\n");
        return;
    }
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }
    todelet = temp->next;
    temp->next = todelet->next;
    free((todelet));
}

int search(int data)
{
    Node *temp = head.next;
    int i = 0, c = 0, k;
    for (; i < size(); ++i)
    {
        if (temp->data == data)
        {
            return i;
        }

        temp = temp->next;
    }
    return -1;
}

Node *max()
{
    Node *max;
    Node *temp = head.next;
    max = temp;
    while (temp != NULL)
    {
        if (max->data < temp->data)
        {
            max = temp;
        }
        temp = temp->next;
    }
    return max;
}

int average()
{
    int sum = 0, ave = 0;
    Node *temp = head.next;
    while (temp != NULL)
    {
        sum = sum + (temp->data);
        temp = temp->next;
    }
    ave = sum / size();
    return ave;
}

void swap(int index1, int index2)
{
    Node *temp = head.next;
    int *node1, *node2, nodetemp;
    for (int i = 0; i < size(); i++)
    {
        if (index1 == i)
        {
            node1 = &(temp->data);
        }
        if (i == index2)
        {
            node2 = &(temp->data);
        }
        temp = temp->next;
    }
    nodetemp = *node1;
    *node1 = *node2;
    *node2 = nodetemp;
}

void print()
{
    Node *temp = head.next;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
