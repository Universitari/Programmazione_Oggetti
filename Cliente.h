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

  void SetNome(string tmp) {Nome = tmp;};
  void SetCognome(string tmp) {Cognome = tmp;};
  void SetEmail(string tmp) {Email = tmp;};
  void SetTessera(unsigned int tmp) {Tessera = tmp;};
  void SetID(unsigned int tmp) {max_clienti = tmp;};

  string GetNome() const {return Nome;};
  string GetCognome() const {return Cognome;};
  string GetEmail() const {return Email;};
  unsigned int GetTessera() const {return Tessera;};
  unsigned int GetID() const {return max_clienti;};

};
