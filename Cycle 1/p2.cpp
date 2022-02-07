/*program to calculate the area of different shapes like Rectangle,Square etc
(at least 5 shapes) using overloaded function area()*/
#include<iostream>
#include<cmath>
using namespace std ;

//Rectangle
float area(int l , int b){
    return l*b;
}

//square
float area(int a){
    return a*a;
}

//triangle 
float area(float a , float b , float c){
    float s = ( a + b + c ) / 2 ;
    int ar = sqrt(s*(s-a)*(s-b)*(s-c));
    return ar ;

}
//circle
float area (float r){
    return (3.14*r*r);
}

//CSA of cylinder 
float area(float r , float h)
{
    return 3.14*r*r*h ;
}
int main(){
    cout << area(30.00,56) << endl ;
    cout << area(4) << endl ;
    cout << area(5,674) << endl ;
    cout << area(4.00,5.7,6.9) << endl ;
    cout << area(7) << endl ;
    return 0 ;
}