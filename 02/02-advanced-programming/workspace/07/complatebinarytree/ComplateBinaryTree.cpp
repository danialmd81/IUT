#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <exception>
#include <conio.h>
#include "Node.h"

using namespace std;

template <class U>
class ComplateBinaryTree
{
private:
    Node<U> *root;    // نود ریشه
    Node<U> *add;     // نودی که برای اضافه کردن استفاده میشه
    Node<U> *read;    //   نودی که برای خوندن استفاده میشه
    int add_num_node; // مقدار نودی که قراره وارد بشه
    int num_node;     // تعداد کل نود های وارد شده
public:
    ComplateBinaryTree<U>()
    {
        int zero = 0;
        root = new Node{zero, ++zero};
        add = root;
        read = root;
        add_num_node = 2;
    }

    ComplateBinaryTree(U &data)
    {
        int zero = 0;
        root = new Node{data, ++zero};
        add = root;
        read = root;
        add_num_node = 2;
    }

    void clear()
    {
        system("cls");
    }

    void gotoxy(int x, int y)
    {
        printf("%c[%d;%df", 0x1B, y, x);
    }

    int height() // ارتفاع شماره نودی که قرارع وارد بشه
    {
        return log2(add_num_node);
    }

    int num_all_node(int &i) // تعداد تمام نود ها در آن ارتفاع
    {
        return pow(2, height() - i);
    }

    bool go_to_right(int &i) // آیا باقی مانده شماره نود از تمام نود های بیشترین ارتفاع از نصف بیشتره یا نه
    {
        if ((add_num_node % num_all_node(i)) >= (num_all_node(i) / 2))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void add_node(U &data)
    {
        for (int i = 0; add->right; i++)
        {
            if (go_to_right(i))
            {
                add = add->right;
            }
            else
            {
                add = add->left;
            }
        }
        num_node = add_num_node;
        if (add_num_node % 2 == 1)
        {
            add->right = new Node{data, add_num_node};
            add_num_node++;
            add->full = 1;
            add = root;
        }
        else
        {
            add->left = new Node{data, add_num_node};
            add_num_node++;
        }
    }

    Node<U> *ret_root()
    {
        return this->root;
    }

    void print()
    {
        // int x, y;
        // // clear();
        // // gotoxy(num_node, 1);
        // read->print_node();
        // cout << endl;
        // for (add_num_node = 2; add_num_node < num_node; add_num_node++)
        // {
        //     for (int i = 0; i < height() - 1; i++)
        //     {
        //         if (go_to_right(i))
        //         {
        //             read = read->right;
        //         }
        //         else
        //         {
        //             read = read->left;
        //         }
        //     }
        //     if (add_num_node % 2 == 1)
        //     {
        //         read->right->print_node();
        //         cout << endl;
        //         read = root;
        //     }
        //     else
        //     {
        //         read->left->print_node();
        //         read = root;
        //     }
        // }

        read->print_node();
        for (add_num_node = 2; add_num_node <= num_node; add_num_node++)
        {
            for (int i = 0; i < height() - 1; i++)
            {
                if (go_to_right(i))
                {
                    read = read->right;
                }
                else
                {
                    read = read->left;
                }
            }
            int all = pow(2, height());
            if (add_num_node == all)
            {
                cout << endl;
            }
            if (add_num_node % 2 == 1)
            {
                read->right->print_node();
                read = root;
            }
            else
            {
                read->left->print_node();
                read = root;
            }
        }
        cout << endl;
    }

    void print_preorder(Node<U> *p)
    {
        if (p == NULL)
        {
            return;
        }
        p->print_node();
        cout << ", ";
        print_preorder(p->left);
        print_preorder(p->right);
    }

    void print_inorder(Node<U> *p)
    {
        if (p == NULL)
        {
            return;
        }
        print_inorder(p->left);
        p->print_node();
        cout << ", ";
        print_inorder(p->right);
    }

    void print_postorder(Node<U> *p)
    {
        if (p == NULL)
        {
            return;
        }
        print_postorder(p->left);
        print_postorder(p->right);
        p->print_node();
        cout << ", ";
    }

    void sort_binary_tree()
    {
        vector<U> vec;
        vec.push_back(read->data);
        for (add_num_node = 2; add_num_node <= num_node; add_num_node++)
        {
            for (int i = 0; i < height() - 1; i++)
            {
                if (go_to_right(i))
                {
                    read = read->right;
                }
                else
                {
                    read = read->left;
                }
            }
            if (add_num_node % 2 == 1)
            {
                vec.push_back(read->right->data);
                read = root;
            }
            else
            {
                vec.push_back(read->left->data);
                read = root;
            }
        }
        sort(vec.begin(), vec.end());
        ComplateBinaryTree a(vec.at(0));
        for (int i = 1; i < vec.size(); i++)
        {
            a.add_node(vec.at(i));
        }
        root = a.ret_root();
        add = root;
        read = root;
    }

    void iterate()
    {
        cout << "enter R or L to iterate in tree or ! to end:" << endl;
        read = root;
        read->print_node();
        while (1)
        {
            char ch = getch();
            if (ch == 'L' || ch == 'l')
            {
                read = read->left;
            }
            else if (ch == 'R' || ch == 'r')
            {
                read = read->right;
            }
            else if (ch == '!')
            {
                break;
            }
            else
            {
                invalid_argument arg("\nchoose corectly.\n");
                throw arg;
            }
            if (read == NULL)
            {
                out_of_range rang("\nout of range.\n");
                throw rang;
            }
            else
            {
                read->print_node();
            }
        }
        cout << endl;
    }

    void delete_node(Node<U> *p)
    {
        if (p == NULL)
        {
            return;
        }
        delete_node(p->left);
        delete_node(p->right);
        p = NULL;
        delete p;
    }

    ~ComplateBinaryTree()
    {
        delete_node(this->root);
    }
};
