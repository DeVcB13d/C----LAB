//Write a C++ program to demonstrate the concept of Multiple and Multilevel
//inheritance including constructors with parameters.
#include <iostream>
#include <string>
using namespace std ;

class person
{
    protected:
        string name;
        int age;
    public:
        person(string n,int a)
        {
            name = n;
            age = a;
        }
        void show()
        {
            cout << "Name : " << name << endl;
            cout << "Age  : " << age  << endl;
        }
};

class Employee : public person
{
    protected:
        float Bpay;
        int years;
    public:
        Employee(string na,int ag,float sal,int yr) : person(na,ag)
        {
            Bpay = sal;
            years = yr;
        }
        void show()
        {
            cout << "Basic Pay : " << Bpay << endl;
            cout << "Years of service : " << years << endl;
        }
};

class Extragrants
{
    protected:
        float bonus;
        float pen;
    public:
        Extragrants(float b,float p)
        {
            bonus = b;
            pen = p;
        }
        void show()
        {
            cout << "Bonus  : " << bonus << "%\n";
            cout << "Pension: " << pen   << "%\n";
        }
};

class Developer : public Employee,public Extragrants
{
    protected:
        int rank;
        int DeID;
        int Sal;
    public:
        Developer(string na,int ag,float sal,int yr,float b,float p,int rk,int id)
            :Extragrants(b,p),Employee(na,ag,sal,yr)
        {
            rank = rk;
            DeID = id;
            Sal = Bpay+(Bpay*(bonus/100))-(Bpay*(pen/100));
        }
        void show()
        {
            cout << "DETAILS OF DEVELOPER : \n";
            person::show();
            cout << "Rank  : " << rank << "\n";
            cout << "Dev ID: " << DeID << "\n";
            Employee::show();
            Extragrants::show();
            cout << "Final Salary : " << Sal << endl;
        }
};

int main()
{
    string Nm;int ag,yrs,rk,id;
    float sal,b,p;
    cout << "Welcome\n\n";
    cout << "Enter the Details : \n\n";
    cout << "Name  : " ;
    cin >> Nm;
    cout << "Enter age : ";
    cin >> ag;
    cout << "Enter Bpay,Bonus and Pension percent : \n";
    cin >> sal >> b >> p ;
    cout << "Enter Years of Service : ";
    cin >> yrs ;
    cout << "Enter DevID and Rank :";
    cin >> id >> rk;
    cout << "\n\n";
    Developer D1(Nm,ag,sal,yrs,b,p,rk,id);
    D1.show();
    return 0;
}