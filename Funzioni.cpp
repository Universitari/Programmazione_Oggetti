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

  while (input >> tmp_string){

      tmp_libro.SetTitolo(tmp_string);
    input >> tmp_string;
      tmp_libro.SetAutore(tmp_string);
    input >> tmp_string;
      tmp_libro.SetISBN(tmp_string);
    input >> tmp_string;
      tmp_libro.SetPrezzo(tmp_float);
    input >> tmp_int;
      tmp_libro.SetQuantita(tmp_int);
    input >> tmp_int;
      tmp_libro.SetOrdinati(tmp_int);

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

void Vendita(vector<Libro> &l, vector<Acquisti> &a){

  string ISBN_Venduto;
  int indice = -1;
  int copie_vendute;
  Acquisti tmp;

  while (indice == -1){

    cout << "Inserire l'ISBN del libro venduto: ";

    cin >> ISBN_Venduto;

    indice = RicercaISBN(ISBN_Venduto);

    if (indice == -1)
        cout << "ISBN errato o inesistente!\n";
  }

  cout << "Inserire numero di copie vendute: ";
  cin >> copie_vendute;

  l.at(indice).RiduciQuantita(copie_vendute);

  tmp.SetISBN_Acq(ISBN_Venduto);
  tmp.SetTessera();
  tmp.SetPrezzo_Acq();
  tmp.SetData();

  a.push_back(tmp);

}
