/*program to calculate the area of different shapes like Rectangle,
Square etc (at least 5 shapes) using overloaded function area()*/
#include<iostream>
#include<cmath>
using namespace std ;

//Rectangle
float area(float l , float b){
    return l*b;
}

//square
float area(float a){
    return a*a;
}

//triangle 
float area(float a , float b , float c){
    float s = ( a + b + c ) / 2 ;
    int ar = sqrt(s*(s-a)*(s-b)*(s-c));
    return ar ;

}

int main(){
    cout << area(30.55,56.33) << endl ;
    cout << area(4.00) << endl ;
    cout << area(4.00,5.7,6.9) << endl ;
    cout << area(7) << endl ;
    return 0 ;
}