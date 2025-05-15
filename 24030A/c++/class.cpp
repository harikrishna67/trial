#include<iostream>
using namespace std;
class Student
{
    int id;
    string name;
    float per;

    void get_detail()
    {
        cout<< "Enter id:";
        cin>> id;
        cout<< " Enter name:";
        cin>> name;
        cout<< " Enter Percentage:";
        cin>> per;
    }
    void disply()
    {
        cout<< name << endl << id << endl << per << endl;
    }
};
int main()
{
    Student stud1, stud2, stud3;
    stud1.get_detail();
    stud1.disply();
    //cout<<sizeof(stud1)<<endl;
    return 0;
}