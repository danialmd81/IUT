#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
	struct Node** children;
	int data;
	int nchild;
}Node;
Node* root = NULL;

Node* CreatNode(int data) 
{
	Node* node = (Node*)malloc(sizeof(Node));
    if(node==NULL)
    {
        printf("Memory can not be allocated->");
		exit(1);
    }
	node->children = NULL;
	node->data = data;
	node->nchild = 0;
	return node;

}

void AddNode(Node* node, int  data) 
{
	if (node->nchild == 0) 
    {
		node->nchild++;
		node->children = (Node **)malloc(sizeof(Node*));
		node->children[0] = CreatNode(data);
		return;
	}
	node->nchild++;
	node->children = (Node **)realloc(node->children, node->nchild * sizeof(Node*));
	if (node->children == NULL) 
    {
		printf("Memory can not be allocated->");
		exit(1);
	}
	node->children[node->nchild - 1] = CreatNode(data);
	return;
}

void makeRoot(int data) 
{
	root = CreatNode(data);
}

int main() 
{
	makeRoot(0);

	TEST----AddNode(root, 1);
	AddNode(root, 2);
	AddNode(root, 3);
	AddNode(root->children[0], 3);
	AddNode(root->children[0], 3);
	AddNode(root->children[2], 1);
	AddNode(root->children[1], 5);
	AddNode(root->children[1], 3);
	AddNode(root->children[0]->children[0], 4);
	AddNode(root->children[0]->children[1], 3);
	AddNode(root->children[0]->children[1], 2);
	AddNode(root->children[1]->children[0], 4);
	AddNode(root->children[1]->children[1], 7);
	Print(root);



}
