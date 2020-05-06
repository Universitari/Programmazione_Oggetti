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


	/*
	Libro prova0, prova1, prova2;

	prova0.SetTitolo("uno");
	cout << prova0.GetTitolo() << endl;

	prova1.SetTitolo("due");
	cout << prova1.GetTitolo() << endl;

	prova2.SetTitolo("tre");
	cout << prova2.GetTitolo() << endl;


vector<Libro> array;

array.push_back(prova0);
array.push_back(prova1);
array.push_back(prova2);
array.push_back(prova0);
array.push_back(prova1);

cout << "capacity: " << array.capacity() << " "
     << "size: " << array.size() << endl;

array.erase(array.begin() + 1);
array.shrink_to_fit();

cout << "capacity: " << array.capacity() << " "
     << "size: " << array.size() << endl;

PrintLibro(array.at(0));
PrintLibro(array.at(1));
PrintLibro(array.at(2));
*/

	return 0;
}
