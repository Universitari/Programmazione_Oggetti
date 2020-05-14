#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"
#include "Funzioni.h"

using namespace std;

int main(){

	vector<Libro> lista_libri;
	vector<Acquisto> lista_acquisti;
	vector<Cliente> lista_clienti;

	init_l(lista_libri);
	init_a(lista_acquisti);
	init_c(lista_clienti);

	Vendita(lista_libri, lista_acquisti);
	save_a(lista_acquisti);
	save_c(lista_clienti);
	save_l(lista_libri);

	return 0;
}
