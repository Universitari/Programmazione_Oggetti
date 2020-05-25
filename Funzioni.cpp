#include "Funzioni.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

// Inizializzazione di un vettore di "Libro" dal file "Libri.txt"
void init_l(vector<Libro> &l) {

  ifstream input;

  // Apertura file.
  input.open("Libri.txt");
  // Controllo dell'apertura del file.
  if (!input.good()){
    cout << "Errore nell'apertura del file";
    exit(0);
  };

  // In caso di file vuoto il vettore di "Libro" rimarrà vuoto.
  if (File_Vuoto(input)){
    input.close();
    return;
  }

  Libro tmp_libro;
  string tmp_string = "";
  float tmp_float;
  unsigned int tmp_int;

  // Estrazione dei dati dal file di testo.
  while (tmp_string != ";"){

    // Titolo
    getline(input, tmp_string, ',');      // getline che legge fino ad una virgola
      tmp_libro.SetTitolo(tmp_string);
    // Autore
    getline(input, tmp_string, ',');
      tmp_libro.SetAutore(tmp_string);
    // ISBN
    getline(input, tmp_string, ',');
      tmp_libro.SetISBN(tmp_string);
    // Prezzo
    input >> tmp_float;                   // Operatore >> estrae il numero
    input.ignore(1);                      // e ignore(1) salta la virgola
      tmp_libro.SetPrezzo(tmp_float);
    // Quantità in stock
    input >> tmp_int;
    input.ignore(1);
      tmp_libro.SetQuantita(tmp_int);
    // Quantità ordinati
    input >> tmp_int;
      tmp_libro.SetOrdinati(tmp_int);

    input >> tmp_string;
    input.ignore();

    l.push_back(tmp_libro);               // Il libro viene aggiunto in coda al vettore

  };

  // Chiusuar input
  input.close();
};

// Inizializzazione di un vettore di "Acquisto" dal file "Acquisti.txt"
void init_a(vector<Acquisto> &a) {

  ifstream input;

  input.open("Acquisti.txt");
  if (!input.good()){
    cout << "Errore nell'apertura del file";
    exit(0);
  }

  if (File_Vuoto(input)){
    input.close();
    return;
  }

  Acquisto tmp_acquisto;
  string tmp_string = "";
  unsigned int tmp_int;
  float tmp_float;
  Data tmp_data;

  while (tmp_string != ";"){

    getline(input, tmp_string, ',');
        tmp_acquisto.SetISBN_Acq(tmp_string);

    input >> tmp_int;
        input.ignore(1);
            tmp_acquisto.SetTessera(tmp_int);

    input >> tmp_float;
        input.ignore(1);
            tmp_acquisto.SetPrezzo(tmp_float);

    input >> tmp_data.Giorno;
      input.ignore(1);

    input >> tmp_data.Mese;
      input.ignore(1);

    input >> tmp_data.Anno;
        tmp_acquisto.SetData(tmp_data);

    input >> tmp_string;

    input.ignore();

    a.push_back(tmp_acquisto);
  };

  input.close();
};

// Inizializzazione di un vettore di "Cliente" dal file "Clienti.txt"
void init_c(vector<Cliente> &c){

  ifstream input;

  input.open("Clienti.txt");
  if (!input.good()){
    cout << "Errore nell'apertura del file";
    exit(0);
  }

  if (File_Vuoto(input)){
    input.close();
    return;
  }

  Cliente tmp_cliente;
  string tmp_string = "";
  unsigned int tmp_int;

  input >> tmp_int;
  input.ignore(1);
  tmp_cliente.Set_MaxClienti(tmp_int);

  while (tmp_string != ";"){

    getline(input, tmp_string, ',');
      tmp_cliente.SetNome(tmp_string);
    getline(input, tmp_string, ',');
      tmp_cliente.SetCognome(tmp_string);
    getline(input, tmp_string, ',');
      tmp_cliente.SetEmail(tmp_string);
    input >> tmp_int;
      tmp_cliente.SetTessera(tmp_int);

    input >> tmp_string;

    input.ignore();

    c.push_back(tmp_cliente);

}

  input.close();

}

