#include <iostream>
#include <string>
#include "Menu.h"

using namespace std;

void Menu_Principale() {

	unsigned int scelta = 0;

	cout << "MENU PRINCIPALE\n\n"
			"1. Ricerca Libro\n"
			"2. Aggiungi Libro\n"
			"3. Salvataggio cambiamenti";


	switch(scelta) {

		case(1):
				Ricerca();
				break;

		case(2):
				Aggiunta_Libro();
				break;

		case(3):
				Salvataggio();
				break;
		default:
			return;
	}


}
