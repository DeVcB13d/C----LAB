//Program 2 

//program to calculate the area of different shapes like 
//Rectangle,Square etc (at least 5 shapes) using 
//overloaded function area()

#include<iostream>
#include<cmath>
using namespace std ;

//Rectangle
float area(int l , int b){
    cout << "Area of rectangle\n";
    return l*b;
}

//square
float area(int a){
    cout << "Area of a square \n";
    return a*a;
}

//triangle 
float area(float a , float b , float c){
    cout << "Area of a triangle\n";
    float s = ( a + b + c ) / 2 ;
    int ar = sqrt(s*(s-a)*(s-b)*(s-c));
    return ar ;

}
//circle

float area (double r){
    cout << "Area of circle \n";
    return (3.14*r*r);
}

//CSA of cylinder 
float area(double r ,double h)
{
    cout << "CSA of a cylinder \n";
    return 3.14*r*r*h ;
}

int main(){
    cout << area(30,56) << "\n\n" ;
    cout << area(4) << "\n\n" ;
    cout << area(5.45,6.74) << "\n\n" ;
    cout << area(4.00,5.7,6.9) << "\n\n" ;
    cout << area(7.67) << "\n\n" ;
    return 0 ;
}