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
        void create_matrix();
        void show_matrix();
        friend matrix operator+(matrix A, matrix B);
        friend matrix operator*(matrix A, matrix B);
};

matrix::matrix(int r,int c)
{
    R = r ; C = c ;
    p = new int* [R+1];
    for(int i = 0; i < C ; i++){
        p[i] = new int[C+1];
    }
}

void matrix::create_matrix(){
    for(int i = 0 ; i < R ; i++){
        cout << "For row " << i+1 << "\n";
        for(int j = 0; j < C; j++){
            cout << "Enter elem " << j+1 << ": ";
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
    return e ;    
}

matrix operator* (matrix A, matrix B)
{
        matrix x(A.R,B.C);
        for(int i = 0 ;i < A.R ;i++){
            for(int j = 0 ; j < B.C ; j++){
                int sum = 0;
                for(int n = 0; n<B.R ;n++){
                    sum+= A.p[i][n] * B.p[n][j];
                }
                x.p[i][j] = sum;
            }    
        }
        return x ;
}

int main()
{
    matrix A(3,3);
    matrix B(3,3);
    A.create_matrix();
    B.create_matrix();
    cout << "A = \n";
    A.show_matrix();
    cout << "\n";
    cout << "B = \n";
    B.show_matrix();
    cout << "\n";
    cout << "A + B = \n";
    matrix C = A + B;
    C.show_matrix();
    cout << "\n";
    cout << "A * B = \n";
    matrix D = A * B;
    D.show_matrix();
    cout << "\n";
}



