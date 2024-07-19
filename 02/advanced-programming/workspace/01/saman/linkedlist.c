/*

 FirstName:Danial

 LastName:Mobini

 StudentNumber: 40130023

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

typedef struct Node
{
    employee *data;
    struct Node *next;
} Node;

Node head = {NULL, NULL};

Node *createNode(employee data)
{
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = (employee *)malloc(sizeof(employee));
    if (newNode == NULL)
    {
        printf("Memory can not be allocated->");
    }
    else
    {
        *newNode->data = data;
        newNode->next = NULL;
        return newNode;
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

void push_front(employee data)
{
    Node *newNode = createNode(data);
    newNode->next = head.next;
    head.next = newNode;
}

void push_back(employee data)
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
    free(temp->data);
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
        free(OneToLast->data);
        free(OneToLast);
        head.next = NULL;
        return;
    }
    else
    {
        while (last->next != NULL)
        {
            OneToLast = OneToLast->next;
            last = last->next;
        }
        free(last->data);
        free(last);
        OneToLast->next = NULL;
        return;
    }
}

Node *search(char mcode[11])
{
    Node *temp;
    temp = head.next;
    for (int i = 0; i < size(); ++i)
    {
        if (strcmp(temp->data->mcode, mcode) == 0)
        {
            return temp;
        }
        temp = temp->next;
    }
}

void delet(char mcode[11])
{
    if (size() == 0)
    {
        printf("There is No Employee.\n");
        return;
    }
    Node *temp, *tempback, *todelet;
    tempback = head.next;
    temp = head.next->next;
    if (size() == 1)
    {
        if (strcmp(tempback->data->mcode, mcode) == 0)
        {
            todelet = tempback;
        }
        free(todelet->data);
        free(todelet);
        return;
    }
    if (size() > 1)
    {
        for (int i = 1; i < size(); ++i)
        {
            if (strcmp(temp->data->mcode, mcode) == 0)
            {
                todelet = temp;
                tempback->next = todelet->next;
            }
            tempback = tempback->next;
            temp = temp->next;
        }
        free(todelet->data);
        free(todelet);
        return;
    }
}

void printNode(Node *node)
{
    if (node == NULL)
    {
        printf("There is No Employee.\n");
    }
    else
    {
        printf("%s\n", (*node).data->name);
        printf("%s\n", (*node).data->fname);
        printf("%s\n", (*node).data->mcode);
        printf("%s\n", (*node).data->birthda);
        printf("%d\n", (*node).data->finalsalry);
    }
    return;
}

void print()
{
    Node *temp = head.next;
    while (temp != NULL)
    {
        printNode(temp);
        temp = temp->next;
    }
    return;
}

void display(char mcode[11])
{
    system("cls");
    Node *dis = search(mcode);
    printNode(dis);
    return;
}

void changesalary(char mcode[11], int newsalary)
{
    Node *wanted = search(mcode);
    wanted->data->salary = newsalary;
    wanted->data->finalsalry = wanted->data->salary * wanted->data->hour * wanted->data->bonus;
    return;
}

void changelevel(char mcode[11], int level)
{
    Node *wanted = search(mcode);
    wanted->data->level = level;
    return;
}
