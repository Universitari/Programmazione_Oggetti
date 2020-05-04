#include <string>
#include <vector>
#include <iostream>
#include "Libro.h"
#include "Acquisto.h"

using namespace std;

void init(vector<Libro> &l);
void Aggiunta_Libro(vector<Libro> &l);
void PrintLibro(const Libro tmp);
void PrintAcquisto(const Acquisto tmp);
int RicercaISBN(vector<Libro> &l, const string tmp);
void Vendita(vector<Libro> &l, vector<Acquisto> &a);
