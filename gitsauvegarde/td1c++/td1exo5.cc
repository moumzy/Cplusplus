#include <iostream>
#include <cmath>

class Point{
private:
  int x;
  int y;

public:

  Point(){
    this -> x = 0;
    this -> y = 0;
  }

  Point(int a, int b){
    this -> x = a;
    this -> y = b;
  }

  Point(const Point& P){
    this -> x = P.getX();
    this -> y = P.getY();
  }

  int getX()const{
    return this -> x;
  }

  int getY()const{
    return this -> y;
  }

  void afficher() {
    std::cout << '(' << x << ',' << y << ')' << std::endl;
  }

  void placer(int a, int b) {
    this -> x = a; this -> y = b;
  }

  void cloner(const Point& P){
    this -> x = P.getX();
    this -> y = P.getY();
  }

  ~Point(){
    std::cout << "destruction du point" << std::endl;
  }


};

class Segment{
public:
  ~Segment(){
    std::cout << "destruction du segment" << std::endl;
  }

  Segment(const Point& PA, const Point& PB){
    this -> P1 = PA;
    this -> P2 = PB;
  }

  void afficher(){
    std::cout << "P1 : ";
    this -> P1.afficher();
    std::cout << "P2 : ";
    this -> P2.afficher();
    std::cout << "longueur : " << this -> longueur() << std::endl;
  }

  int longueur(){
    return sqrt((P2.getX() - P1.getX())*(P2.getX() - P1.getX()) + (P2.getY() - P1.getY())*(P2.getY() - P1.getY()));
  }

  bool est_vertical(){
    return (this -> P1.getY() == this -> P2.getY());
  }

  bool est_horizontal(){
    return (this -> P1.getX() == this -> P2.getX());
  }

  bool est_diagonal(){
    return (!est_vertical() && !est_horizontal());
  }


private:
  Point P1;
  Point P2;

};

int main(){
  Point *P1 = new Point();
  P1 -> afficher();
  Point *P2 = new Point(5, 123);
  P2 -> afficher();

  Segment* S = new Segment(*P1, *P2);
  S -> afficher();
  delete P1;
  delete P2;
  delete S;
  return 0;
}
