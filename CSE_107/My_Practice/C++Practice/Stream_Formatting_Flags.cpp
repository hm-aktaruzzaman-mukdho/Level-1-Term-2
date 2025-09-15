#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
    cout.setf(ios::showpoint);
    cout.setf(ios::showpos);
    cout << 100.0 << "\n"; // displays +100.000
    cout.setf(ios::uppercase | ios::scientific);
    cout << 100.12 << "\n";      // displays 1.001200E+02
    cout.unsetf(ios::uppercase); // clear uppercase
    cout << 100.12 << "\n";      // displays 1.001200e+02
    cout.unsetf(ios::showpos | ios::uppercase | ios::scientific);
    cout.precision(4);
    cout.width(10);
    cout << 10.12345 << "\n"; // displays 10.12
    cout.fill('*');
    cout.width(10);
    cout << 10.12345 << "\n"; // displays *****10.12
    // field width applies to strings, too
    cout.width(10);
    cout << "Hi!"
         << "\n"; // displays *******Hi!
    cout.width(10);
    cout.setf(ios::left); // left justify
    cout << 10.12345;     // displays 10.12*****    return 0;
}