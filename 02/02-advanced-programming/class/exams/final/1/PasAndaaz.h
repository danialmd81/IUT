#ifndef PASANDAAZ_H
#define PASANDAAZ_H

#include "Account.h"

class PasAndaaz : public Account {
  private:
  protected:
    double percent;

  public:
    PasAndaaz();
    virtual const double etebar();
};

#include "PasAndaaz.cpp"

#endif // PASANDAAZ_H
