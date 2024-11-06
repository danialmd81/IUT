#include "pizza_finder.hpp"
#include "hash_table.cpp"
#include "kd_tree.hpp"

struct ll
{
    int value;
    string name;
};

int main()
{
    try
    {
        My_Hash_table<ll> h;
        ll al;
        al.name = "Ali";
        al.value = 20;
        h.set(al.name, al);
        cout << h.get("Ali").value().value << "\n";
        cout << h.get("a").value().value;
        ///////////////////////////////////////////////////////////////
        kd_tree tree;
        tree.insert(30, 40);
        tree.insert(5, 25);
        tree.insert(70, 70);
        tree.insert(10, 12);
        tree.insert(50, 30);
        tree.insert(35, 45);

        // cout << "Minimum of 0'th dimension is " << findMin(root, 0) << endl;
        // cout << "Minimum of 1'th dimension is " << findMin(root, 1) << endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}