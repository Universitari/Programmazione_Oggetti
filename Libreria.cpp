#include <iostream>
#include <string>
#include "Menu.h"
#include "Libro.h"

using namespace std;

int main(){

	Libro prova;

	prova.SetTitolo("Ciao");
	cout << prova.GetTitolo() << endl;

	return 0;
}
