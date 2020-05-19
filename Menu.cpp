#include <iostream>
#include <string>
#include "Menu.h"
#include "rlutil.h"

using namespace std;

void Menu_Principale(vector<Libro> &l, vector<Acquisto> &a, vector<Cliente> &c) {

	unsigned int scelta = 0;

	rlutil::cls();

	rlutil::setColor(3);
	cout << "MENU PRINCIPALE\n";

	rlutil::resetColor();
	cout <<	"1. Ricerca libro\n"
					"2. Gestisci dati\n"
					"3. Visualizza dati\n"
					"4. Salva\n"
					"0. Esci\n"
					"Inserisci un numero... ";

	scelta = Inserimento_Scelta(4);

	switch(scelta) {

		case(1):{

        string tmp_string;
        unsigned int i;

				rlutil::cls();

        cout << "Inserisci l'ISBN del libro: ";
				getline(cin, tmp_string);

        i = RicercaISBN(l, tmp_string);

				if (i == -1){
					cout << "ISBN non presente!\n"
									"Premi qualsiasi tasto per tornare al menu...";
					rlutil::anykey();
				} else{

					PrintLibro(l.at(i));
					cout << "Premi qualsiasi tasto per tornare al menu...";
					rlutil::anykey();
					}

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

	rlutil::cls();

	rlutil::setColor(3);
	cout << "MENU GESTIONE DATI\n";

	rlutil::resetColor();
	cout << "1. Aggiungi Libro\n"
	        "2. Aggiungi Cliente\n"
	        "3. Vendi libro\n"
	        "4. Elimina Cliente\n"
	        "5. Gestisci Ordinazioni\n"
					"0. Indietro\n"
					"Inserisci un numero... ";

  scelta = Inserimento_Scelta(5);

	switch(scelta) {

	    case(1):

				rlutil::cls();
        Aggiunta_Libro(l);
        break;

	    case(2):

				rlutil::cls();
        Aggiunta_Cliente(c);
        break;

	    case(3):

				rlutil::cls();
        Vendita(l, a);
        break;

			case(4):

				rlutil::cls();
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

  rlutil::cls();

	rlutil::setColor(3);
	cout << "MENU ORDINAZIONI\n";

	rlutil::resetColor();
	cout << "1. Aggiungi libri ordinati\n"
	        "2. Libri arrivati\n"
					"0. Indietro\n"
					"Inserisci un numero... ";

  scelta = Inserimento_Scelta(2);

	switch(scelta){

	    case(1):

				rlutil::cls();
	    	OrdinaLibri(l);
	    	break;

	    case(2):

				rlutil::cls();
				LibriArrivati(l);
	      break;

	   default:
	      return;
	};

	Menu_Ordinazioni(l, a, c);
}

void Menu_Stampa(vector<Libro> &l, vector<Acquisto> &a, vector<Cliente> &c){

	unsigned int scelta = 0;

	rlutil::cls();

	rlutil::setColor(3);
	cout << "MENU VISUALIZZAZIONE DATI\n";

	rlutil::resetColor();
	cout << "1. Stampa lista libri\n"
	        "2. Stampa lista clienti\n"
	        "3. Stampa lista acquisti\n"
					"0. Indietro\n"
					"Inserisci un numero... ";

scelta = Inserimento_Scelta(3);

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

unsigned int Inserimento_Scelta(int max){

	unsigned int scelta;

	do{

		scelta = Input_int();

		if (scelta <= max)
			return scelta;

		rlutil::setColor(4);
		cout << "Numero non valido. ";
		rlutil::resetColor();
		cout <<	"Inserisci un numero... ";

	} while (true);

}
