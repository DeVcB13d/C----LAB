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
        void create_matrix(int,int);
        void show_matrix();
        friend MATRIX matrix_add(MATRIX A, MATRIX B);
        friend MATRIX matrix_mult(MATRIX A, MATRIX B);
        friend MATRIX matrix_transpose(MATRIX A);
        friend int trace(MATRIX A);
        void get_RC();
};

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
        cout << "Enter " << C << " elements:\n ";
        for (int k = 0 ; k < C ; k++ ){
            cin >>  value ;
            p[l][k] = value ;
        }
    }
}

void MATRIX::show_matrix()
{
    cout << "\n";
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
    if (A.R == B.R && A.C == B.C){
        MATRIX x(A.R,B.C);
        for(int i = 0 ;i < A.R ;i++){
            for(int j = 0 ; j < B.C; j++){
                x.p[i][j] = A.p[i][j] + B.p[i][j];
            }    
        }
        return x ;
    }
    else{
        cout << "Cannot Add\n";
        MATRIX X;
        return X ;
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

int trace(MATRIX A)
{
    if(A.C == A.C){
        int tr = 0 ;
        for(int i = 0; i<A.C ; i++){
            tr+=A.p[i][i];
        }
        return tr;
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

void MATRIX::get_RC(){
    int r1,c1;
    cout << "Enter Number of Rows :";
    cin >> r1 ;
    cout << "Enter Number of Columns :";
    cin >> c1 ;
    MATRIX(r1,c1);
    create_matrix(r1,c1);
}
int main()
{
    cout << "To create 1st Matrix :\n";
    MATRIX M1 ;
    M1.get_RC();
    cout << "To create 2nd Matrix :\n";
    MATRIX M2 ;
    M2.get_RC();
    cout << "M1 = \n";
    M1.show_matrix();
    cout << "M2 = \n";
    M2.show_matrix();
    cout << "Adding them : ";
    MATRIX  M3,M4,M5,M6;
    M3 = matrix_add(M1,M2);
    M4 = matrix_mult(M1,M2);
    M5 = matrix_transpose(M1);
    M6 = matrix_transpose(M2);
    cout << "M1 + M2  = ";
    M3.show_matrix();
    cout << "M1 X M2  = ";
    M4.show_matrix();
    cout << "M1 Transpose = ";
    M5.show_matrix();
    cout << "M2 Transpose = ";
    M6.show_matrix();
    cout << "M1 Trace = " << trace(M1) << endl;
    cout << "M2 Trace = " << trace(M2) << endl;


} 