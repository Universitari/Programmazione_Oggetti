#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "Libro.h"
#include "Acquisto.h"
#include "Cliente.h"
#include "rlutil.h"


using namespace std;

int Input_int();
float Input_float();
bool File_Vuoto(ifstream& input);


/// Inizializzazione file contenente libri
///
/// @param l vettore Libro
  void init_l(vector<Libro> &l);

/// Inizializzazione file contenente acquisti
///
/// @param a vettore Acquisto
  void init_a(vector<Acquisto> &a);

/// Inizializzazione file contenente clienti
///
/// @param c vettore Cliente
  void init_c(vector<Cliente> &c);


/// Aggiunta di nuovi libri
///
/// @param l vettore Libro
  void Aggiunta_Libro(vector<Libro> &l);

/// Aggiunta di nuovi clienti
///
/// @param c vettore Cliente
  void Aggiunta_Cliente(vector<Cliente> &c);

/// Eliminazione di clienti
///
/// @param c vettore Cliente
  void EliminaCliente(vector<Cliente> &c);


/// Stampa primaria di libro
///
/// @param tmp di tipo libro
  void PrintLibro(const Libro tmp);

/// Stampa primaria di acquisto
///
/// @param tmp di tipo acquisto
  void PrintAcquisto(const Acquisto tmp);

/// Stampa primaria di cliente
///
/// @param tmp di tipo cliente
  void PrintCliente(const Cliente tmp);


/// Stampa di Libro
///
/// @param l del vettore Libro
void StampaLibri(const vector<Libro> &l);

/// Stampa di acquisto
///
/// @param a del vettore Acquisto
void StampaAcquisti(const vector<Acquisto> &a);

/// Stampa di cliente
///
/// @param c del vettore Cliente
void StampaClienti(const vector<Cliente> &c);


/// Ricerca del libro per ISBN
///
/// @param l del vettore Libro
/// @param tmp di tipo stringa per ISBN del libro
int RicercaISBN(vector<Libro> &l, const string tmp);

/// Ricerca del cliente per tessera
///
/// @param c del vettore Cliente
/// @param tessera per la ricerca del cliene
int RicercaTessera(vector<Cliente> &c, unsigned int tessera);

/// Funzione per l'aggiunta di una vendita
///
/// @param l del vettore Libro
/// @param a del vettore Acquisto
void Vendita(vector<Libro> &l, vector<Acquisto> &a);

/// Funzione per ordinazione dei libri
///
/// @param l del vettore Libro
void OrdinaLibri(vector<Libro> &l);

/// Funzione per cambio del valore di libri in stock ed ordinati
///
/// @param l del vettore Libro
void LibriArrivati(vector<Libro> &l);


/// Funzione di conversione della struct "Data" in stringa
///
/// @param a del vettore Acquisto
string Data_to_string(Acquisto a);


// Funzione per controllo del giorno
///
/// @param m per controllo mese
/// @param y per controllo anno
short int MaxGiorno(short int m, short int y);

/// Funzione per l'inserimento della data
Data InserimentoData();


/// Funzione per salvataggio in file del lavoro su libri
///
/// @param l del vettore Libro
void save_l(vector<Libro> &l);

/// Funzione per salvataggio in file del lavoro su acquisti
///
/// @param a del vettore Acquisto
void save_a(vector<Acquisto> &a);

/// Funzione per salvataggio in file del lavoro su clienti
///
/// @param c del vettore Cliente
void save_c(vector<Cliente> &c);
