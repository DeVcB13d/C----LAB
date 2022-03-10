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
        friend MATRIX matrix_add(MATRIX& A, MATRIX& B);
        friend MATRIX matrix_mult(MATRIX& A, MATRIX& B);
        friend MATRIX matrix_transpose(MATRIX& A);
        friend int trace(MATRIX& A);
        void get_RC();
        //~MATRIX();
};

MATRIX::MATRIX(int r,int c)
{
    R = r ;
    C = c ;
    p = new int*[R+1];
    for (int i = 0;i<C;i++){
        p[i] = new int[C+1] ;
    }
}

void MATRIX::create_matrix(int r,int c)
{
    int value;
    R = r ;
    C = c ;
    p = new int*[R];
    for (int i = 0;i<R;i++){
        p[i] = new int[C] ;
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

MATRIX matrix_add(MATRIX& A , MATRIX& B)
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

MATRIX matrix_mult(MATRIX& A , MATRIX& B)
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

int trace(MATRIX& A)
{
    if(A.C == A.C){
        int tr = 0 ;
        for(int i = 0; i<A.C ; i++){
            tr+=A.p[i][i];
        }
        return tr;
    }
}

MATRIX matrix_transpose(MATRIX& A)
{
    MATRIX X(A.C,A.R) ;
        for(int i = 0 ;i < A.R ;i++){
            for(int j = 0 ; j < A.C ; j++){
                X.p[i][j] = A.p[j][i];
        }
    }
    return X;
}
/*
MATRIX::~MATRIX()
{
    for(int i=0;i<R;i++){
        delete p[i];
    }
    delete p ;
    cout << "Destructor called \n";
}
*/

void MATRIX::get_RC(){
    int r1,c1;
    cout << "Enter Number of Rows and Columns :";
    cin >> r1 >> c1;
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
    cout << "MENU :\n";
    cout << "1. Add\n2. Multiply\n3.Transpose\n";
    cout << "4.Traces\n5.Exit\n";
    int choice = 0 ;
    
    while (choice != 5){
        cout << "Choose :";
        cin >> choice ;
        if (choice == 1){
            MATRIX  M3;
            M3 = matrix_add(M1,M2);
            cout << "M1 + M2  = ";
            M3.show_matrix();
        }
        else if (choice == 2)
        {
            MATRIX M4;
            M4 = matrix_mult(M1,M2);
            cout << "M1 X M2  = ";
            M4.show_matrix();
        }
        else if (choice == 3)
        {
            MATRIX M5,M6;
            M5 = matrix_transpose(M1);
            M6 = matrix_transpose(M2);
            cout << "M1 Transpose = ";
            M5.show_matrix();
            cout << "M2 Transpose = ";
            M6.show_matrix();

        }

        else if (choice == 4)
        {
            cout << "M1 Trace = " << trace(M1) << endl;
            cout << "M2 Trace = " << trace(M2) << endl;
        }
        else if (choice == 5)
        {
            cout << "Thanks\n";
        }
        else
        {
            cout << "Invalid option\n";
        }
    }
    return 0 ;

} 