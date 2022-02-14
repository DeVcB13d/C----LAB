//Write a program to perform addition of two complex numbers using constructor
//overloading. The first constructor which takes no argument is used to create
//objects which are not initialized, second which takes one argument is used to
//initialize real and imag parts to equal values and third which takes two
//argument is used to initialized real and imag to two different values.
#include<iostream>
using namespace std ;

class complex{
    float real;
    float imag;
    public:
        complex(void){};
        complex(float a){
            real = imag = a ;
        }
        complex(float x , float y){
            real = x ;
            imag = y ;
        }
        void show(void){
            if (imag >= 0 ){
                cout << real << " + "<< imag << " i" "\n";
            }
            else {cout << real << " - "<<(-1)* imag <<" i" "\n";}
        
        }
        friend complex add(complex ,complex) ;
};

complex add(complex A,complex B){
    complex C ;
    C.real = A.real + B.real ;
    C.imag = A.imag + B.imag ;
    return C ;
}


int main()
{
    complex X = complex(1.2,3.6);
    complex Y = complex(-3.6) ;
    complex Z;
    Z = add(X,Y);
    cout << "X = " ;
    X.show();
    cout << "Y = " ;
    Y.show();
    cout << "Z = " ;
    Z.show();
}