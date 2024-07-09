#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *next;
}Node;

Node head ={-1,NULL};

Node* createNode(int data);

void printNode(int index);

int size();

void push_back(int data);

void pop_front();

void delet(int index);

int search(int data);

int deletsearch(int data);

int main()
{
    int call , p , a , b , c , d ;
    while(1)
    {
        scanf ("%d",&call);
        if(call==1)//push back
        {
            scanf("%d",&p);
            push_back(p);
        }
        if(call==2)//pop front
        {
            if(size()!=0)
            printf("%d\n",(head.next)->data);
            pop_front();
        }

        if(call==3)
        {
            scanf("%d",&a);
            printNode(a-1);
        }
        if(call==4)
        {
            scanf("%d",&b);
            search(b);
        }
        if(call==5)
        {
            scanf("%d",&c);
            delet(c-1);
        }
        if(call==6)
        {
            scanf("%d",&d);
            deletsearch(d);
        }
        else if(call==7)
        {
            return 0;
        }
    }
}

Node* createNode(int data)
{
    Node *newNode;
    newNode = (struct Node *)malloc(sizeof(Node));
    if(newNode == NULL) 
    {
        printf("Memory can not be allocated->\n");
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }
}

void printNode(int index)
{

    Node *temp=head.next;
    if(index>=size())
    {
        printf("ERROR1\n");
        return;
    }
    for(int i=0;i<index;i++)
    {
        temp=temp->next;
    }
    printf("%d\n",temp->data);
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
    }
    else
    {
        while (last->next!= NULL)
        {
            last = last->next;
        }
        last->next = newNode;
    }
}
void pop_front()
{
    Node* temp = head.next;
    if(size()==0)
    {
        printf("ERROR0\n");
        return;
    }
    temp = head.next;
    head.next=temp->next;
    free(temp);
}

void delet(int index)
{
    Node *temp=head.next;
    Node *todelet;
    if(index>=size())
    {
        printf("ERROR3\n");
        return ;
    }
    for(int i=0;i<index-1;i++)
    {
        temp=temp->next;
    }
    todelet=temp->next;
    temp->next=todelet->next;
    free((todelet));
}

int search(int data)
{
    Node *temp=head.next;
    int i=0,c=0,k;
    for(;i<size();++i)
    {
        if(temp->data==data)
        {
            c++;
            k=i;
        }
        
        temp=temp->next;
    }
    if(c!=0)
    {
        printf("%d\n",k+1);
    }
    
    else
    printf("ERROR2\n");
}

int deletsearch(int data)
{
    Node *temp=head.next;
    int i=0,c=0,k;
    if(size()==0)
    printf("ERROR4\n");
    else if(size()==1)
    {
        free(temp);
        head.next=NULL;
    }
    else
    {
        for(;i<size();++i)
        {
            if(temp->data==data)
            {
                c++;
                k=i;
            }
            temp=temp->next;
        }
        temp=head.next;
        Node *todelet;
        if(k>size())
        {
            printf("ERROR4\n");
        }
        for(int i=0;i<k-1;i++)
        {
            temp=temp->next;
        }
        todelet=temp->next;
        temp->next=todelet->next;
        free((todelet));
    }
    
}