// Aggiunta di un nuovo elemento nel vettore di "Libro"
void Aggiunta_Libro(vector<Libro> &l){

  Libro tmp_libro;
  string tmp_string;
  float tmp_float = 0;
  unsigned int tmp_int = 0;
  bool flag=true;
  char tmp_char;

  cout << "AGGIUNTA LIBRO\n";

    cout << "Titolo: ";
    getline(cin, tmp_string);
      tmp_libro.SetTitolo(tmp_string);

    cout << "Autore: ";
    getline(cin, tmp_string);
      tmp_libro.SetAutore(tmp_string);

    cout << "ISBN: ";
    getline(cin, tmp_string);

    if (RicercaISBN(l, tmp_string) != -1){
      cout << "Errore, ISBN già presente.";
      return;
    }

    tmp_libro.SetISBN(tmp_string);

    cout << "Prezzo: ";
    tmp_float = Input_float();
      tmp_libro.SetPrezzo(tmp_float);

    cout << "Quantita in stock: ";
    tmp_int = Input_int();
      tmp_libro.SetQuantita(tmp_int);

    cout << "Ordinati: ";
    tmp_int = Input_int();
      tmp_libro.SetOrdinati(tmp_int);

    cout << "Vuoi procedere all'aggiunta di questo libro? (y/n)... ";

    do{

      cin >> tmp_char;
      cin.ignore();
      if (tmp_char == 'y' || tmp_char == 'Y'){
        flag = false;
        l.push_back(tmp_libro);
        rlutil::setColor(2);
        cout << "Aggiunta avvenuta con successo.\n";
      }
        else if (tmp_char == 'n' || tmp_char == 'N')
          flag = false;
        else
          cout << "inserire una scelta valida...";

    } while(flag);

      rlutil::setColor(15);
      cout << "Premi qualsiasi tasto per tornare al menu...";
      rlutil::anykey();

}

void PrintLibro(const Libro tmp){

  cout << left << setw(49) << setfill(' ') << tmp.GetTitolo()
       << left << setw(20) << setfill(' ') << tmp.GetISBN()
       << left << setw(8) << setfill(' ') << tmp.GetPrezzo()
       << left << setw(10) << setfill(' ') << tmp.GetQuantita()
       << left << setw(11) << setfill(' ') << tmp.GetOrdinati()
       << endl << setw(98) << setfill(' ') << tmp.GetAutore()
       << endl;
}

void PrintAcquisto(const Acquisto tmp){

  cout << left << setw(20) << setfill(' ') << tmp.GetISBN_Acq()
       << left << setw(10) << setfill(' ') << tmp.GetNumero_tessera()
       << left << setw(8) << setfill(' ') << tmp.GetPrezzo_Acq()
       << left << setw(12) << setfill(' ') << Data_to_string(tmp)
       << endl;
}

void PrintCliente(const Cliente tmp){

  cout << left << setw(20) << setfill(' ') << tmp.GetNome()
       << left << setw(30) << setfill(' ') << tmp.GetCognome()
       << left << setw(35) << setfill(' ') << tmp.GetEmail()
       << left << setw(10) << setfill(' ') << tmp.GetTessera()
       << endl;
}

int RicercaISBN(vector<Libro> &l, const string tmp){

  int i = 0;

  while (i < l.size()) {
    if (tmp.compare(l.at(i).GetISBN()) == 0)
        return i;
  i++;

  }

  return(-1);
}

void Vendita(vector<Libro> &l, vector<Acquisto> &a){

  string ISBN_Venduto;
  int indice = -1;
  int tmp_int;
  unsigned int tmp_tessera;
  float tmp_float;
  Acquisto acq;
  Data tmp_data;


  cout << "Inserire l'ISBN del libro venduto: ";

  getline(cin, ISBN_Venduto);

  indice = RicercaISBN(l, ISBN_Venduto);

  if (indice == -1){
      rlutil::setColor(4);
      cout << "ISBN errato o inesistente!\n";
      rlutil::setColor(15);
      cout << "Premi qualsiasi tasto per tornare al menu...";
      rlutil::anykey();
      return;
  }

  cout << "Inserire numero di copie vendute: ";
  tmp_int = Input_int();

  if (tmp_int > l.at(indice).GetQuantita()){

    rlutil::setColor(4);
    cout << "Errore! Sono disponibili solo " << l.at(indice).GetQuantita()
         << " copie di quel libro.\n";

    rlutil::setColor(15);
    cout << "Premi qualsiasi tasto per tornare al menu...";
    rlutil::anykey();
    return;
  };

  acq.SetISBN_Acq(ISBN_Venduto);

  l.at(indice).RiduciQuantita(tmp_int);

  cout << "inserire il numero della tessera del cliente (0 se non tesserato): ";
  tmp_tessera = Input_int();
  acq.SetTessera(tmp_tessera);

  acq.SetPrezzo_Acq(l.at(indice).GetPrezzo() * tmp_int);

  tmp_data = InserimentoData();
  acq.SetData(tmp_data);

  a.push_back(acq);

  rlutil::setColor(2);
  cout << "Vendita avvenuta con successo.\n";
  rlutil::setColor(15);
  cout << "Premi qualsiasi tasto per tornare al menu...";
  rlutil::anykey();

}

