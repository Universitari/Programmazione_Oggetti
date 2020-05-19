#include "Funzioni.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void init_l(vector<Libro> &l) {

  ifstream input;

  input.open("Libri.txt");
  if (!input.good()){
    cout << "Errore nell'apertura del file";
    exit(0);
  };

  Libro tmp_libro;
  string tmp_string = "";
  float tmp_float;
  unsigned int tmp_int;

  while (tmp_string != ";"){

    getline(input, tmp_string, ',');
      tmp_libro.SetTitolo(tmp_string);
    getline(input, tmp_string, ',');
      tmp_libro.SetAutore(tmp_string);
    getline(input, tmp_string, ',');
      tmp_libro.SetISBN(tmp_string);
    input >> tmp_float;
    input.ignore(1);
      tmp_libro.SetPrezzo(tmp_float);
    input >> tmp_int;
    input.ignore(1);
      tmp_libro.SetQuantita(tmp_int);
    input >> tmp_int;
      tmp_libro.SetOrdinati(tmp_int);

    input >> tmp_string;
    input.ignore();

    l.push_back(tmp_libro);

  };

  input.close();
};

void init_a(vector<Acquisto> &a) {

  ifstream input;

  input.open("Acquisti.txt");
  if (!input.good()){
    cout << "Errore nell'apertura del file";
    exit(0);
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

void init_c(vector<Cliente> &c){

  ifstream input;

  input.open("Clienti.txt");
  if (!input.good()){
    cout << "Errore nell'apertura del file";
    exit(0);
  }

  Cliente tmp_cliente;
  string tmp_string = "";
  unsigned int tmp_int;

  input >> tmp_int;
  tmp_cliente.SetID(tmp_int);

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

void Aggiunta_Libro(vector<Libro> &l){

  Libro tmp_libro;
  string tmp_string;
  float tmp_float = 0;
  unsigned int tmp_int = 0;

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
    cin >> tmp_float;
      tmp_libro.SetPrezzo(tmp_float);

    cout << "Quantita in stock: ";
    cin >> tmp_int;
      tmp_libro.SetQuantita(tmp_int);

    cout << "Ordinati: ";
    cin >> tmp_int;
      tmp_libro.SetOrdinati(tmp_int);

    cin.ignore();

    l.push_back(tmp_libro);

}

void PrintLibro(const Libro tmp){

  cout << tmp.GetTitolo() <<endl
       << tmp.GetAutore() <<endl
       << tmp.GetISBN() <<endl
       << tmp.GetPrezzo() <<endl
       << tmp.GetQuantita() <<endl
       << tmp.GetOrdinati() <<endl;
}

void PrintAcquisto(const Acquisto tmp){

  cout << tmp.GetISBN_Acq() << endl
       << tmp.GetNumero_tessera() << endl
       << tmp.GetPrezzo_Acq() << endl
       << tmp.GetData().Giorno << "/"
       << tmp.GetData().Mese << "/"
       << tmp.GetData().Anno << endl;
}

void PrintCliente(const Cliente tmp){

  cout << tmp.GetNome() <<endl
       << tmp.GetCognome() <<endl
       << tmp.GetEmail() <<endl
       << tmp.GetTessera() <<endl;
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
        cout << "ISBN errato o inesistente!\n"
                "Premi qualsiasi tasto per tornare al menu...";
        rlutil::anykey();
        return;
    }

  cout << "Inserire numero di copie vendute: ";
  cin >> tmp_int;

  if (tmp_int > l.at(indice).GetQuantita()){
    cout << "Sono disponibili solo " << l.at(indice).GetQuantita()
         << " copie di quel libro.";
    return;
  };

  acq.SetISBN_Acq(ISBN_Venduto);

  l.at(indice).RiduciQuantita(tmp_int);

  cout << "inserire il numero della tessera del cliente (0 se non tesserato): ";
  cin >> tmp_tessera;
  acq.SetTessera(tmp_tessera);

  acq.SetPrezzo_Acq(l.at(indice).GetPrezzo() * tmp_int);

  tmp_data = InserimentoData();
  acq.SetData(tmp_data);

  a.push_back(acq);

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
  cin >> d;

  cout << "Mese: ";
  cin >> m;

  cout << "Anno: ";
  cin >> y;

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

    tmp_cliente.SetTessera(tmp_cliente.GetID()+1);
    tmp_cliente.SetID(tmp_cliente.GetID()+1);

    c.push_back(tmp_cliente);

}

void EliminaCliente(vector<Cliente> &c){

    int indice;
    unsigned int tessera;

      cout << "Inserire l'ID della tessera del cliente da eliminare: ";
      cin >> tessera;
      cin.ignore();

      if (tessera < c.front().GetTessera() || tessera > c.back().GetTessera()){
        cout << "Errore! ID tessera non esistente!\n"
             << "Premi qualsiasi tasto per tornare al menu...";
        rlutil::anykey();
        return;
      }

    indice = RicercaTessera(c, tessera);
    if (indice == -1){
      cout << "Errore! ID tessera non esistente!\n"
           << "Premi qualsiasi tasto per tornare al menu...";
      rlutil::anykey();
      return;
    };

    c.erase(c.begin()+indice);

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

        cout << "Errore nell'apertura del file di output!\n";
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

      cout << "Errore nell'apertura del file di output!\n";
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

        cout << "Errore nell'apertura del file di output!\n";
        exit(0);
    };

    int i;

    output << c.at(0).GetID() << " ";

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
    cin >> tmp_string;

    i = RicercaISBN(l, tmp_string);

    cout << "inserire la quantità di libri ordinati: ";
    cin >> quantita;

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
      cout << "ISBN errato o inesistente!\n"
      "Premi qualsiasi tasto per tornare al menu...";
      rlutil::anykey();
      return;
    }

    cout << "inserire la quantità di libri arrivati: ";
    cin >> quantita;

    if (quantita > l.at(i).GetOrdinati()){
        cout << "Errore! i libri ordinati sono " << l.at(i).GetOrdinati() << endl;
        return;
    }

    l.at(i).SetOrdinati(l.at(i).GetOrdinati() - quantita);
    l.at(i).SetQuantita(l.at(i).GetQuantita() + quantita);

}
