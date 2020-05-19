#include <iostream>
#include <string>
#include "Funzioni.h"

using namespace std;

unsigned int Inserimento_Scelta(int max);

void Menu_Stampa(vector<Libro> &l, vector<Acquisto> &a, vector<Cliente> &c);
void Menu_GestioneDati(vector<Libro> &l, vector<Acquisto> &a, vector<Cliente> &c);
void Menu_Ordinazioni(vector<Libro> &l, vector<Acquisto> &a, vector<Cliente> &c);
void Menu_Principale(vector<Libro> &l, vector<Acquisto> &a, vector<Cliente> &c);
