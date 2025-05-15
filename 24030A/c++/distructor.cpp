#include<iostream>

using namespace std;

class car
{
    private:
    int model;
    string name;
    public:

    car(int model = 100, string name = "default"): model(model), name(name)
    {
        cout<<"constructor cslled\n";
    }
    void print()
    {
        cout<<model<<endl<< name<< endl;
    }
    ~car()
    {
        cout<<"Destructor called\n";
    }
    
};
int main()
{
    car C1(101,"Maruti"), C2(102, "BMW"), C3(103, "MERCEDES");
    return 0;
}