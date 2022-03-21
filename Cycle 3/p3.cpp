//3. Write a C++ program to demonstrate the use of exception handling.
#include<iostream>
#include<string>
using namespace std;

class Dictionary
{
    int *keys;
    float *values;
    int size = 0;
    int ctrl = 0;
    public:
        void create();
        void append(int,float);
        float find(int);
        void show();
};

void Dictionary::append(int a,float b)
{
    try
    {
        if (size >0 && size > ctrl)
        {
        keys[ctrl] = a;
            values[ctrl] = b;
            ctrl++;
        }
        else if (size==0)
        {
            throw "Size not assigned\n";
        }
        else
        {
            throw "Size limit exceeded\n";
        }
    }
    catch (char const *e)
    {
        cout << "Exception occured\n";
        cout << e;
    }
}

void Dictionary::create()
{
    cout << "Size : ";cin >> size;
    try
    {
        if (size>0)
        {
        keys = new int[size];
            values = new float[size];
        }
        else 
        {
            throw "Invalid Size\nTry Again\n";
        }
    }
    catch (char const *e)
    {
        cout << e;
        this->create();
    }
}

float Dictionary::find(int x)
{
    try
    {
        if (ctrl < x && x < size)
        {
            throw "keys value not assingned\n";
        }
        else
        {
            int ret_index = -1;
            for(int i = 0;i<ctrl;i++)
            {
                if (keys[i] == x)
                {
                    ret_index = i;
                }
            }
            if (ret_index == -1)
            {
                throw "Key Does not exist try again\n";
            }
            else 
            {
                return values[ret_index];
            }
        }
    }
    catch (char const *e)
    {
        cout << "Exception\n" ;
        cout << e ;
        return 0;
    }
}

void Dictionary::show()
{
    cout << "{ ";
    for(int i = 0;i<ctrl;i++)
    {
        cout << "(" <<keys[i] << ":" << values[i] << ")";
    }
    cout << " }\n";
}

int main()
{
    Dictionary X;
    X.create();
    cout << "\n\nMenu\n";
    cout << "1. Add element\n";
    cout << "2. Find element\n";
    cout << "3. Show the dictionary\n";
    cout << "4. To Exit\n";
    int choice;
    while (choice != 4)
    {
        cout << "\n\nChoose an option : ";cin>>choice;
        cout << "\n\n";
        switch (choice)
        {
        case 1:
            int k;float val;
            cout << "Enter Key : ";cin>>k;
            cout << "Enter value: ";cin>>val;
            X.append(k,val);
            break;
        case 2:
            int el;
            cout << "Enter key of the element : ";
            cin>>el;
            cout << X.find(el) << "\n";
            break;
        case 3:
            X.show();
            break;
        case 4:
            cout << "Thanks!!\n\n";
            break;
        default:
            break;
        }

    }

}