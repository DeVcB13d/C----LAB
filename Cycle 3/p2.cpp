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

int main()
{
    int sz;
    cout << "Enter List Size : ";cin>>sz;
    list<int> L1(sz);
    cout << "For integer list : \n";
    cout << "Enter " <<sz<<" elements : \n";
    for(int i=0;i<sz;i++)
    {
        int Z;
        cout << ">>>";
        cin >> Z;
        L1.append(Z);
    }
    list<char> L2(sz);
    cout << "For char list : \n";
    cout << "Enter " <<sz<<" elements : \n";
    for(int i=0;i<sz;i++)
    {
        char Z;
        cout << ">>> ";
        cin >> Z;
        L2.append(Z);
    }
    cout << "L1 = " ;
    L1.show();
    cout << "L2 = ";
    L2.show();
    return 0;
}



