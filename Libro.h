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
    /// set Titolo del libro
    /// @param tmp variabile temporanea del Titolo libro
    void SetTitolo(string tmp) {Titolo = tmp;};
    /// set Autore del libro
    /// @param tmp variabile temporanea dell'Autore libro
    void SetAutore(string tmp) {Autore = tmp;};
    /// set ISBN del libro
    /// @param tmp variabile temporanea dell'ISBN libro
    void SetISBN(string tmp) {ISBN = tmp;};
    /// set Prezzo del libro
    /// @param tmp variabile temporanea del Prezzo libro
    void SetPrezzo(float tmp) {Prezzo = tmp;};
    /// set Quantità del libro
    /// @param tmp variabile temporanea della Quantità libro
    void SetQuantita(unsigned int tmp) {Quantita = tmp;};
    /// set Ordinati del libro
    /// @param tmp variabile temporanea per gli Ordinati libro
    void SetOrdinati(unsigned int tmp) {Ordinati = tmp;};
    
    /// Get Titolo del libro
    /// @returns Titolo libro
    string GetTitolo() const {return Titolo;};
    /// Get Autore del libro
    /// @returns Titolo libro
    string GetAutore() const {return Autore;};
    /// Get ISBN del libro
    /// @returns ISBN libro
    string GetISBN() const {return ISBN;}; 
    /// Get Prezzo del libro
    /// @returns Prezzo libro
    float GetPrezzo() const {return Prezzo;}; 
    /// Get Quantità del libro
    /// @returns Quantità libro
    unsigned int GetQuantita() const {return Quantita;};
    /// Get Ordinati del libro
    /// @returns Ordinati libro
    unsigned int GetOrdinati() const {return Ordinati;};
    
    /// Get Titolo libro
    /// @returns Titolo libro
    void RiduciQuantita(int tmp) {Quantita = Quantita - tmp;};

    Libro& operator=(const Libro &tmp);

};
