#include "KootahModdat.h"
#include "Jari.h"
#include <vector>

int main()
{
    vector<Account *> list;
    Jari j;
    j.ref_mojoodi() = 1000;
    KootahModdat k1(0.14), k2(0.14);
    k1.ref_mojoodi() = 1000;
    k2.ref_mojoodi() = 2000;
    list.push_back(&j);
    list.push_back(&k1);
    list.push_back(&k2);
    for (int i = 0; i < list.size(); i++)
    {
        std::cout << list.at(i)->etebar() << endl;
    }
}