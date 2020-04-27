#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"
#include "Funzioni.h"

using namespace std;

int main(){

	Libro prova, prova2;

	prova.SetTitolo("Ciao");
	cout << prova.GetTitolo() << endl;


vector<Libro> array;

array.reserve(10);
array.push_back(prova);

PrintLibro(prova);
PrintLibro(prova2);

	return 0;
}
