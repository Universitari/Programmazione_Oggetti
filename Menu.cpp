#include <iostream>
#include <string>
#include "Menu.h"

using namespace std;

void Menu_Principale(vector<Libro> &l, vector<Acquisto> &a, vector<Cliente> &c) {

	unsigned int scelta = 0;

	cout << "MENU PRINCIPALE\n\n"
					"1. Ricerca libri\n"
					"2. Gestisci dati\n"
					"3. Visualizza dati\n"
					"4. Salva\n"
					"0. Esci\n";

    cin >> scelta;
    cin.ignore();

	switch(scelta) {

		case(1):{

		        string tmp_string;
		        unsigned int i;

                cout << "Inserisci l'ISBN del libro: ";
                cin >> tmp_string;

                i = RicercaISBN(l, tmp_string);

								if (i == -1)
									cout << "ISBN non presente!\n";
								else
									PrintLibro(l.at(i));
				break;
		}

		case(2):

				Menu_GestioneDati(l, a, c);
				break;

		case(3):

				Menu_Stampa(l, a, c);
				break;

		case(4):

				save_l(l);
				save_a(a);
				save_c(c);
				break;
		default:
			return;

	  case(0):
				exit(0);
	}

    Menu_Principale(l, a, c);

}

void Menu_GestioneDati(vector<Libro> &l, vector<Acquisto> &a, vector<Cliente> &c){

    unsigned int scelta = 0;

	cout << "MENU GESTIONE DATI\n\n"
	        "1. Aggiungi Libro\n"
	        "2. Aggiungi Cliente\n"
	        "3. Vendi libro\n"
	        "4. Elimina Cliente\n"
	        "5. Gestisci Ordinazioni\n"
					"0. Indietro\n";


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

						 Menu_Ordinazioni(l, a, c);

	    default:
	            return;
	};

    Menu_GestioneDati(l, a, c);
}

void Menu_Ordinazioni(vector<Libro> &l, vector<Acquisto> &a, vector<Cliente> &c){

    unsigned int scelta = 0;

	cout << "MENU ORDINAZIONI\n\n"
	        "1. Aggiungi libri ordinati\n"
	        "2. Libri arrivati"
					"0. Indietro\n";


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

	Menu_Ordinazioni(l, a, c);
}

void Menu_Stampa(vector<Libro> &l, vector<Acquisto> &a, vector<Cliente> &c){

	unsigned int scelta = 0;

	cout << "MENU VISUALIZZAZIONE DATI\n\n"
	        "1. Stampa lista libri\n"
	        "2. Stampa lista clienti\n"
	        "3. Stampa lista acquisti\n"
					"0. Indietro\n";


    cin >> scelta;
    cin.ignore();

	switch(scelta){

	    case(1):

				break;

	    case(2):

				break;

	    case(3):

				break;

			default:
				return;
	}
}
