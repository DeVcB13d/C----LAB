//1. Write a C++ program to overload ==, !=, <, <=, > and >= operators as
//member operator functions for a vector object.
#include<iostream>
using namespace std;
class Vector
{
    int size;
    int* Varr;
    public:
        Vector(){}
        Vector(int z,int* k);
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
    cout << "{";
    for(int i = 0 ; i<size ; i++){
        cout << Varr[i] << ",";
    }
    cout << "}";
}

Vector::Vector(int z,int* k)
{
    size = z ;
    Varr = new int[size+1];
    for(int i = 0 ; i<z ; i++){
        k[i] = Varr[i];
    }
}

bool operator==(Vector x,Vector y)
{
    bool ret = true;
    for(int j = 0 ; j < x.size ; j++){
        if(x.Varr[j] != y.Varr[j]){
            ret = false;
            break;
        }
    }
    return ret;
}

bool operator!=(Vector x,Vector y)
{
    bool ret = true;
    for(int j = 0 ; j < x.size ; j++){
        if(x.Varr[j] != y.Varr[j]){
            ret = true;
            break;
        }
    }
    return ret;
}

bool operator<=(Vector x,Vector y)
{
    bool ret = true;
    for(int j = 0 ; j < x.size ; j++){
        if(x.Varr[j] >= y.Varr[j]){
            ret = false;
            break;
        }
    }
    return ret;
}

bool operator>=(Vector x,Vector y)
{
    bool ret = true;
    for(int j = 0 ; j < x.size ; j++){
        if(x.Varr[j] <= y.Varr[j]){
            ret = false;
            break;
        }
    }
    return ret;
}

bool operator<(Vector x,Vector y)
{
    bool ret = true;
    for(int j = 0 ; j < x.size ; j++){
        if(x.Varr[j] > y.Varr[j]){
            ret = false;
            break;
        }
    }
    return ret;
}

bool operator>(Vector x,Vector y)
{
    bool ret = true;
    for(int j = 0 ; j < x.size ; j++){
        if(x.Varr[j] < y.Varr[j]){
            ret = false;
            break;
        }
    }
    return ret;
}



int main()
{
    int l1[6] = {1,3,4,4,2,1};
    int l2[8] = {3,4,5,2,5,2};
    Vector A(6,l1),B(6,l2);

    cout << "A <= B ";
    bool z = (A != B) ;
    cout << z << "\n";
    return 0 ;
}