#include<iostream>
using namespace std ;

class matrix 
{
    int m,n ;
    int **p ;
    public:
        matrix(){};
        matrix(int M,int N);
        friend matrix rr(matrix K);
        void show();
};

matrix::matrix(int M , int N)
{
    m = M ; n = N ;
    p = new int*[M+1] ;
    for(int i = 0 ; i < n ; i++){
        *p = new int[N+1] ;
    }
    for(int i = 0; i < m ; i++){
        cout << "Row " << i + 1 << "\n" ;
        for(int j = 0 ; j < m ; j++){
            cout << "elem " << j + 1 << " : ";
            int elem ;
            cin >> elem ;
            p[i][j] = elem ;
        }
    }
}

matrix rr(matrix A)
{
    matrix R ;
    R.m = A.m; R.m = R.n ;
    //section to copy
    for(int i = 0 ; i < R.m ; i++){
        for(int j = 0 ; j < R.n ; j++){
            R.p[i][j] = A.p[i][j];
        }
    }
    //Row reduction
    for(int i = 0;i<R.m;i++){
        for(int j = i;j<R.n;j++){
            float f = (A.p[j][i])/(A.p[i][i]);
            for(int k = 0 ; k < A.n ; k++){
                R.p[j][k] = R.p[j][k] - (f*(R.p[i][k]));
            }
        }
    }
}

void matrix::show()
{
    for(int i = 0 ;i < m ;i++){
        for(int j = 0 ; j < n ; j++){
            cout << p[i][j] << " " ;
        }
        cout << "\n";
    }
    cout << "\n\n";
}

int main()
{
    matrix A(3,3);
    A.show();
    matrix B ;
    B = rr(A);
    B.show();
    return 0 ;
}

