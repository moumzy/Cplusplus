using namespace std;
#include <iostream>

class Point {
	private:
		double x;
		double y;
	public: 
		Point()
		 {
			 this->x = 0;
			 this->y = 0;
		 }
		 Point(double x, double y)
		 {
			 this->x = x;
			 this->y = y;
		 }
		 Point(const Point& p)
			{
			 this->x = p.getx();
			 this->y = p.gety();
			}
		 ~Point()  // la petite vague correspondant a lappel du destructeur 
			{
			 cout << "appel au destructeur du point "<<x<<"  "<<y;
			}
		 double getx() const 
			{
				return this -> x;
			}
		double gety() const 
			{
				return this -> y;
			}
		void afficher()
		{
			cout << this -> x <<this-> y ;
		}
		void cloner (const Point &p)
		{
			this -> x = p.getx();
			this -> y = p.gety();
		}
		
	};
	
	
int main(){
	
	Point *p1 = new Point();
	cout << p1 -> getx() << endl;
	p1 -> afficher();
	delete p1;
	
}
