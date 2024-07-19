#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *next;           
}Node;
Node head ={0,NULL};
Node* createNode(int data);
int size();
void push_back(int data);
void pop_back();
Node* max();
int main()
{
    int call,p;
    Node *m;
    while(1)
    {
        scanf("%d",&call);
            if(call==1)// push back
            {
                scanf("%d",&p);
                push_back(p);
            }

            if(call==2) // pop back
            {
                pop_back();
            }
            if(call==3)//max
            {
                if(size()==0)
                printf("stack is empty\n");
            
                else
                {
                    m=max();
                    printf("%d\n",m->data);
                }
            }
            
            if(call==4)
            return 0;
    }
}
Node* createNode(int data)
{
    Node *newNode;
    newNode = (struct Node *)malloc(sizeof(Node));
    if(newNode == NULL) 
    {
        printf(" Memory can not be allocated->\n");
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }
}
int size()
{
    int size=0;
    Node *last=head.next;
    while (last!= NULL)
    {
        last = last->next;
        size++;
    }
    return size;
}
void push_back(int data)
{
    Node *newNode = createNode(data);
    Node *last =head.next;
    newNode->next = NULL;
    if (head.next == NULL)
    {
        head.next = newNode;
        return;
    }
    else
    {
        while (last->next!= NULL)
        {
            last = last->next;
        }
        last->next = newNode;
        return;
    }
    
}
void pop_back()
{
    Node *OneToLast =head.next;
    Node *last;
    if(head.next!=NULL)
    last =OneToLast->next;
    if (size()==0)
    {
        printf("stack is empty\n");
    }
    else if (size()==1)
    {
        head.next=NULL;
        printf("%d\n",OneToLast->data);
        free(OneToLast);
        free(last);
    }
    else
    {
        while (last->next!= NULL)
        {
            OneToLast=OneToLast->next;
            last = last->next;
        }
        printf("%d\n",last->data);
        free(last);
        OneToLast->next=NULL;
    }
    
}
Node* max()
{
    Node *max;
    Node *temp=head.next;
    max=temp;
    while ( temp!= NULL) 
    {
        if (max->data < temp->data)
        {
            max=temp;
        }
        temp=temp->next;
    }
    return max;
}