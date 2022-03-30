//1. Write a C++ program to overload ==, !=, <, <=, > and >= operators as
//member operator functions for a vector object.
#include<iostream>
#include<cmath>
using namespace std;
class Vector
{
    float i,j,k;
    float M;
    public:
        Vector(){}
        Vector(float a,float b,float c);
        friend bool operator==(Vector,Vector);
        friend bool operator!=(Vector,Vector);
        friend bool operator<=(Vector,Vector);
        friend bool operator>=(Vector,Vector);
        friend bool operator>(Vector,Vector);
        friend bool operator<(Vector,Vector);
        void display();        
};

void Vector::display()
{
    cout << i << "i + " << j << "j + " << k << "k";
    cout <<"("<<M<<")";
}

Vector::Vector(float a,float b,float c)
{
    i = a;j = b;k = c;
    //To get magnitude of the vector
    M = sqrt((i*i)+(j*j)+(k*k));
}

bool operator==(Vector x,Vector y)
{
    if (x.M == y.M)
    {
        return true;
    }
    else return false;
}

bool operator!=(Vector x,Vector y)
{
    if (x.M != y.M)
    {
        return true;
    }
    else return false;
}

bool operator<=(Vector x,Vector y)
{
    if (x.M <= y.M)
    {
        return true;
    }
    else return false;
}

bool operator>=(Vector x,Vector y)
{
    if (x.M >= y.M)
    {
        return true;
    }
    else return false;
}

bool operator<(Vector x,Vector y)
{
    if (x.M < y.M)
    {
        return true;
    }
    else return false;

}

bool operator>(Vector x,Vector y)
{
    if (x.M > y.M)
    {
        return true;
    }
    else return false;
}

//Function to give output based on T/F values
void compare_out(bool x)
{
    if (x==true)
    {
        cout << "\nThe comparison is True\n";
    }
    else if(x==false)
    {
        cout << "\nThe comparison is False\n";
    }
    else 
    {
        cout << "\nNo Output\n";
    }
}

int main()
{
    //To get 2 array inputs
    float l,m,n;
    cout << "Enter i ,j and k terms for vector 1\n";
    cin >> l >> m >> n;
    Vector V1(l,m,n);
    cout << "Enter i ,j and k terms for vector 2\n";
    cin >> l >> m >> n;
    Vector V2(l,m,n);
    cout << "\n\nMENU\n";
    cout << "For Comparison operations\n1. ==\n2. !=\n3. <=\n4. >=\n5. <\n6. >\n";
    cout << "7 - To Exit\n\n";
    int choice = 0;
    while (choice != 7)
    {
        cout << "Choose an option \n";
        cin >> choice ;

        if(choice == 1){
            V1.display();
            cout << "==";
            V2.display();
            compare_out(V1 == V2);
        }
        else if(choice == 2)
        {
            V1.display();
            cout << "!=";
            V2.display();
            compare_out(V1 != V2);
        }
        else if(choice == 3){
            V1.display();
            cout << "<=";
            V2.display();
            compare_out(V1 <= V2);
        }
        else if(choice == 4){
            V1.display();
            cout << "!=";
            V2.display();
            compare_out(V1 >= V2);
        }
        else if(choice == 5){
            V1.display();
            cout << "<";
            V2.display();
            compare_out(V1 < V2);
        }
        else if(choice == 6){
            V1.display();
            cout << ">";
            V2.display();
            compare_out(V1 > V2);
        }
        else if(choice == 7){
            cout << "Thanks for using\n";
        }
        else{
            cout << "Invalid option\n";
        }
    }
    return 0 ;
}