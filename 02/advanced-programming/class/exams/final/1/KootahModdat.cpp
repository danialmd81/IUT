#include "KootahModdat.h"

KootahModdat::KootahModdat(double percerntt)
{
    percent = percerntt;
}
const double KootahModdat::etebar()
{
    return ref_mojoodi() + percent * ref_mojoodi();
}
const double KootahModdat::operator+(KootahModdat object)
{
    return etebar() + object.etebar();
}

;
