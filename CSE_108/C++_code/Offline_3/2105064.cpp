#include <iostream>
// your code
using namespace std;

class Point2D
{
    double x, y;

public:
    Point2D()
    {
        x = 0;
        y = 0;
    }
    Point2D(double x, double y);
    void setX(double x);
    void setY(double y);
    double getX();
    double getY();
    void print();
    ~Point2D();
    // your code
    Point2D operator+(const Point2D &rhs);
    Point2D operator*(double n);
    bool operator==(const Point2D &rhs);
    bool operator!=(const Point2D &rhs);
};

Point2D::Point2D(double argx, double argy)
{
    x = argx;
    y = argy;
}

void Point2D::setX(double argx)
{
    x = argx;
}

void Point2D::setY(double argy)
{
    y = argy;
}

double Point2D::getX()
{
    return x;
}

double Point2D::getY()
{
    return y;
}

void Point2D::print()
{
    cout << "(" << x << "," << y << ")";
}

Point2D::~Point2D()
{
    x = 0;
    y = 0;
}
// My overloaded function
Point2D Point2D::operator+(const Point2D &rhs)
{
    Point2D newobj;
    newobj.x = this->x + rhs.x;
    newobj.y = this->y + rhs.y;
    return newobj;
}

Point2D Point2D::operator*(double n)
{
    Point2D newobj;
    newobj.x = this->x * n;
    newobj.y = this->y * n;
    return newobj;
}
bool Point2D::operator==(const Point2D &rhs)
{
    if (this->x == rhs.x && this->y == rhs.y)
        return true;
    else
        return false;
}
bool Point2D::operator!=(const Point2D &rhs)
{
    if (this->x != rhs.x || this->y != rhs.y)
        return true;
    else
        return false;
}
// your code

class Circle
{
    Point2D center;
    double radius;
    double area()
    {
        return 3.14159265 * radius * radius;
    }

public:
    Circle();
    Circle(Point2D c, double r);
    void setCenter(Point2D c);
    void setRadius(double r);
    Point2D getCenter();
    double getRadius();
    void print();
    ~Circle();
    // your code
    Circle operator+(Point2D &temp);
    Circle operator*(double n);
    Circle operator+(Circle &temp);
    Circle operator-(Circle &temp);
    bool operator==(Circle &temp);
    bool operator>(Circle &temp);

    bool operator>=(Circle &temp);
    bool operator<(Circle &temp);
    bool operator<=(Circle &temp);
    Circle operator++(int);
    Circle operator++();
};

Circle::Circle()
{
    center.setX(0);
    center.setY(0);
    radius = 0;
}

Circle::Circle(Point2D c, double r)
{
    center.setX(c.getX());
    center.setY(c.getY());
    radius = r;
}

void Circle::setCenter(Point2D c)
{
    center.setX(c.getX());
    center.setY(c.getY());
}

void Circle::setRadius(double r)
{
    radius = r;
}
Point2D Circle::getCenter()
{
    return center;
}
double Circle::getRadius()
{
    return radius;
}

void Circle::print()
{
    cout << "[Center: ";
    center.print();
    cout << " Radius: " << radius;
    cout << "]";
}

Circle::~Circle()
{
    center.setX(0);
    center.setY(0);
    radius = 0;
}
// My overloaded function
Circle Circle::operator+(Point2D &temp)
{
    Circle newobj;
    newobj.center.setX(this->center.getX() + temp.getX());
    newobj.center.setY(this->center.getY() + temp.getY());
    newobj.radius = this->radius;
    return newobj;
}

Circle Circle::operator*(double n)
{
    Circle newobj;
    newobj.center.setX(this->center.getX() * n);
    newobj.center.setY(this->center.getY() * n);
    newobj.radius = this->radius * n;
    return newobj;
}
Circle Circle::operator+(Circle &temp)
{
    Circle newobj;
    double l1 = this->radius, l2 = temp.radius;
    newobj.setCenter(this->center * (l1 / (l1 + l2)) + temp.center * (l2 / (l1 + l2)));
    newobj.radius = this->radius + temp.radius;
    return newobj;
}

Circle Circle::operator-(Circle &temp)
{
    Circle newobj;
    double l1 = this->radius, l2 = temp.radius;
    newobj.setCenter(this->center * (l1 / (l1 + l2)) + temp.center * (l2 / (l1 + l2)));
    newobj.radius = this->radius - temp.radius;
    return newobj;
}

bool Circle::operator==(Circle &temp)
{
    if (this->area() == temp.area())
        return true;
    else
        return false;
}

bool Circle::operator>(Circle &temp)
{
    if (this->area() > temp.area())
        return true;
    else
        return false;
}

bool Circle::operator>=(Circle &temp)
{
    if (this->area() >= temp.area())
        return true;
    else
        return false;
}

bool Circle::operator<(Circle &temp)
{
    if (this->area() < temp.area())
        return true;
    else
        return false;
}

bool Circle::operator<=(Circle &temp)
{
    if (this->area() <= temp.area())
        return true;
    else
        return false;
}

Circle Circle::operator++(int)
{
    Circle newobj = *this;
    this->radius++;
    return newobj;
}
Circle Circle::operator++()
{
    ++this->radius;
    return *this;
}
// your code

