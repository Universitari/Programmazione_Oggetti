#include <string>
#include "Libro.h"

using namespace std;

Libro& Libro::operator=(const Libro &tmp ){

  if (this != &tmp){

    Titolo = tmp.Titolo;
    Autore = tmp.Autore;
    ISBN = tmp.ISBN;
    Prezzo = tmp.Prezzo;
    Quantita = tmp.Quantita;
    Ordinati = tmp.Ordinati;
  }
    return *this;
}
