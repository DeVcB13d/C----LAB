//4. Write a C++ program for developing a matrix class which can handle integer
//matrices of different dimensions. Also overload the operator for addition and
//multiplication of matrices. Use double pointers in your program to dynamically
//allocate memory for the matrices.

#include<iostream>
using namespace std;

class matrix 
{
    int R,C ;
    int **p ;
    public: 
        matrix(){}
        matrix(int r,int c);
        void create_matrix(int,int);
        void show_matrix();
        friend matrix operator+(matrix A, matrix B);
        friend matrix operator*(matrix A, matrix B);
};

matrix::matrix(int r,int c)
{
    R = r ; C = c ;
    p = new int* [R+1];
    for(int i = 0; i < C ; i++){
        *p = new int[C+1];
    }
}

void matrix::create_matrix(int,int){
    for(int i = 0 ; i < R ; i++){
        cout << "For row " << i+1 << "\n";
        for(int j = 0; j < C; j++){
            cout << "Enter elem " << j+1;
            int e ;
            cin >> e ;
            p[i][j] = e ;
        }
    }
}

void matrix::show_matrix(){
    for(int i = 0 ; i < R ; i++){
        for(int j = 0; j < C; j++){
            cout << p[i][j] << " " ;
        }
        cout << "\n" ;
    } 
}

matrix operator+ (matrix A , matrix B){
    matrix e(A.R,A.C);
    for(int i = 0 ; i < e.R ; i++){
        for(int j = 0; j < e.C; j++){
            e.p[i][j] = A.p[i][j] + B.p[i][j]; 
        }
        
    }
}







