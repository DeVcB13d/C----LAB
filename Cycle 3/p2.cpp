//2. Write a C++ program to demonstrate the use of class templates.
#include <iostream>
using namespace std;

template <class T>
class list
{
    T *E;
    int len;
    int end;
    public:
        list(int l)
        {
            len = l;
            end = 0;
            E = new T[l];
        }
        T get(int index){return E[index];};
        T remove(int index);
        void show(void);
        void append(T x);
};

template <class T> 
T list<T>::remove(int index)
{
    T tt = this->get(index);
    if (index < end && index > 0)
    {
        for(int i=index;i<end;i++)
        {
            E[i] = E[i-1];
        }
        len--;
        return tt;
    }
    else throw "Invalid Index\n";
}
template <class T> 
void list<T>::append(T x)
{
    if(len>end)
    {
        E[end] = x;
    }
    end++;
}
template <class T> 
void list<T>::show()
{
    cout << "[";
    for(int i=0;i<end;i++)
    {
        cout << E[i] << ",";
    }
    cout << "]\n";
}

template <class C>
void Menu()
{
    int sz;
    cout << "Enter List Size : ";cin>>sz;
    list<C> L1(sz);
    cout << "Enter " <<sz<<" elements : \n";
    for(int i=0;i<sz;i++)
    {
        C Z;
        cout << ">>>";
        cin >> Z;
        L1.append(Z);
    }
    L1.show();
}


int main()
{
    cout << "Choose a data type for the list :\n";
    cout << "1. int\n2. float\n3. char\n4. Exit\n";
    int choice = 0;
    while (choice != 4)
    {
        cout << "Choose an option : ";
        cin >> choice ;
        switch (choice)
        {
            case 1 :
            {
                Menu<int>();
                break;
            }
            case 2 : 
            {
                Menu<float>();
                break;
            }
            case 3 :
            {
                Menu<char>();
                break;
            }
            case 4 :
            {
                cout << "Exit\n";
                break;
            }
            default:
            {
                cout << "Invalid option\n";
            }
        }
    }
}



