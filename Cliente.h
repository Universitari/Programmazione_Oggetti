#include <string>

using namespace std;

class Cliente {

  private:

  string Nome;
  string Cognome;
  string Email;
  string Tessera;

  public:

  void SetNome(string tmp) {Nome = tmp;};
  void SetCognome(string tmp) {Cognome = tmp;};
  void SetEmail(string tmp) {Email = tmp;};
  void SetTessera_c(string tmp) {Tessera = tmp;};

  string GetNome() const {return Nome;};
  string GetCognome() const {return Cognome;};
  string GetEmail() const {return Email;};
  string GetTessera() const {return Tessera;};
};
