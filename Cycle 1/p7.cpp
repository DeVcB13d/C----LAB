//Write a C++ program to implement a class MATRIX with member functions such
//as matrix_add, matrix_mult, matrix_transpose, matrix_determinant etc

#include<iostream>
using namespace std ;
const int c = 20;
class MATRIX {
    int R,C ;
    int **p ;
    public: 
        MATRIX(){R = 0;C =0;}
        MATRIX(int r,int c);
        void add_elem(int i , int j ,int val){
            p[i][j] = val;
        }
        void create_matrix();
        int elem(int r,int c){
            return (p[r][c]);}
        void show_matrix();
        friend MATRIX matrix_add(MATRIX A, MATRIX B);
        friend MATRIX matrix_mult(MATRIX A, MATRIX B);
        friend MATRIX matrix_transpose(MATRIX A);
        int matrix_determinant();
};

MATRIX::MATRIX(int r,int c){
    R = r ;
    C = c ;
    p = new int*[R];
    for (int i = 0;i<C;i++){
        p[i] = new int[C] ;
    }
}

void MATRIX::create_matrix(){
    int value;
    for(int j = 0 ; j < R ; j++){
        cout << "For row " << j+1 << "\n";
        for (int k = 0 ; k < C ; k++ ){
            cout << "Enter element " << k + 1 << ": " ;
            cin >>  value ;
            add_elem(j,k,value);
        }
    }
}

void MATRIX::show_matrix(){
    for(int i = 0 ;i < R ;i++){
        for(int j = 0 ; j < C ; j++){
            cout << p[i][j] << " " ;
        }
        cout << "\n";
    }
    cout << "\n\n";
}

MATRIX matrix_add(MATRIX A , MATRIX B){
    
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
        cout << "Dimensions diifferernt cannot add\n";
        MATRIX y(1,1);
        return y;
    }
}

MATRIX matrix_mult(MATRIX A , MATRIX B){
    
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

MATRIX matrix_transpose(MATRIX A){
    MATRIX X(A.C,A.R) ;
        for(int i = 0 ;i < A.R ;i++){
            for(int j = 0 ; j < A.C ; j++){
                X.p[i][j] = A.p[j][i];
        }
    }
    return X;
}

int main(){
    MATRIX m1(4,2);
    m1.create_matrix();
    MATRIX m2(4,3);
    m2.create_matrix();
    MATRIX m3 = matrix_mult(m1,m2);
    MATRIX m4 = matrix_transpose(m2);
    m1.show_matrix();
    m2.show_matrix();
    m3.show_matrix();
    m4.show_matrix();
} 