short int MaxGiorno(short int m, short int y){

	switch (m){

	    case 4:
	    case 6:
	    case 9:
	    case 11:{

		    return 30;
		    break;
	    }

    	case 2:{

    	    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
    	         return 29;
    	    else return 28;
    		break;
    	}

    	default:{

    		return 31;
    		break;
    	}


    	}
}

Data InserimentoData(){

  short int d,m,y;
  Data tmp;
  bool flag = true;

  cout << "Inserire la data della vendita\n";

  do {
  cout << "Giorno: ";
  d = Input_int();

  cout << "Mese: ";
  m = Input_int();

  cout << "Anno: ";
  y = Input_int();

  if (y < 1900){
    cout << "Anno non valido. Reinserire la data.\n";
    continue;
  }

  if (m < 1 || m > 12){
    cout << "Mese non valido. Reinserire la data.\n";
    continue;
  }

  if (d < 1 || d > MaxGiorno(m, y)){
    cout << "Giorno non valido. Reinserire la data.\n";
    continue;
  }

flag = false;

} while(flag);

tmp.Giorno = d;
tmp.Mese = m;
tmp.Anno = y;

return tmp;

}

void Aggiunta_Cliente(vector<Cliente> &c){

    string tmp_string;
    Cliente tmp_cliente;
    bool flag=true;
    char tmp_char;

    cout << "AGGIUNTA CLIENTE\n";

    cout << "Nome: ";
    getline(cin, tmp_string);
        tmp_cliente.SetNome(tmp_string);
    cin.clear();

    cout << "Cognome: ";
    getline(cin, tmp_string);
        tmp_cliente.SetCognome(tmp_string);

    cout << "e-mail: ";
    getline(cin, tmp_string);
        tmp_cliente.SetEmail(tmp_string);

    tmp_cliente.SetTessera(tmp_cliente.Get_MaxClienti()+1);
    tmp_cliente.Set_MaxClienti(tmp_cliente.Get_MaxClienti()+1);

    cout << "Tessera: " << tmp_cliente.GetTessera() << endl;

    cout << "Vuoi procedere all'aggiunta di questo cliente? (y/n)... ";

    do{

      cin >> tmp_char;
      cin.ignore();
      if (tmp_char == 'y' || tmp_char == 'Y'){
        flag = false;
        c.push_back(tmp_cliente);
        rlutil::setColor(2);
        cout << "Aggiunta avvenuta con successo.\n";
      }
        else if (tmp_char == 'n' || tmp_char == 'N')
          flag = false;
        else
          cout << "inserire una scelta valida...";

    } while(flag);

    rlutil::setColor(15);
    cout << "Premi qualsiasi tasto per tornare al menu...";
    rlutil::anykey();

}

void EliminaCliente(vector<Cliente> &c){

    int indice;
    unsigned int tessera;

      cout << "Inserire l'ID della tessera del cliente da eliminare... ";
      tessera = Input_int();

      if (tessera < c.front().GetTessera() || tessera > c.back().GetTessera()){

        rlutil::setColor(4);
        cout << "Errore! ID tessera non esistente!\n";

        rlutil::setColor(15);
        cout << "Premi qualsiasi tasto per tornare al menu...";

        rlutil::anykey();
        return;
      }

    indice = RicercaTessera(c, tessera);
    if (indice == -1){

      rlutil::setColor(4);
      cout << "Errore! ID tessera non esistente!\n";

      rlutil::setColor(15);
      cout << "Premi qualsiasi tasto per tornare al menu...";

      rlutil::anykey();
      return;
    };

    c.erase(c.begin()+indice);

    rlutil::setColor(2);
    cout << "Eliminazione avvenuta con successo.\n";
    rlutil::setColor(15);
    cout << "Premi qualsiasi tasto per tornare al menu...";
    rlutil::anykey();

}

