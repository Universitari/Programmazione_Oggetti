#include <string>
#include <vector>
#include <iostream>
#include "Libro.h"
#include "Acquisto.h"
#include "Cliente.h"

using namespace std;

void init_l(vector<Libro> &l);
void init_a(vector<Acquisto> &a);
void init_c(vector<Cliente> &c);
void Aggiunta_Libro(vector<Libro> &l);
void PrintLibro(const Libro tmp);
void PrintAcquisto(const Acquisto tmp);
void PrintCliente(const Cliente tmp);
int RicercaISBN(vector<Libro> &l, const string tmp);
void Vendita(vector<Libro> &l, vector<Acquisto> &a);
short int MaxGiorno(short int m, short int y);
Data InserimentoData();
