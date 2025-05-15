#include<iostream>

using namespace std;

class student
{
    private:
    int id;
    float per;
    string name;

    public:
    student(int, float, string);
    void disply()
    ~student();
};
student :: student(int id = 0, float per = 0, string name "def"): id(id), per(per), name(name)
{
    cout<<"constructor called\n";
}
void student :: disply()
{
    cout<< id << endl << per << endl << name << endl;
}
student :: ~student()
{
    cout<< "Destructor is called\n";
}
int main()
{
    student stud1, stud2, stud3;
    return 0;
}