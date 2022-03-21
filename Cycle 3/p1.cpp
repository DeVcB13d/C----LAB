//1. Write a C++ program to demonstrate the use of pure virtual functions and
//abstract base classes.
#include <iostream>
#include <cmath>
using namespace std;

class sequence
{
    protected:
        float a;
        float cc;
        float* elems;
        int Nels;
    public:
        virtual void generate(){}
        virtual void mean(){}
        void show();
};

class AP :public sequence
{
    public:
        void generate();
        void mean();
};

class GP : public sequence
{
    public:
        void generate();
        void mean();
};

void AP::generate()
{
    cout << "First term        : ";
    cin >> a;
    cout << "Common Difference : ";
    cin >> cc;
    cout << "Number of terms   : ";
    cin >> Nels;
    elems = new float [Nels];
    elems[0] = a;
    for(int i = 1;i<Nels;i++)
    {
        elems[i] = elems[i-1] + cc;
    }
    cout << "Generation successfull!!\n\n";
}

void GP::generate()
{
    cout << "First term      : ";
    cin >> a;
    cout << "Common Ratio    : ";
    cin >> cc;
    cout << "Number of terms : ";
    cin >> Nels;
    elems = new float [Nels];
    elems[0] = a;
    for(int i = 1;i<Nels;i++)
    {
        elems[i] = elems[i-1] * cc;
    }
    cout << "Generation successfull!!\n\n";
}

void sequence::show()
{
    for(int i = 0; i < Nels;i++)
    {
        cout << elems[i] << " ";
    }
    cout << "\n";
}

void AP::mean()
{
    float sum = 0;
    for(int j = 0;j<Nels;j++)
    {
        sum+=float(elems[j]);
    }
    cout << "Arithmetic mean = " << float(sum/Nels) << "\n";
}
void GP::mean()
{
    float pdt = 1;
    for(int j = 0;j<Nels;j++)
    {
        pdt*=elems[j];
    }
    float n = (1/float(Nels));
    float avg = pow(pdt,n);
    cout << "Geometric mean = " << avg << "\n";
}
int main()
{
    cout << "Menu\n";
    cout << "1. AP\n2. GP\n3. Exit\n";
    sequence *sptr;
    int choice1 = 0;
    
    do
    {
        int choice2 = 0;
        cout << "Select a sequence type: ";
        cin  >> choice1 ;
        switch (choice1)
        {
            case 1 : 
            {
                sptr = new AP;
                sptr->generate();
                break;
            }
            case 2 :
            {
                sptr  = new GP;
                sptr->generate();
                break;
            }
            case 3 :
            {
                cout << "Thanks\n\n";
                break;
            }
            default :
                cout << "Invalid option\n";
        }
        
        cout << "\n\n1.Re-Generate the seqence\n";
        cout << "2.Calculate the mean\n";
        cout << "3.Show the sequence\n";
        
        while(choice2 != 4)
        {
            cout << "Select an operation";
            cout << ">>>";cin >> choice2;
            cout << "\n\n";
            switch (choice2)
            {
            case 1:
                sptr->generate();
                break;
            case 2:
                sptr->mean();
                break;
            case 3:
                sptr->show();
                break;
            case 4:
                cout << "Thanks\n";
                break;
            default:
                cout << "Invalid option\n";
            }
        }
    }
    while (choice1 != 3);
}


