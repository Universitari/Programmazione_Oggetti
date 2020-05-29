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
/// @param tmp appoggio per nome cliente
  void SetNome(string tmp) {Nome = tmp;};
  void SetCognome(string tmp) {Cognome = tmp;};
  void SetEmail(string tmp) {Email = tmp;};
  void SetTessera(unsigned int tmp) {Tessera = tmp;};
  void Set_MaxClienti(unsigned int tmp) {max_clienti = tmp;};

  string GetNome() const {return Nome;};
  string GetCognome() const {return Cognome;};
  string GetEmail() const {return Email;};
  unsigned int GetTessera() const {return Tessera;};
  unsigned int Get_MaxClienti() const {return max_clienti;};

};
