#include <string>

using namespace std;

class Cliente {

  private:

  string Nome;
  string Cognome;
  string Email;
  unsigned int Tessera;

  static unsigned int max_clienti;

  public:
/// Set nome del cliente
/// @param tmp variabile temporanea per nome cliente
  void SetNome(string tmp) {Nome = tmp;};
/// Set cognome del cliente
/// @param tmp variabile temporanea per cognome cliente
  void SetCognome(string tmp) {Cognome = tmp;};
/// Set e-mail del cliente
/// @param tmp variabile temporanea per e-mail cliente
  void SetEmail(string tmp) {Email = tmp;};
/// Set tessera del cliente
/// @param tmp variabile temporanea per tessera cliente
  void SetTessera(unsigned int tmp) {Tessera = tmp;};
/// Set numero max di cliente
/// @param tmp variabile temporanea per numero max cliente
  void Set_MaxClienti(unsigned int tmp) {max_clienti = tmp;};

/// Get nome del cliente
/// @returns nome cliente
  string GetNome() const {return Nome;};
/// Get cognome cliente
/// @returns cognome cliente
  string GetCognome() const {return Cognome;};
/// Get e-mail cliente
/// @returns e-mail cliente
  string GetEmail() const {return Email;};
/// Get tessera cliente
/// @returns tessera cliente
  unsigned int GetTessera() const {return Tessera;};
/// Get numero max cliente
/// @returns numero max cliente
  unsigned int Get_MaxClienti() const {return max_clienti;};

};
