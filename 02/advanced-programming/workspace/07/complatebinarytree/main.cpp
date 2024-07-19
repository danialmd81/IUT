#include "ComplateBinaryTree.h"

using namespace std;

int main()
{
    char ch = 'A';
    ComplateBinaryTree tree(ch);
    for (char i = 66; i < 74; i++)
    {
        tree.add_node(i);
    }
    tree.print_preorder(tree.ret_root());
    cout << endl;
    tree.print_inorder(tree.ret_root());
    cout << endl;
    tree.print_postorder(tree.ret_root());
    cout << endl;
    tree.print();
    try
    {
        tree.iterate();
        tree.delete_node(tree.ret_root());
        tree.print();
    }
    catch (const exception &e)
    {
        cerr << e.what();
    }

    ch = 'I';
    ComplateBinaryTree tree1(ch);
    for (char i = 72; i > 64; i--)
    {
        tree1.add_node(i);
    }
    tree1.print();
    tree1.sort_binary_tree();
    tree1.print();
}