//Write a C++ program to implement a class MATRIX with member functions such
//as matrix_add, matrix_mult, matrix_transpose, matrix_determinant etc

#include<iostream>
using namespace std ;
const int c = 20;


class MATRIX 
{
    int R,C ;
    int **p ;
    public: 
        MATRIX(){}
        MATRIX(int r,int c);
        MATRIX(const MATRIX &X);
        void add_elem(int i , int j ,int val){p[i][j] = val;}
        void create_matrix(int,int);
        int elem(int r,int c){return (p[r][c]);}
        void show_matrix();
        friend MATRIX matrix_add(MATRIX A, MATRIX B);
        friend MATRIX matrix_mult(MATRIX A, MATRIX B);
        friend MATRIX matrix_transpose(MATRIX A);
        friend MATRIX rowredn(MATRIX);
        int matrix_determinant(MATRIX);
};

MATRIX::MATRIX(const MATRIX &X){
    R = X.R;
    C = X.C;
    for(int l = 0 ; l < R ; l++){
        for (int k = 0 ; k < C ; k++ ){
            p[l][k] = X.p[l][k];
        }
    }
}

MATRIX::MATRIX(int r,int c)
{
    R = r ;
    C = c ;
    p = new int*[R+2];
    for (int i = 0;i<C;i++){
        p[i] = new int[C+2] ;
    }
}

void MATRIX::create_matrix(int r,int c)
{
    int value;
    R = r ;
    C = c ;
    p = new int*[R+1];
    for (int i = 0;i<C;i++){
        p[i] = new int[C+1] ;
    }
    for(int l = 0 ; l < R ; l++){
        cout << "For row " << l+1 << "\n";
        for (int k = 0 ; k < C ; k++ ){
            cout << "Enter element " << k + 1 << ": " ;
            cin >>  value ;
            p[l][k] = value ;
        }
    }
}

void MATRIX::show_matrix()
{
    cout << "\n\n";
    for(int i = 0 ;i < R ;i++){
        for(int j = 0 ; j < C ; j++){
            cout << p[i][j] << " " ;
        }
        cout << "\n";
    }
    cout << "\n\n";
}

MATRIX matrix_add(MATRIX A , MATRIX B)
{
    
    if (A.C == B.C && A.R == B.R){
        MATRIX x(A.R,A.C);
        for(int i = 0 ;i < A.R ;i++){
            for(int j = 0 ; j < A.C ; j++){
                x.p[i][j] = A.p[i][j] + B.p[i][j];
            }    
        }
        return x ;
    }
    else{
        cout << "Dimensions differernt cannot add\n";
        MATRIX y(1,1);
        return y;
    }
}

MATRIX matrix_mult(MATRIX A , MATRIX B)
{
    
    if (A.C == B.R){
        MATRIX x(A.R,B.C);
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
    else{
        cout << "Dimensions not compatible\n";
        MATRIX y(1,1);
        return y;
    }
}

MATRIX matrix_transpose(MATRIX A)
{
    MATRIX X(A.C,A.R) ;
        for(int i = 0 ;i < A.R ;i++){
            for(int j = 0 ; j < A.C ; j++){
                X.p[i][j] = A.p[j][i];
        }
    }
    return X;
}

MATRIX rowredn(MATRIX A)
{
    MATRIX X(A);//copy A to X
    for(int i = 0;i<A.C;i++){
        for(int j = i;j<A.C;j++){
            float f = (X.p[j][i])/(X.p[i][i]);
            for(int k = 0 ; k < A.C ; k++){
                X.p[j][k] = X.p[j][k] - (f*(X.p[i][k]));
            }
        }
    }
    return X ;
}

int MATRIX::matrix_determinant(MATRIX X)
{
    int det = 1 ;
    if (C ==R){
        MATRIX Y = rowredn(X);
        for(int i = 0 ; i<C; i++){
            det = det * Y.p[i][i];
        } 
    }
}

int main()
{
    MATRIX m1;
    m1.create_matrix(3,3);
    cout << "m1 = " ;
    m1.show_matrix();
    MATRIX m2;
    cout << "m2 = ";
    m2.create_matrix(3,3) ;
    m2.show_matrix();
    MATRIX m3,m4,m5;
    cout << "m1 + m2 = " ;
    m3 = matrix_add(m1,m2);
    m3.show_matrix();
    cout << "m1 X m2 = ";
    m4 = matrix_mult(m1,m2);
    m4.show_matrix();
    cout << "m2 transpose = ";
    m5 = matrix_transpose(m2);
    m5.show_matrix();

    return 0 ;

} 