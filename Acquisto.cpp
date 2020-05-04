#include <string>
#include <iostream>
#include "Acquisto.h"

using namespace std;

void Acquisto::SetPrezzo_Acq(float tmp) {

  if (Numero_tessera != 0)
    Prezzo = (tmp - tmp/10);
    else Prezzo = tmp;
};

void Acquisto::SetData() {

  cout << "inserire la data della vendita\n"
       << "Giorno: ";
  cin >> DataVendita.Giorno;

  cout << "Mese: ";
  cin >> DataVendita.Mese;

  cout << "Anno: ";
  cin >> DataVendita.Anno;

};
