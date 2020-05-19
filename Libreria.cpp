#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"

using namespace std;

int main(){

	vector<Libro> lista_libri;
	vector<Acquisto> lista_acquisti;
	vector<Cliente> lista_clienti;

	init_l(lista_libri);
	init_a(lista_acquisti);
	init_c(lista_clienti);

	Menu_Principale(lista_libri, lista_acquisti, lista_clienti);

	return 0;
}
