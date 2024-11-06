#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    multimap<char, int> multi;
    multi.insert(pair<char, int>('a', 10));
    multi.insert(make_pair('b', 20));
    multi.insert(make_pair('b', 30));
    multi.insert(make_pair('b', 40));
    multi.insert(make_pair('c', 50));
    multi.insert(make_pair('c', 60));
    for (char ch = 'a'; ch < 'd'; ch++)
    {
        cout << ch << " has " << multi.count(ch) << " elements" << endl;
    }
    for (char ch = 'a'; ch < 'd'; ch++)
    {
        pair<multimap<char, int>::iterator,
             multimap<char, int>::iterator>
            iter;
        iter = multi.equal_range(ch);
        cout << ch << " : ";
        for (multimap<char, int>::iterator it = iter.first;
             it != iter.second; it++)
        {
            cout << " " << it->second;
        }
        cout << endl;
    }
    multimap<char, int>::iterator lower = multi.lower_bound('a');
    multimap<char, int>::iterator upper = multi.upper_bound('b');
    for (multimap<char, int>::iterator it = lower;
         it != upper; it++)
    {
        cout << " " << it->second;
    }
}
