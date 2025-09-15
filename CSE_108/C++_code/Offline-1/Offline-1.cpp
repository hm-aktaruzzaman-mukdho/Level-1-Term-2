// Deadline June 14,5PM
/*Consider the class Student that has three private member variables,
namely roll (integer), name (string), and cgpa (float).
Write appropriate getter and setter functions along with
overloaded constructors so the given main function works properly.
Also, write a destructor function that sets the roll to 0.*/

#include <iostream>
#include <cstring>
using namespace std;

// Implement the class Student
class Student
{
private:
    int roll;
    char name[200];
    float cg;

public:
    Student()
    {
        
    }
    Student(int x)
    {
        roll = x;
    }
    Student(float x)
    {
        cg = x;
    }
    Student(const char *str)
    {
        strcpy(name, str);
    }
    Student(int x,const char *str, float CG)
    {
        roll = x;
        strcpy(name, str);
        cg = CG;
    }
    void setroll(int x)
    {
        roll = x;
    }
    int getroll()
    {
        return roll;
    }
    void setcg(float x)
    {
        cg = x;
    }
    float getcg()
    {
        return cg;
    }
    void setname(const char *str)
    {
        strcpy(name, str);
    }
    char * getname()
    {
        return name;
    }
};

int main()
{
    Student s1;
    Student s2("Karim");
    Student s3(3);
    Student s4(4, "Rahim", 3.52);
    Student s5(5, "Sakib", 3.92);
    s1.setname("Papon");
    s1.setroll(1);
    s1.setcg(4.00);
    s2.setroll(2);
    s2.setcg(3.8);
    s3.setname("Abdul");
    s3.setcg(3.96);
    float avg = (s1.getcg() + s2.getcg() + s3.getcg() + s4.getcg() + s5.getcg()) / 5;
    cout << "Student #1" << endl;
    cout << "Roll : " << s1.getroll() << endl;
    cout << "Name : " << s1.getname() << endl;
    cout << "CGPA : " << s1.getcg() << endl
         << endl;

    cout << "Student #2" << endl;
    cout << "Roll : " << s2.getroll() << endl;
    cout << "Name : " << s2.getname() << endl;
    cout << "CGPA : " << s2.getcg() << endl
         << endl;

    cout << "Student #3" << endl;
    cout << "Roll : " << s3.getroll() << endl;
    cout << "Name : " << s3.getname() << endl;
    cout << "CGPA : " << s3.getcg() << endl
         << endl;

    cout << "Student #4" << endl;
    cout << "Roll : " << s4.getroll() << endl;
    cout << "Name : " << s4.getname() << endl;
    cout << "CGPA : " << s4.getcg() << endl
         << endl;

    cout << "Student #5" << endl;
    cout << "Roll : " << s5.getroll() << endl;
    cout << "Name : " << s5.getname() << endl;
    cout << "CGPA : " << s5.getcg() << endl
         << endl;

    cout << "Average of CGPA : " << avg << endl;
}