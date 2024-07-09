#include "PasAndaaz.h"

PasAndaaz::PasAndaaz() { percent = 0; }

const double PasAndaaz::etebar() {
    return ref_mojoodi() + percent * ref_mojoodi();
}
