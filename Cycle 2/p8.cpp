/* Write a C++ program to define classes Shapes, Circle, Square, Ellipse and
Rectangle with member functions to get the values for finding corresponding
areas and print the same. Utilize the concept of Abstract Class and Runtime
polymorphism to solve the problem.*/
#include<iostream>
using namespace std;

//Creating abstract class Shape
class Shape
{
    protected:
        float area;
    public:
        virtual void getarea(){};
        virtual void show(){};
};

class Circle : public Shape
{
    float r;
    public:
        void getarea()
        {
            cout<<"Enter Radius of the circle:";
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
    float a;
    public:
    void getarea()
    {
        cout << "Enter side of square:";
        cin >> a ;
        area = a*a;
    }
    void show()
    {
        cout<<"Square Area = "<<area<<"\n";
    }
};

class Rectangle : public Shape
{
    float l,b;
    public:
    void getarea()
    {
        cout << "\nRectangle\n";
        cout << "Enter length: ";
        cin >> l ;
        cout << "Enter breadth: ";
        cin >> b ;
        area = l*b;
    }
    void show()
    {
        cout<<"Rectangle Area = "<<area<<"\n";
    }
};

class Ellipse : public Shape
{
    float MaA,MiA;
    public:
    void getarea()
    {
        cout << "\nEllipse\n";
        cout << "Enter Major Axis length: ";
        cin >> MaA ;
        cout << "Enter Minor Axis length: ";
        cin >> MiA ;
        area = 3.14*MaA*MiA;
    }
    void show()
    {
        cout<<"Ellipse Area = "<<area<<"\n";
    }
};

int main()
{
    //Menu
    cout << "Choose an option : \n";
    cout << "1 - Circle\n";
    cout << "2 - Square\n";
    cout << "3 - Ellipse\n";
    cout << "4 - Rectangle\n";
    cout << "5 - Exit\n";
    Shape *sptr;
    int choice = 0;
    while (choice != 5)
    {
        cout << "\n\nSelect an option : ";
        cin >> choice;
        switch (choice)
        {
            case 1 :
            {
                sptr = new Circle;
                sptr ->getarea();
                sptr ->show();
                break;
            }
            case 2 :
            {
                sptr = new Square;
                sptr ->getarea();
                sptr ->show();
                break;
            }
            case 3 :
            {
                sptr = new Ellipse;
                sptr ->getarea();
                sptr ->show();
                break;
            }
            case 4 :
            {
                sptr = new Rectangle;
                sptr ->getarea();
                sptr ->show();
                break;
            }
            case 5 :
            {
                cout << "   \n";
                break;
            }
            default :
            cout << "Invalid Option Try Again!!!\n";
            break;
        }
    }
}