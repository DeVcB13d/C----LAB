//Write a C++ program to demonstrate the order of execution of constructors & destructors. And the dynamic memory allocation of mATRIX
#include<iostream>
using namespace std ;
//use matrix class + 1 fn
class item{
    float price;
    int code;
    public:
        item(float p,int c){
            cout << "Called constructor 1\n";
            price = p;
            code = c;
        }
        ~item(float p,int c){
            cout << "Called destructor 1\n";
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
    {
        item b ;
    }
        
    return 0;
}