int RicercaTessera(vector<Cliente> &c, unsigned int tessera){

    int min = 0;
    int max = c.size() - 1;
    int mid;

    while (min <= max){

        mid = (min + max) / 2;

        if (c.at(mid).GetTessera() == tessera)
            return mid;

        if (c.at(mid).GetTessera() < tessera)
            min = mid + 1;
        else max = mid -1;

    }

    return -1;
}

void save_l(vector<Libro> &l){

    ofstream output;

    output.open("Libri.txt");

    if (!output.good()){

      rlutil::setColor(4);
      cout << "Errore nell'apertura del file di output!\n";
      rlutil::setColor(15);
      exit(0);
    };

    int i;

    for (i=0; i < l.size(); i++){
        output << l.at(i).GetTitolo() << ","
               << l.at(i).GetAutore() << ","
               << l.at(i).GetISBN() << ","
               << l.at(i).GetPrezzo() << ","
               << l.at(i).GetQuantita() << ","
               << l.at(i).GetOrdinati();

        if (i == l.size() - 1)
          output << " ;";
        else output << ",\n";

    }

    output.close();
}

void save_a(vector<Acquisto> &a){

  ofstream output;

  output.open("Acquisti.txt");

  if (!output.good()){

    rlutil::setColor(4);
    cout << "Errore nell'apertura del file di output!\n";
    rlutil::setColor(15);
      exit(0);
  };

  int i;

  for (i=0; i < a.size(); i++){

      output << a.at(i).GetISBN_Acq() << ","
             << a.at(i).GetNumero_tessera() << ","
             << a.at(i).GetPrezzo_Acq() << ","
             << a.at(i).GetData().Giorno << "/"
             << a.at(i).GetData().Mese << "/"
             << a.at(i).GetData().Anno;

      if (i == a.size() - 1)
        output << " ;";
      else output << ",\n";
  }

}

void save_c(vector<Cliente> &c){

    ofstream output;

    output.open("Clienti.txt");

    if (!output.good()){
        rlutil::setColor(4);
        cout << "Errore nell'apertura del file di output!\n";
        rlutil::setColor(15);
        exit(0);
    };

    int i;

    output << c.at(0).Get_MaxClienti() << ",";

    for (i=0; i < c.size(); i++){

        output << c.at(i).GetNome() << ","
               << c.at(i).GetCognome() << ","
               << c.at(i).GetEmail() << ","
               << c.at(i).GetTessera();

        if (i == c.size() - 1)
          output << " ;";
        else output << ",\n";
    }

}

void OrdinaLibri(vector<Libro> &l){

    string tmp_string;
    int i;
    unsigned int quantita=0;

    cout << "Inserire l'ISBN del libro ordinato: ";
    getline(cin, tmp_string);

    i = RicercaISBN(l, tmp_string);

    if (i == -1){
      rlutil::setColor(4);
      cout << "ISBN errato o inesistente!\n";
      rlutil::setColor(15);
      cout << "Premi qualsiasi tasto per tornare al menu...";
      rlutil::anykey();
      return;
    }

    cout << "inserire la quantità di libri ordinati: ";
    quantita = Input_int();

    l.at(i).SetOrdinati(quantita);

}

void LibriArrivati(vector<Libro> &l){

    string tmp_string;
    int i;
    unsigned int quantita=0;

    cout << "Inserire l'ISBN dei libri arrivati: ";
    getline(cin, tmp_string);

    i = RicercaISBN(l, tmp_string);

    if (i == -1){
      rlutil::setColor(4);
      cout << "ISBN errato o inesistente!\n";
      rlutil::setColor(15);
      cout << "Premi qualsiasi tasto per tornare al menu...";
      rlutil::anykey();
      return;
    }

    cout << "inserire la quantità di libri arrivati: ";
    quantita = Input_int();

    if (quantita > l.at(i).GetOrdinati()){

      rlutil::setColor(4);
      cout << "Errore! Sono state ordinate solo " << l.at(i).GetOrdinati()
           << " copie di quel libro\n";

      rlutil::setColor(15);
      cout << "Premi qualsiasi tasto per tornare al menu...";
      rlutil::anykey();

      return;
    }

    l.at(i).SetOrdinati(l.at(i).GetOrdinati() - quantita);
    l.at(i).SetQuantita(l.at(i).GetQuantita() + quantita);

}

