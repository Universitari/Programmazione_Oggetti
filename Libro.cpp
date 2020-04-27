#include <string>
#include "Libro.h"

using namespace std;

string Libro::GetStato() {

  if (Quantita == 0)
    return "Esaurito";

  else if (Quantita == 0 && Ordinati != 0)
          return "In arrivo";
  else
      return "Disponibile";
}

Libro& Libro::operator=(const Libro &tmp ){

  if (this != &tmp){

    Titolo = tmp.Titolo;
    Autore = tmp.Autore;
    ISBN = tmp.ISBN;
    Stato = tmp.Stato;
    Prezzo = tmp.Prezzo;
    Quantita = tmp.Quantita;
    Ordinati = tmp.Ordinati;
  }
    return *this;
}
