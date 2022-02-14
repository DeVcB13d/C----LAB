//Write a C++ program to implement a class MATRIX with member functions such
//as matrix_add, matrix_mult, matrix_transpose, matrix_determinant etc

#include<iostream>
using namespace std ;
const int c = 20;
class matrix {
    int mn ;
    int m[c] ;
    public: 
        void makematrix();
        void showmatrix();

};

void matrix::makematrix(void)
{
    cout << "Enter number of rows" ;
    cin >> mn ;
    for(int i = 1 ; i<=mn ; i++){
        int el[mn];
        cout << "For row" << i <<" \n";
        for (int j = 1 ; j<=mn ;j++){
            cout << "Enter column" << j << " :" ;
            cin >> el[j-1] ;
        }
        m[i-1] = el[mn];
    }
}

void matrix::showmatrix(void)
{
    cout.width(3);
    for(int i = 1 ; i<=mn ; i++){
        int m1[mn] = {m[i -1]};
        for (int j = 1 ; j<=mn ;j++){
            cout << m1[j-1] << " " ;
        }
        cout << "\n" ;
    }
}


int main()
{
    matrix A ;
    A.makematrix();
    A.showmatrix();
}