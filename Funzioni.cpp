#include "Funzioni.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void init(vector<Libro> &l) {

  ifstream input;

  input.open("Libri.txt");
  if (!input.good()){
    cout << "Errore nell'apertura del file";
    exit(0);
  }

  Libro tmp_libro;
  string tmp_string;
  float tmp_float;
  unsigned int tmp_int;

  while (tmp_string != ";"){

    getline(input, tmp_string, ',');
      tmp_libro.SetTitolo(tmp_string);
    getline(input, tmp_string, ',');
      tmp_libro.SetAutore(tmp_string);
    getline(input, tmp_string, ',');
      tmp_libro.SetISBN(tmp_string);
    input >> tmp_float;
    input.ignore(1);
      tmp_libro.SetPrezzo(tmp_float);
    input >> tmp_int;
    input.ignore(1);
      tmp_libro.SetQuantita(tmp_int);
    input >> tmp_int;
      tmp_libro.SetOrdinati(tmp_int);

    input >> tmp_string;

    l.push_back(tmp_libro);

  };

  input.close();
};

void Aggiunta_Libro(vector<Libro> &l){

  Libro tmp_libro;
  string tmp_string;
  float tmp_float = 0;
  unsigned int tmp_int = 0;

  cout << "AGGIUNTA LIBRO\n";

    cout << "Titolo: ";
    cin >> tmp_string;
      tmp_libro.SetTitolo(tmp_string);

    cout << "Autore: ";
    cin >> tmp_string;
      tmp_libro.SetAutore(tmp_string);

    cout << "ISBN: ";
    cin >> tmp_string;

    if (RicercaISBN(l, tmp_string) != -1){
      cout << "Errore, ISBN già presente.";
      exit(0);
    }

    tmp_libro.SetISBN(tmp_string);

      cout << "Prezzo: ";
    cin >> tmp_float;
      tmp_libro.SetPrezzo(tmp_float);

    cout << "Quantita in stock: ";
    cin >> tmp_int;
      tmp_libro.SetQuantita(tmp_int);

    cout << "Ordinati: ";
    cin >> tmp_int;
      tmp_libro.SetOrdinati(tmp_int);

    l.push_back(tmp_libro);

}

void PrintLibro(const Libro tmp){

  cout << tmp.GetTitolo() <<endl
       << tmp.GetAutore() <<endl
       << tmp.GetISBN() <<endl
       << tmp.GetPrezzo() <<endl
       << tmp.GetQuantita() <<endl
       << tmp.GetOrdinati() <<endl;
}

void PrintAcquisto(const Acquisto tmp){

  cout << tmp.GetISBN_Acq() << endl
       << tmp.GetNumero_tessera() << endl
       << tmp.GetPrezzo_Acq() << endl
       << tmp.GetData().Giorno << "/"
       << tmp.GetData().Mese << "/"
       << tmp.GetData().Anno << endl;
}

int RicercaISBN(vector<Libro> &l, const string tmp){

  int i = 0;

  while (i < l.size()) {
    if (tmp.compare(l.at(i).GetISBN()) == 0)
        return i;
  i++;

  }

  return(-1);
}

void Vendita(vector<Libro> &l, vector<Acquisto> &a){

  string ISBN_Venduto;
  int indice = -1;
  int tmp_int;
  float tmp_float;
  Acquisto acq;

  while (indice == -1){

    cout << "Inserire l'ISBN del libro venduto: ";

    cin >> ISBN_Venduto;

    indice = RicercaISBN(l, ISBN_Venduto);

    if (indice == -1){
        cout << "ISBN errato o inesistente!\n";
        exit(0);
    }
  }

  acq.SetISBN_Acq(ISBN_Venduto);

  cout << "Inserire numero di copie vendute: ";
  cin >> tmp_int;
  l.at(indice).RiduciQuantita(tmp_int);

  cout << "inserire il numero della tessera del cliente (0 se non tesserato): ";
  cin >> tmp_int;
  acq.SetTessera(tmp_int);

  acq.SetPrezzo_Acq(l.at(indice).GetPrezzo());

  acq.SetData();

  a.push_back(acq);

}
