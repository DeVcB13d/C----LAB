
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
        void rowredn();
        void show_matrix();
        void create_matrix(int,int);
};
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
    for(int i = 0 ;i < R ;i++){
        for(int j = 0 ; j < C ; j++){
            cout << p[i][j] << " " ;
        }
        cout << "\n";
    }
    cout << "\n\n";
}
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

void MATRIX::rowredn()
{
    for(int i = 0;i<C;i++){
        for(int j = i;j<C;j++){
            float f = (p[j][i])/(p[i][i]);
            cout << f << "\n";
            for(int k = 0 ; k < C ; k++){
                p[j][k] = p[j][k] - (f*(p[i][k]));
            }
            show_matrix();
        }
    }
}

int main()
{
    MATRIX m1;
    m1.create_matrix(3,3);
    
    m1.show_matrix();
    
    cout << "hi";
    MATRIX m2 ;
    m1.rowredn();
    m1.show_matrix();
    return 0 ;

} 