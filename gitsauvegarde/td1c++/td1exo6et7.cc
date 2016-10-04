#include <iostream>
#include <string.h>
using namespace std;


class Cstring{
public:
  //static void init();

  Cstring(const char* chaine){
    this -> str = new char[strlen(chaine) + 1];
    strcpy(this -> str, chaine);
    this -> taille = strlen(chaine);
    //Cstring::nbr++;
  }
  
  Cstring(const char c){
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

  Cstring plus(const Cstring& a){    // concatene deux chaines de caracteres
    char buf[this -> taille + a.getTaille() + 1];  // crée un tableau de caractere de la taille des 2 chaines de carac
    strcpy(buf, this -> str);                 // copine str dans le buf
    return Cstring(strcat(buf, a.getChaine()));  // on concatene le buffer + nouvelle chaine
  }

  Cstring plus(char c){
    char buf[this -> taille + 2];  // concatene un caractere avec une chaine
    strcpy(buf, this -> str);
    buf[this -> taille] = c;
    buf[this -> taille + 1] = '\0';
    return Cstring(buf);
  }

  bool plusGrandQue(const Cstring& s){
    if(strcmp(this -> str, s.getChaine()) > 0)   //compare les 2 chaines de caractere. inferieur a 0 si premier est plus petit que le deuxieme
      return false;									// 0 si les deux sont égaux
    return true;
  }

  bool infOuEgale(const Cstring& s){
    return !(this -> plusGrandQue(s));
  }

  Cstring plusGrand(const Cstring& s){   //compare les 2 chaines et retourne la plus grande chaine de caractere.
    if(this -> taille > s.getTaille())
      return *this;
    return s;
  }

  ~Cstring(){
    cout << " Le destructeur fonctionne" << endl;
  }
private:
  char* str;
  int taille;
  //static int nbr;

};

class Definition{
public:

  Definition(const char* ch1, const char* ch2){
    mot = Cstring(ch1);
    def = Cstring(ch2);
  }
  const char* getDef()const{
    return this -> def.getChaine();
  }

  const char* getMot()const{
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
  Definition Thomas ("Thomas" , "Surfeur");
  cout << "La definition de " << Thomas.getMot() << " est " << Thomas.getDef() << endl;
}
