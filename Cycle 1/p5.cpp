//Write a C++ program to demonstrate the order of execution of constructors & destructors.
#include<iostream>
using namespace std ;

class item{
    float price;
    int code;
    public:
        item(float p,int c){
            cout << "Called constructor 1\n";
            price = p;
            code = c;
        }
        item(){cout << "Called default constructor \n";}
        ~item(){
            cout << "Called a destructor\n";
        }
};

int main()
{
    item a(12.3,4);
    item b ;
    return 0;
}