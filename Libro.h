#include <string>

using namespace std;

class Libro {

  private:

    string Titolo = "";
    string Autore = "";
    string ISBN = "";
    float Prezzo = 0;
    unsigned int Quantita = 0;
    unsigned int Ordinati = 0;

  public:
// Funzioni per la gestione delle variabili private
    void SetTitolo(string tmp) {Titolo = tmp;};
    void SetAutore(string tmp) {Autore = tmp;};
    void SetISBN(string tmp) {ISBN = tmp;};
    void SetPrezzo(float tmp) {Prezzo = tmp;};
    void SetQuantita(unsigned int tmp) {Quantita = tmp;};
    void SetOrdinati(unsigned int tmp) {Ordinati = tmp;};

    string GetTitolo() const {return Titolo;};
    string GetAutore() const {return Autore;};
    string GetISBN() const {return ISBN;};
    float GetPrezzo() const {return Prezzo;};
    unsigned int GetQuantita() const {return Quantita;};
    unsigned int GetOrdinati() const {return Ordinati;};

    void RiduciQuantita(int tmp) {Quantita = Quantita - tmp;};

    Libro& operator=(const Libro &tmp);

};
