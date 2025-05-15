#include<iostream>
using namespace std;
class student 
{
    int id;
    float per;
    string name;

public:
student(int std, float per, string name)
{
    cout<<"default constructor called\n";
    this -> id =1;
    this -> per = 67.58;
    this -> name = "default";
}
void disply()
{
    cout<<"id:"<<id<<endl<<"percentage:"<<per<<endl<<"Nmae:"<<endl;
}
};
int main()
{
    student stud1,stud2,stud3;
    stud1 disply;
    stud2 disply;
    stud3 disply;
}