//3. Write a C++ program to overload operators like *, <<, >> using friend
//function. The following overloaded operators should work for a class vector.

#include<iostream>
using namespace std;

class Vector
{
    float i,j,k;
    public:
        friend float operator*(Vector,Vector);
        friend ostream &operator<<( ostream &output, const Vector &V ) { 
            output << V.i << "i + " << V.j << "j + " << V.k << "k\n" ;
            return output;            
        }
        friend istream &operator>>( istream  &input, Vector &V ) { 
            input >> V.i >> V.j >> V.k;
            return input;            
    }
};

float operator*(Vector A,Vector B)
{
    float DP = (A.i*B.i)+(A.j*B.j)+(A.k*B.k);
    return DP;
}


int main()
{
    Vector A,B;
    cout << "Enter the vector A i,j an k : ";
    cin >> A ;
    cout << "Enter the vector B i,j an k : ";
    cin >> B ;
    cout << "\nA = "<< A << "\n";
    cout << "B = "<< B << "\n";
    int C = A * B ;
    cout << "C = A * B = " << C << "\n\n" ;
    return 0 ;
}


