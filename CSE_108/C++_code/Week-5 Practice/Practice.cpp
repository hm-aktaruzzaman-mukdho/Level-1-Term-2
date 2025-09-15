#include<iostream>
#define UNDEFINED 0
#define LINE 1
#define RECTANGLE 2
#define CUBOID 3

using namespace std;

class Shape
{
    int type;
public:
    Shape()
    {
        this->type=UNDEFINED;
    }
    Shape(int type)
    {
        this->type = type;
    }
    int area()
    {
        return -1;
    }
    int volume()
    {
        return -1;
    }
    int get_type()
    {
        return type;
    }
    void set_type(int type)
    {
        this->type = type;
    }
};


class Line: public Shape
{

    int length;
public:
    Line()
    {
        length=0;
    }
    Line(int type, int length)
    {
        this->length = length;
        set_type(type);
    }
    // your code
    int area()
    {
        return 0;
    }
    int volume()
    {
        return 0;
    }
    void set_length(int length)
    {
        this->length=length;
    }
    int get_length()
    {
        return length;
    }
};

class Rectangle: public Line
{
    int width;
public:
    Rectangle()
    {
        this->width=0;
    }
    Rectangle(int type, int length, int width)
    {
        this->width = width;
        set_type(type);
        set_length(length);
    }
    // your code
    void set_width(int width)
    {
        this->width=width;
    }
    int get_width()
    {
        return this->width;
    }
    int area()
    {
        return get_length()*this->width;
    }
    int volume()
    {
        return 0;
    }
};

class Cuboid: public Rectangle
{
    int height;
public:
    Cuboid()
    {
        this->height=0;
    }
    Cuboid(int type, int length, int width, int height)
    {
        this->height = height;
    }
    // your code
};


int main()
{
    Shape s(UNDEFINED);
    cout << s.area() << endl;
    cout << s.volume() << endl;

    Line l(LINE, 5);
    cout << l.area() << endl; // 0
    cout << l.volume() << endl; // 0

    Rectangle r(RECTANGLE, 5, 2);
    cout << r.area() << endl; // 10
    cout << r.volume() << endl; // 0

    Cuboid c(CUBOID, 5, 2, 4);
    cout << c.area() << endl; // 76
    cout << c.volume() << endl; // 40


    Shape *s1;
    s1 = &l;
    cout << s1->area() << endl; // 0
    cout << s1->volume() << endl; // 0

    Shape* s2;
    s2 = &r;
    cout << s2->area() << endl; // 10
    cout << s2->volume() << endl; // 0


    Shape* s3;
    s3 = &c;
    cout << s2->area() << endl; // 76
    cout << s2->volume() << endl; // 40

    //write destructor function and observe (by printing something) the order of constructor and destructor call

    return 0;
}