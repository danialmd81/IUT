#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

using namespace std;

class Account {
  private:
    double mojoodi;

  public:
    Account();
    double &ref_mojoodi();
    virtual const double etebar() = 0;
};
#include "Account.cpp"

#endif // ACCOUNT_H
