#include <string>

using namespace std;

struct Data {

    short int Giorno;
    short int Mese;
    short int Anno;
};

class Acquisto {

    private:

    string ISBN = "";
    unsigned int Numero_tessera = 0;
    float Prezzo = 0;
    Data DataVendita;

    public:

    void SetISBN_Acq(string tmp){ ISBN = tmp;};
    void SetTessera(unsigned int tmp) {Numero_tessera = tmp;};
    void SetPrezzo(float tmp) {Prezzo = tmp;};
    void SetData(Data tmp) {DataVendita = tmp;};

    string GetISBN_Acq() const {return ISBN;};
    unsigned int GetNumero_tessera() const {return Numero_tessera;};
    float GetPrezzo_Acq() const {return Prezzo;};
    Data GetData() const {return DataVendita;};

    void SetPrezzo_Acq(float tmp);
};
