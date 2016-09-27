#include <iostream>
#include <string.h>
using namespace std;


class Cstring{
public:
  //static void init();

  Cstring(char* chaine){
    this -> str = new char[strlen(chaine) + 1];
    strcpy(this -> str, chaine);
    this -> taille = strlen(chaine);
    //Cstring::nbr++;
  }
  
  Cstring(char c){
    this -> str = new char[2];
    this -> str[0] = c;
    this -> str[1] = '\0';
    this -> taille = 1;
    //Cstring::nbr++;
  }

  Cstring(){
    this -> str = new char[1];
    this -> str[0] = '\0';
    this -> taille = 0;
    //Cstring::nbr++;
  }

  char* getChaine()const{
    return this -> str;
  }

  int getTaille()const{
    return this -> taille;
  }

  /*
  int nbrChaines(){
    return this -> nbr;
  }
  */

  Cstring plus(const Cstring& a){
    char buf[this -> taille + a.getTaille() + 1];
    strcpy(buf, this -> str);
    return Cstring(strcat(buf, a.getChaine()));
  }

  Cstring plus(char c){
    char buf[this -> taille + 2];
    strcpy(buf, this -> str);
    buf[this -> taille] = c;
    buf[this -> taille + 1] = '\0';
    return Cstring(buf);
  }

  bool plusGrandQue(const Cstring& s){
    if(strcmp(this -> str, s.getChaine()) > 0)
      return false;
    return true;
  }

  bool infOuEgale(const Cstring& s){
    return !(this -> plusGrandQue(s));
  }

  Cstring plusGrand(const Cstring& s){
    if(this -> taille > s.getTaille())
      return *this;
    return s;
  }

  ~Cstring(){
    cout << "habibi ca detruit" << endl;
  }
private:
  char* str;
  int taille;
  //static int nbr;

};

class Definition{
public:

  Definition(char* def, char* mot){
    this -> mot = Cstring(mot);
    this -> def = Cstring(def);
  }
  char* getDef()const{
    return this -> def.getChaine();
  }

  char* getMot()const{
    return this -> mot.getChaine();
  }

  ~Definition(){
    cout << "destruction definition" << endl;
  }

private:
  Cstring mot;
  Cstring def;
};

int main()
{
  Definition Thomas ("Thomas", "Bite");
  cout << "La definition de " << Thomas.getMot() << " est " << Thomas.getDef() << endl;
}
