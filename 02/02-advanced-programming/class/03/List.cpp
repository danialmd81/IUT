// in this project, we intrduced the list in c++
// list is a linked list designed to contain objects from a specific class
// list contais various number of usefull functions
// we introduced some of them here


#include <iostream>
#include <list>
#include <string>
using namespace std;
int main()
{
    to_string(12);
    list<int> l = { 1,2,3,4,5,6,7,8 };
    cout << *l.begin() << endl; // will point to the first element of the list
    cout << l.back() << endl;// will return the last element of the list
    l.push_back(14);// will add an element in the end of the list
    cout << l.front() << endl;//will return the first element in the list
    list<int>::iterator it = l.begin();//we defined an iterator to walk through the list
    cout << *it << endl;//iterator is a pointer.
    advance(it, 4);// advance makes iterator move forward in the list.
    cout << *it << endl;
    for (auto x : l) {// a for each loop to print all of the element in the list
        cout << x << " ";
    }
}

