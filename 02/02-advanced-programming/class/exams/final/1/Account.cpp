#include "Account.h"

Account::Account()
{
    mojoodi = 0;
}
double &Account::ref_mojoodi()
{
    return mojoodi;
}
