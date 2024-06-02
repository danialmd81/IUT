#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
	int data;
	struct Node *child;
    struct Node *next;

}Node;
Node *root=NULL;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL) 
    {
        printf(" Memory can not be allocated->");
    }
    newNode->data = data;
    newNode->child= NULL;
    newNode->next= NULL;
    return newNode;
}
        
void makeRoot(int data)
{
    root=createNode(data);
    root->next=NULL;
    root->child=NULL;
}

void AddNext(Node *treeNode, int data)
{
    Node *newNode = createNode(data);
    Node *last =treeNode->next;
    newNode->next = NULL;
    if (treeNode->next == NULL)
    {
        treeNode->next = newNode;
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

Node *AddChild(Node *Node, int data)
{
    Node->child=createNode(data);
    return (Node->child);
}

void print(Node *treeNode)
{
    Node *temp=treeNode->next;
    while ( temp!= NULL)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}

int main()
{
    makeRoot(0);
    Node *rchild1,*rchild2,*rchild3,*rchild4,*rchild5;
    rchild1=AddChild(root,1);
    rchild2=AddChild(root,2);
    rchild3=AddChild(root,3);
    rchild4=AddChild(root,4);
    rchild5=AddChild(root,5);
    for(int i=10;i<50;i+=5)
    AddNext(rchild1,i);
    print(rchild1);
}










