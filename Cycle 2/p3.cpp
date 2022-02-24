//3. Write a C++ program to overload operators like *, <<, >> using friend
//function. The following overloaded operators should work for a class vector.

#include<iostream>
using namespace std;

class Vector
{
    int size;
    int* Varr;
    public:
        Vector(){}
        Vector(int z,int* k);
        friend bool operator* (Vector,Vector);
        
};