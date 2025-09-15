#include <iostream>
using namespace std;

class Rectangle {
	int *width, *height;
public:
	Rectangle(int, int);
	Rectangle(const Rectangle &r);
	~Rectangle ();
	int area () {return (*width * *height);}
};

Rectangle::Rectangle (int a, int b) {
	cout<<"----Constructor"<<endl;
	width= new int;
	height = new int;
	*width = a;
	*height = b;
}

Rectangle::Rectangle(const Rectangle &r){
	cout<<"    Copy constructor"<<endl;
	width=new int;
	height=new int;
	*width=*r.width;
	*height=*r.height;
}

Rectangle:: ~Rectangle () {
	delete width;
	delete height;
}

Rectangle larger(Rectangle recta, Rectangle rectb){
	if(recta.area()>rectb.area())
		return recta;
	else
		return rectb;
}

int main () {
	Rectangle recta (3,4);
	Rectangle rectb (5,6);
	
	Rectangle rectc=recta; //this will call copy constructor
	Rectangle rect_larger(0,0);
	
	rect_larger=larger(recta, rectb);
	 //this will call both copy constructor and destructor 3 times

	cout << "recta area: " << recta.area() << endl;
	cout << "rectb area: " << rectb.area() << endl;
	cout << "rectc area: " << rectc.area() << endl;
	

	cout << "rect_larger area: " << rect_larger.area() << endl; 
	
	
	return 0;
} 
