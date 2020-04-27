#include "Funzioni.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void init() {

  ifstream input;


};

void PrintLibro(const Libro tmp){

  cout << tmp.GetTitolo() <<endl
       << tmp.GetISBN() <<endl
       << tmp.GetStato() <<endl
       << tmp.GetAutore() <<endl
       << tmp.GetPrezzo() <<endl
       << tmp.GetOrdinati() <<endl
       << tmp.GetQuantita();
}
