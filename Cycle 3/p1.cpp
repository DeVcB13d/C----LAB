//1. Write a C++ program to demonstrate the use of pure virtual functions and
//abstract base classes.
#include <iostream>
using namespace std;

class sequence
{
    protected:
        float a;
        float cc;
        float* elems;
        int Nels;
    public:
        sequence(float A,float R,int N){
            a = A;cc = R;Nels=N;
        }
        virtual void generate();
        void show();
};

class AP :public sequence
{
    public:
        AP(float A,float R,int N):sequence(A,R,N){
            cout << "hii\n";
        }
        void generate();
};

class GP : public sequence
{
    public:
        GP(float A,float R,int N):sequence(A,R,N){
            cout << "hii\n";
        }
        void generate();
};

void AP::generate()
{
    float a,d;int n;
    Nels = n;
    elems = new float [n];
    elems[0] = a;
    for(int i = 1;i<n;i++)
    {
        elems[i] = elems[i-1] + d;
    }
    cout << "Generation successfull!!\n";
}

void GP::generate()
{
    float a,r;int n;
    Nels = n;
    elems = new float [n];
    elems[0] = a;
    for(int i = 1;i<n;i++)
    {
        elems[i] = elems[i-1]*r;
    }
    cout << "Generation successfull!!\n";
}

void sequence::show()
{
    for(int i = 0; i < Nels;i++)
    {
        cout << elems[i] << " ";
    }
}

int main()
{
    sequence *sptr;
    float a,d;
    int n;
    cout << "Enter A,Cd,term nos: ";
    cin >> a >> d >> n ;
    AP a1(a,d,n);
    sptr = &a1;
    sptr->generate();
    return 0;
}


