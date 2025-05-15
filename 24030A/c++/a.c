#include<iostream>
#include<cstring>
#include<cstdlib>


using namespace std;

class car
{
    private:
    int model;
    string name;
    car()
    {
        cout<<"constructor cslled\n";
        name = (char *)malloc(sizeof(char) * 10);
        
    }
    void print()
    {
        cout<<model<<endl<< name<< endl;
    }
    ~car()
    {
        cout<<"Destructor called\n";
        free(name);
    }
    
};
int main()
{
    car C1, C2, C3;
    strcpy(C1.name, "SUZUKI");
    
    C1.print(); 
    return 0;
}