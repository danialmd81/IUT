#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createnode(int data)
{
    struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
    tmp->data = data;
    tmp->left = tmp->right = NULL;
    return tmp;
}

struct Node *insert(struct Node *Node, int data)
{

    if (Node == NULL)
        return createnode(data);

    if (data < Node->data)
    {
        Node->left = insert(Node->left, data);
    }

    else if (data > Node->data)
    {
        Node->right = insert(Node->right, data);
    }

    return Node;
}

void print_preorder(Node *binary_tree)
{
    if (binary_tree != NULL)
    {
        printf("%d\n", binary_tree->data);
        print_preorder(binary_tree->left);
        print_preorder(binary_tree->right);
    }
}

void print_inorder(Node *binary_tree)
{
    if (binary_tree)
    {
        print_inorder(binary_tree->left);
        printf("%d ", binary_tree->data);
        print_inorder(binary_tree->right);
    }
}

void print_postorder(Node *binary_tree)
{
    if (binary_tree)
    {
        print_postorder(binary_tree->left);
        print_postorder(binary_tree->right);
        printf("%d\n", binary_tree->data);
    }
}

int main()
{
    int n, a;
    scanf("%d", &n);
    Node *binary_tree = NULL;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        binary_tree = insert(binary_tree, a);
    }

    print_inorder(binary_tree);
}
