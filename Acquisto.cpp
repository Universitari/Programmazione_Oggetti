#include <string>
#include <iostream>
#include "Acquisto.h"

using namespace std;

void Acquisto::SetPrezzo_Acq(float tmp) {

  if (Numero_tessera != 0)
    SetPrezzo(tmp - tmp/10);
    else SetPrezzo(tmp);
};
