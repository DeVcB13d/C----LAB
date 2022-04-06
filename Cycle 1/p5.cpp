//Write a C++ program to demonstrate the order of execution of constructors & destructors
//for a matrix class
#include<iostream>
using namespace std ;

class matrix 
{
    int R,C;
    int **p;
    public:
        matrix(){cout << "Default constructor\n";}
        matrix(int r,int c);
        int trace(void);
        ~matrix();
};

matrix::matrix(int r,int c)
{
    R = r ; C = c ;
    p = new int*[R+1];
    for(int i = 0; i < R ; i++){
            p[i] = new int[C+1];
        }
    cout<<"Enter  a "<<C<<"X"<<R<<" matrix\n";
    for(int i = 0; i < R ; i++){
        for(int j = 0; j < C ; j++){
            int elem;
            cin >> elem;
            p[i][j] = elem;
        }
    }
    cout << "\nConstructor called\n";
}

matrix::~matrix()
{
    for(int i=0;i<R;i++){
        delete p[i];
    }
    delete p ;
    cout << "Destructor called\n";
}

int matrix::trace()
{
    int tr = 0 ;
    if (R==C){
        for(int i = 0;i<R;i++){
            tr+=p[i][i];
        }
        return tr ;
    }
    else{
        cout << "Dimenstions not compatible\n";
        return 0;
    }
}

int main()
{
    cout << "Creating a matrix\n";
    int r1,c1;
    cout << "Enter number of rows :";
    cin >> r1;
    cout << "Enter number of columns : ";
    cin >> c1;
    matrix B(r1,c1);
    cout << "\nTrace = " << B.trace() << "\n\n";
}