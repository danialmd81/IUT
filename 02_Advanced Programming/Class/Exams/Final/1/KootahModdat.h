#ifndef KOOTAHMODDAT_H
#define KOOTAHMODDAT_H

#include "PasAndaaz.h"

class KootahModdat : public PasAndaaz {
  private:
  public:
    KootahModdat(double percerntt = 0.11);
    const double etebar();
    const double operator+(KootahModdat object);
};

#include "KootahModdat.cpp"

#endif // KOOTAHMODDAT_H
