#include <iostream>
#include <string>
#include "Menu.h"

using namespace std;

void Menu_Principale(vector<Libro> &l, vector<Cliente> &c, vector<Acquisto> &a) {

	unsigned int scelta = 0;

	cout << "MENU PRINCIPALE\n\n"
			"1. Ricerca libri\n"
			"2. Gestione Dati\n"
			"3. Salvataggio cambiamenti\n";

    cin >> scelta;
    cin.ignore();

	switch(scelta) {

		case(1):{

		        string tmp_string;
		        unsigned int i;

                cout << "Inserisci l'ISBN del libro: ";
                cin >> tmp_string;

                i = RicercaISBN(l, tmp_string);
                PrintLibro(l.at(i));
				break;
		}

		case(2):

				Menu_GestioneDati(l, c, a);
				break;

		case(3):

				save_l(l);
				save_a(a);
				save_c(c);
				break;
		default:
			return;
	}

    Menu_Principale(l, c, a);

}

void Menu_GestioneDati(vector<Libro> &l, vector<Cliente> &c, vector<Acquisto> &a){

    unsigned int scelta = 0;

	cout << "MENU GESTIONE DATI\n\n"
	        "1. Aggiunta Libro\n"
	        "2. Aggiunta Cliente\n"
	        "3. Vendita libro\n"
	        "4. Elimina Cliente\n"
	        "5. Gestione Ordinazioni\n";


    cin >> scelta;
    cin.ignore();

	switch(scelta) {

	    case(1):

	            Aggiunta_Libro(l);
	            break;

	    case(2):

	            Aggiunta_Cliente(c);
	            break;

	    case(3):

	            Vendita(l, a);
	            break;

			case(4):

					   EliminaCliente(c);
					   break;

			case(5):

						 Menu_Ordinazioni(l, c, a);

	    default:
	            return;
	};

    Menu_GestioneDati(l, c, a);
}

void Menu_Ordinazioni(vector<Libro> &l, vector<Cliente> &c, vector<Acquisto> &a){

    unsigned int scelta = 0;

	cout << "MENU ORDINAZIONI\n\n"
	        "1. Aggiungi libri ordinati\n"
	        "2. Libri arrivati";


    cin >> scelta;
    cin.ignore();

	switch(scelta){

	    case(1):

	            OrdinaLibri(l);
	            break;

	    case(2):

	            LibriArrivati(l);
	            break;

	   default:
	        return;
	};

	Menu_Ordinazioni(l, c, a);
}
