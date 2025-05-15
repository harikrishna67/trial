#include<iostream>
using  namespace std;

class Number
{
    int num1,num2;

    public:
    Number(int num1,int num2):num1(num1),num2(num2)
    {}
    ~Number()
    {}
    void display()
    {
        cout<<"Operator overloading using binary operator\n";
        cout<<num1<<endl<<num2;
    }
    void operator +(int num)
    {
        //int res = num1+num2;
        num1=num1+num;
        num2 += num;

        //cout<<num1<<endl;
    }
    Person operator +(Person P)
    {
        Person temp;
        num1 = num1 + num1;
        num2 = num2 + num2;
        return temp;


    }
};

int main()
{
    Number n1(5,8);
    int n= 10;
    
    
    n1+n;//n===>num
    n1.display();

    return 0;
}