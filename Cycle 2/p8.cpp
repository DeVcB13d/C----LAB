/* Write a C++ program to define classes Shapes, Circle, Square, Ellipse and
Rectangle with member functions to get the values for finding corresponding
areas and print the same. Utilize the concept of Abstract Class and Runtime
polymorphism to solve the problem.*/
#include<iostream>
using namespace std;
class Shape
{
    protected:
        float area;
    public:
        virtual void getarea() ;
        virtual void show() ;
};

class Circle : public Shape
{
    float r;
    public:
        void getarea()
        {
            cout<<"Enter Radius :";
            cin >>r;
            area = 3.14*r*r;
        }
        void show()
        {
            cout<<"Circle Area = "<<area<<"\n";
        }
};

class Square : public Shape
{
    int a;
    public:
    void getarea()
    {
        cout << "Enter side :";
        cin >> a ;
        area = a*a;
    }
    void show()
    {
        cout<<"Square Area = "<<area<<"\n";
    }
};

int main()
{
    Shape *sptr;
    sptr = new Circle;
    sptr->getarea();
    sptr->show();
    sptr = new Square;
    sptr ->getarea();
    sptr ->show();
    return 0;
}