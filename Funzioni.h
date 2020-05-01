#include <string>
#include <vector>
#include <iostream>
#include "Libro.h"
#include "Acquisti.h"

using namespace std;

void init(vector<Libro> &l);
void PrintLibro(const Libro tmp);
void Aggiunta_Libro(vector<Libro> &l);
void Vendita(vector<Libro> &l, vector<Acquisti> &a);