string Data_to_string(Acquisto a){

  string tmp_string;

  tmp_string = to_string(a.GetData().Giorno);
  tmp_string += "/";
  tmp_string += to_string(a.GetData().Mese);
  tmp_string += "/";
  tmp_string += to_string(a.GetData().Anno);

  return tmp_string;
}

int Input_int(){

  int x;

  while (!(cin >> x)){

    rlutil::setColor(4);
    cout << "Input non valido. ";

    rlutil::setColor(15);
    cout << "Inserisci un valore intero... ";

    cin.clear();
    cin.ignore(256, '\n');
  }

  cin.ignore();
  return x;

}

//Funzione di controllo per input float errati
float Input_float(){

  float x;

  while (!(cin >> x)){

    rlutil::setColor(4);
    cout << "Input non valido. ";

    rlutil::setColor(15);
    cout << "Inserisci un valore numerico... ";

    cin.clear();
    cin.ignore(256, '\n');
  }

  cin.ignore();
  return x;

}

//Funzione utilizzata nelle inizializzazioni
//Controlla se un file è vuoto
bool File_Vuoto(ifstream& input){

    return input.peek() == ifstream::traits_type::eof();

}

//Funzione di stampa dei libri in menù visualizzazione
void StampaLibri(const vector<Libro> &l){

  int i;

  rlutil::setColor(3);

//Formattazione della tabella
  cout << left << setw(49) << setfill(' ') << "Titolo, Autore"
       << left << setw(20) << setfill(' ') << "ISBN"
       << left << setw(8) << setfill(' ') << "Prezzo"
       << left << setw(10) << setfill(' ') << "Q. stock"
       << left << setw(11) << setfill(' ') << "Q. ordinata"
       << endl;

  rlutil::setColor(15);

  for (i = 0; i < l.size(); i++ ){

    if (i%2 == 1){
      rlutil::setBackgroundColor(7);
      rlutil::setColor(0);
    } else rlutil::resetColor();
	  
//Chimata della stampa primaria
    PrintLibro(l.at(i));

  }

  rlutil::resetColor();

}

//Funzione di stampa degli acquisti in menù visualizzazione
void StampaAcquisti(const vector<Acquisto> &a){

  int i;

  rlutil::setColor(3);

//Formattazione della tabella
  cout << left << setw(20) << setfill(' ') << "ISBN"
       << left << setw(10) << setfill(' ') << "Tessera"
       << left << setw(8) << setfill(' ') << "Prezzo"
       << left << setw(12) << setfill(' ') << "Data"
       << endl;

  rlutil::setColor(15);

  for (i = 0; i < a.size(); i++ ){

    if (i%2 == 1){
      rlutil::setBackgroundColor(7);
      rlutil::setColor(0);
    } else rlutil::resetColor();
  
//Chimata della stampa primaria
    PrintAcquisto(a.at(i));

  }

  rlutil::resetColor();

}

//Funzione di stampa dei clienti in menù visualizzazione
void StampaClienti(const vector<Cliente> &c){

  int i;

  rlutil::setColor(3);
	
//Formattazione della tabella
  cout << left << setw(20) << setfill(' ') << "Nome"
       << left << setw(30) << setfill(' ') << "Cognome"
       << left << setw(35) << setfill(' ') << "Email"
       << left << setw(10) << setfill(' ') << "Tessera"
       << endl;

  rlutil::setColor(15);

  for (i = 0; i < c.size(); i++ ){

    if (i%2 == 1){
      rlutil::setBackgroundColor(7);
      rlutil::setColor(0);
    } else rlutil::resetColor();
	  
//Chimata della stampa primaria
    PrintCliente(c.at(i));

  }

  rlutil::resetColor();

}
