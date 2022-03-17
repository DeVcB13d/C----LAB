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
    cout << "}\n";
}

Vector::Vector(int z,int* k)
{
    size = z ;
    Varr = new int[size+1];
    for(int i = 0 ; i<z ; i++){
        Varr[i] = k[i];
    }
}

bool operator==(Vector x,Vector y)
{
    bool ret;
    if (x.size == y.size){
        ret = true;
        for(int j = 0 ; j < x.size ; j++){
            if(x.Varr[j] != y.Varr[j]){
                ret = false;
                break;
            }
        }
    }
    else ret = false;
    return ret;
}

bool operator!=(Vector x,Vector y)
{
    bool ret;
    if (x.size == y.size){
        ret = false;
        for(int j = 0 ; j < x.size ; j++){
            if(x.Varr[j] != y.Varr[j]){
                ret = true;
                break;
            }
        }
    }
    else ret = true;
    return ret;
}

bool operator<=(Vector x,Vector y)
{
    bool ret = false;
    int ctrl = 0;
    for(int j = 0 ; (j < x.size && ctrl == 0); j++){
        if(y.Varr[j] > x.Varr[j]){
            ret = true;
            ctrl = 1;
        }
    }
    return ret;
}

bool operator>=(Vector x,Vector y)
{
    bool ret = false;
    int ctrl = 0;
    for(int j = 0 ; (j < x.size && ctrl == 0); j++){
        if(x.Varr[j] > y.Varr[j]){
            ret = true;
            ctrl = 1;
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
        }
    }
    return ret;
}



int main()
{
    int l1[6] = {1,2,3,4,7};
    int l2[6] = {1,2,10,4,6};
    Vector A(6,l1),B(6,l2);
    cout << "\n\n";
    cout << (A <= B) << "\n\n\n";
    cout << (A >=B) << "\n";
    return 0 ;
}