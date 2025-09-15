#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define NAME_LENGTH 200

class Student
{
    char *name;
    int Id;
    int credit_hour;
    float cgpa;

public:
    Student(const char *str, int _id, int _credit, float _cgpa)
    {
        name = (char *)malloc(NAME_LENGTH);
        strcpy(name, str);
        Id = _id;
        credit_hour = _credit;
        cgpa = _cgpa;
    }

    Student (Student &obj)
    {
        name=(char *)malloc(NAME_LENGTH);
        strcpy(name, obj.name);
        Id = obj.Id;
        credit_hour = obj.credit_hour;
        cgpa = obj.cgpa;
    }

    void showInfo()
    {
        cout << "Name :" << name << ",";
        cout << " Id:" << Id << ",";
        cout << " Credit Completed :" << credit_hour << ",";
        cout << " Cgpa :" << cgpa << endl;
    }
    void change(const char *str)
    {
        free(name);
        name = (char *)malloc(NAME_LENGTH);
        strcpy(name, str);
    }
    void change(int _id)
    {
        Id = _id;
    }
    void addTermResult(int _credit, float _cgpa)
    {
        cgpa = (credit_hour * cgpa + _credit * _cgpa) / (credit_hour + _credit);
        credit_hour += _credit;
    }
    ~Student()
    {
        free(name);
    }
};

class Batch
{
    Student *stud;
    int studentcount;

public:
    Batch()
    {
        stud = (Student *)malloc(1200 * sizeof(Student));
        studentcount = 0;
    }
    void addStudent(Student &temp)
    {
        stud[studentcount]=temp;
        studentcount++;
    }
    void showAllStudents()
    {
        for (int i = 0; i < studentcount; i++)
            (stud + i)->showInfo();
    }
    ~Batch()
    {
        free(stud);
    }
};

int main()
{
    // Part 1
    /*A student class holds the information of the
    student name, id, credit earned so far, and
    cumulative gpa (cgpa)*/
    /*The name of a student is stored using malloc,
    which will be freed during destruction*/
    Student s1("Tamim Iqbal", 1905131, 39, 3.56);
    Student s2("Liton Das", 1905150, 39, 3.52);
    s1.showInfo();
    cout << "Changing the name of s1" << endl;
    /*During changing the name, you should reallocate
    memory of the new name and free the previously
    allocated memory*/
    s1.change("Tamim Iqbal Khan");
    s1.showInfo();
    cout << "Changing the id of s2" << endl;
    s2.change(1905149);
    s2.showInfo();
    cout << "Adding a term result of s1" << endl;
    /*The first argument of addTermResult is the credit
    earned in a term and second one is the gpa obtained
    in that term*/
    s1.addTermResult(19, 3.85);
    s1.showInfo();
    // Part 2
    /*Batch contains a list of students*/
    /*During construction, a Batch object allocates dynamic
    memory for 1200 students using malloc. The memory will
    be freed during destruction*/
    Batch b;
    b.addStudent(s1);
    b.addStudent(s2);
    //s1.change("H.M. Aktaruzzaman Mukdho");
    cout << "Printing the list of students of the batch b" << endl;
    b.showAllStudents();
}