class Rectangle
{
    Point2D topRightPoint, bottomLeftPoint;

public:
    Rectangle();
    Rectangle(Point2D oneCorner, Point2D anotherCorner);
    void setTopRightPoint(Point2D oneCorner);
    void setbottomLeftPoint(Point2D anotherCorner);
    Point2D getTopRightPoint();
    Point2D getBottomLeftPoint();
    void print();
    ~Rectangle();
    // your code
    Rectangle operator+(const Point2D &temp);
    Rectangle operator*(double n);
};

Rectangle::Rectangle()
{
    topRightPoint.setX(0);
    topRightPoint.setY(0);
    bottomLeftPoint.setX(0);
    bottomLeftPoint.setY(0);
}
Rectangle::Rectangle(Point2D oneCorner, Point2D anotherCorner)
{
    topRightPoint = oneCorner;
    bottomLeftPoint = anotherCorner;
}

void Rectangle::setTopRightPoint(Point2D oneCorner)
{
    topRightPoint = oneCorner;
}
void Rectangle::setbottomLeftPoint(Point2D anotherCorner)
{
    bottomLeftPoint = anotherCorner;
}
Point2D Rectangle::getTopRightPoint()
{
    return topRightPoint;
}
Point2D Rectangle::getBottomLeftPoint()
{
    return bottomLeftPoint;
}

void Rectangle::print()
{
    cout << "[Top Right Point: ";
    topRightPoint.print();
    cout << "  Bottom left Point: ";
    bottomLeftPoint.print();
    cout << "]";
}
Rectangle::~Rectangle()
{
    topRightPoint.setX(0);
    topRightPoint.setY(0);
    bottomLeftPoint.setX(0);
    bottomLeftPoint.setY(0);
}
// Overloaded function
Rectangle Rectangle::operator+(const Point2D &temp)
{
    Rectangle newobj;
    newobj.topRightPoint = this->topRightPoint + temp;
    newobj.bottomLeftPoint = this->bottomLeftPoint + temp;
    return newobj;
}

Rectangle Rectangle::operator*(double n)
{
    Rectangle newobj;
    newobj.topRightPoint = this->topRightPoint * n;
    newobj.bottomLeftPoint = this->bottomLeftPoint * n;
    return newobj;
}
// your code

int main()
{
    Point2D p1(5, 10), p2(15, 10), p3, p4, p5;
    Circle c1(p1, 10), c2, c3;
    Rectangle r1(p1, p2), r2;
    cout << "     Printing Points." << endl;
    cout << "Printing point p1:";
    p1.print();
    cout << endl;
    cout << "Printing point p2:";
    p2.print();
    cout << endl;
    // printing p3=p1+p2
    p3 = p1 + p2;
    cout << "Printing p3=p1+p2:";
    p3.print();
    cout << endl;
    double num = 3;
    // cout << "Enter a value for multiply:";
    // cin >> num;
    p4 = p1 * num;
    cout << "Printing p1*" << num << ":";
    p4.print();
    cout << endl;

    if (p1 == p2)
        cout << "p1 and p2 is equal" << endl;

    if (p1 != p2)
        cout << "p1 and p2 is not equal" << endl;

    double x, y;
    // cout<<"Enter x and y value for p5:";
    // cin>>x>>y;
    cout << "Printing default coordinate of p5:";
    p5.print();
    cout << endl;
    p5.setX(5);
    p5.setY(7);
    cout << "Printing point p5:";
    p5.print();
    cout << endl;
    cout << "X coordinate of p5 :" << p5.getX() << endl;
    cout << "Y coordinate of p5 :" << p5.getY() << endl;
    cout << endl;
    cout << "     Printing circles." << endl;
    cout << "Printing circle c1:";
    c1.print();
    cout << endl;
    c2.setCenter(p2);
    c2.setRadius(5);
    cout << "Printing circle c2 centre set to p2:";
    c2.print();
    cout << endl;
    c3 = c2 + p3;
    cout << "c2+p3:";
    c3.print();
    cout << endl;
    c3 = c3 * 8;
    cout << "c2*8:";
    c3.print();
    cout << endl;

    c3 = c1 + c2;
    cout << "c1+c2:";
    c3.print();
    cout << endl;

    c3 = c1 - c2;
    cout << "c1-c2:";
    c3.print();
    cout << endl;

    if (c1 == c2)
    {
        cout << "c1 and c2 circle is equal." << endl;
    }
    else
        cout << "c1 and c2 circle is not equal." << endl;

    if (c1 > c2)
        cout << "c1 is greater than c2." << endl;
    else
        cout << "c1 is not greater than c2." << endl;

    if (c1 >= c2)
        cout << "c1 is greater than or equal to c2." << endl;
    else
        cout << "c1 is not greater than or equal to c2." << endl;

    if (c1 < c2)
        cout << "c1 is less than c2." << endl;
    else
        cout << "c1 is not less than c2." << endl;

    if (c1 <= c2)
        cout << "c1 is less than or equal to c2." << endl;
    else
        cout << "c1 is not less than or equal to c2." << endl;

    cout << "c1++  :";
    c1++;
    c1.print();
    cout << endl;

    cout << "++c1  :";
    ++c1;
    c1.print();
    cout << "\n\n";

    cout << "     Rectangle functions." << endl;
    cout << "Printing r1 :";
    r1.print();
    cout << endl;

    r2 = r1 + p1;
    cout << "Printing r1+p1 :";
    r2.print();
    cout << endl;

    r2 = r1 * 9;
    cout << "Printing r1*9 :";
    r2.print();
    cout << endl;

    return 0;
}