//3. Write a C++ program to overload operators like *, <<, >> using friend
//function. The following overloaded operators should work for a class vector.

#include<iostream>
using namespace std;

class Vector
{
    int size;
    int* Varr;
    public:
        friend Vector operator* (Vector,Vector);
        friend ostream &operator<<( ostream &output, const Vector &V ) { 
            output << "{" ;
            for (int i = 0;i < V.size;i++)
            {
                output<<V.Varr[i] << ",";
            }
            output <<"}";
            return output;            
        }
        friend istream &operator>>( istream  &input, Vector &V ) { 
            input >> V.size;
            V.Varr = new int [V.size];
            for (int i = 0;i < V.size;i++)
            {
                input >> V.Varr[i];
            }
            return input;            
    }
};

Vector operator*(Vector A,Vector B)
{
    Vector C ;
    if (A.size > B.size) C.size = A.size ;
    else C.size  = B.size;
    C.Varr = new int [C.size];
    for(int i  = 0;i<C.size;i++)
    {
        if (A.Varr[i] && B.Varr[i]){
            C.Varr[i] = A.Varr[i]*B.Varr[i];
        }
        else{
            C.Varr[i] = 0 ;
        }
    }
    return C;
}
int main()
{
    Vector A,B,C;
    cout << "Enter the vector A size and elements: ";
    cin >> A ;
    cout << "\nA = "<< A << "\n";
    cout << "Enter the vector B size and elements: ";
    cin >> B ;
    cout << "\nB = "<< B << "\n";
    C = A * B ;
    cout << "C = A * B = " << C << "\n" ;
    return 0 ;
}


