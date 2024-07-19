#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    // < -- -- -- -- -- -- -- -- -- -- --MAP-- -- -- -- -- -- -- -- -- -- -- --->
    pair<string, int> student1;
    pair<string, int> student2("ali", 123);
    // pair <string, int> student3(student2);
    pair<string, int> student3("Mahdi", 780);
    pair<string, int> student4("shayan", 1000);
    student1.first = "mohammad";
    student1.second = 12;
    map<string, int> mymap;
    mymap["mohammad"] = 1678;
    mymap.insert(student1);
    mymap.insert(student2);
    mymap.insert(student3);
    mymap.insert(student4);
    cout << mymap["ali"] << endl;
    cout << mymap.find("ali")->second << endl;
    cout << mymap.find("ali")->first << endl;
    mymap.find("ali")->second = 512;
    cout << mymap["ali"] << endl;
    mymap.erase("ali");
    map<string, int>::iterator it;
    it = mymap.find("mohammad");
    mymap.erase(it);
    mymap.erase(it, mymap.end());
    cout << mymap.at("ahmad");
    try
    {
        cout << mymap.at("amir") << endl;
    }
    catch (out_of_range oor)
    {
        cerr << "The key was not found" << endl;
    }
    pair<map<string, int>::iterator, bool> in;
    in = mymap.insert(pair<string, int>("amir", 550));
    if (in.second == true)
    {
        cout << in.first->first << " is now in the map" << endl;
    }
    if (in.second == false)
    {
        cout << "element " << in.first->first << " was already existed";
        cout << " with the value of : " << in.first->second << endl;
        ;
    }
    for (auto it2 = mymap.begin(); it2 != mymap.end(); ++it2)
    {
        cout << it2->first << " : " << it2->second << endl;
    }
}
