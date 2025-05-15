#include<iostream>
using namespace std;

class Student
{
    private:
    int id;
    float per;
    string name;

    public:
    Student(int id,float per,string name):id(id),per(per),name(name) //by default we can pass one constructor we can write this example
    {
        cout << "Parameterized constructor called\n";
        // this -> id = id;
        // this -> per = per;
        // this -> name = name;
    }
    {
        cout << "default constructor called\n";
    }
    void display()
    {
        cout << "Id: "<< id << endl << "Percentage is: "<< per << endl << "Name: "<< name <<endl;
    }
};
int main()
{
    Student stud1(100,12.23,"hari"),stud2(101,34.54,"Rohith"),stud3(102,67.98,"Ub");
    Student stud4;
    stud1.display();
    stud2.display();
    stud3.display();
    Student stud5 = stud2; //copy constructor
    stud5.display();

    return 0;

}