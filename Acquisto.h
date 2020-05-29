#include <string>

using namespace std;

struct Data {

    short int Giorno = 1;
    short int Mese = 1;
    short int Anno = 1900;
};

class Acquisto {

    private:

    string ISBN = "";
    unsigned int Numero_tessera = 0;
    float Prezzo = 0;
    Data DataVendita;

    public:
    /// Set ISBN dell'acquisto
    /// @param tmp variabile_temporanea per ISBN acquisto
    void SetISBN_Acq(string tmp){ ISBN = tmp;};
    /// Set Tessera del cliente
    /// @param tmp variabile_temporanea per Tessera del cliente
    void SetTessera(unsigned int tmp) {Numero_tessera = tmp;};
    /// Set Prezzo del libro
    /// @param tmp variabile_temporanea per Prezzo del libro
    void SetPrezzo(float tmp) {Prezzo = tmp;};
    /// Set Data dell'acquisto
    /// @param tmp variabile_temporanea per Data dell'acquisto
    void SetData(Data tmp) {DataVendita = tmp;};

    /// Get ISBN dell'acquisto
    /// @returns ISBN acquisto
    string GetISBN_Acq() const {return ISBN;};
    /// Get Numero tessera del cliente
    /// @returns Numero tessera del cliente
    unsigned int GetNumero_tessera() const {return Numero_tessera;};
    /// Get Prezzo del libro
    /// @returns Prezzo del libro
    float GetPrezzo_Acq() const {return Prezzo;};
    /// Get Data dell'acquisto
    /// @returns Data dell'acquisto
    Data GetData() const {return DataVendita;};
    
    /// Set Prezzo_Acq
    /// @param tmp Prezzo_Acq 
    void SetPrezzo_Acq(float tmp);
};
