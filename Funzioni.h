#include <string>
#include <vector>
#include <iostream>
#include "Libro.h"
#include "Acquisto.h"
#include "Cliente.h"
#include "rlutil.h"


using namespace std;

int Input_int();
float Input_float();
bool File_Vuoto(ifstream& input);

void init_l(vector<Libro> &l);
void init_a(vector<Acquisto> &a);
void init_c(vector<Cliente> &c);


void Aggiunta_Libro(vector<Libro> &l);
void Aggiunta_Cliente(vector<Cliente> &c);
void EliminaCliente(vector<Cliente> &c);

void PrintLibro(const Libro tmp);
void PrintAcquisto(const Acquisto tmp);
void PrintCliente(const Cliente tmp);

int RicercaISBN(vector<Libro> &l, const string tmp);
int RicercaTessera(vector<Cliente> &c, unsigned int tessera);
void Vendita(vector<Libro> &l, vector<Acquisto> &a);
void OrdinaLibri(vector<Libro> &l);
void LibriArrivati(vector<Libro> &l);

short int MaxGiorno(short int m, short int y);
Data InserimentoData();

void save_l(vector<Libro> &l);
void save_a(vector<Acquisto> &a);
void save_c(vector<Cliente> &c);
