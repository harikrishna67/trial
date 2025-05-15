#include<iostream>
using namespace std;
class Student
{
    int num1, num2;
    public:
    Student (int num1, int num2): num1(num1), num2(num2)
    {}
    ~Student()
    {}
    void disply()
    {
        cout<< "num is:" << num1 << endl << "num is :"<< num2 << endl;
    }
    void operator -()
    {
        num1 = num1 * -1;
        num2 *= -1;
    }
    void operator ++()
    {
        num1++;
        num2++;
    }
    void operator ++(int)
    {
        num1++;
        num2++;
    }
};
int main()
{
    Student st1(10, -20);
    st1.disply();
    -st1;
    st1.disply();
    ++st1;
    st1.disply();
    st1++;
    st1.disply();


    return 0;
}