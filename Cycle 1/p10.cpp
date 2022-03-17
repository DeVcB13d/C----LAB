// Write a C++ program using class to process shopping list for a DepartmentalStore.
// The list include details such as the Code-no and price of each item and
// perform the operations like adding & deleting items to the list and printing the
// total value of an order.



#include <iostream>
#include <string>
using namespace std;

const int m = 20;


class Sitems
{
    int Code_No;
    string name;
    float price;
    int Nitems;

public:
    void copy(const Sitems &A);
    int getcode(void) { return Code_No; }
    void additem(void);
    friend void deleteitem(int, int);
    float getprice(void);
    friend void createbill(int);
};


//Global variable to have item numbers
int inum2 = 0;
Sitems slist[m];

void Sitems::copy(const Sitems &A)
{
    Code_No = A.Code_No;
    name = A.name;
    price = A.price;
    Nitems = A.Nitems;
}


void Sitems::additem(void)
{
    cout << "Enter item code: ";
    cin >> Code_No;
    cout << "Enter item name: ";
    cin >> name;
    cout << "Enter item price: ";
    cin >> price;
    cout << "Amount of items: ";
    cin >> Nitems;
}


void deleteitem(int code, int &enums)
{
    int Rcode;
    int rcheck = 0;
    // To search and return the index
    for (int i = 0; i < enums; i++)
    {
        if (slist[i].getcode() == code)
        {
            Rcode = i;
            rcheck = 1;
        }
    }
    if (rcheck == 1)
    {
        for (int j = Rcode; j < enums; j++)
        {
            slist[j].copy(slist[j + 1]);
        }
        enums--;
        cout << "Successfull !!!\n";
    }
    else 
    {
        cout << "Invalid Code\n";
    }
}

void createbill(int inum)
{
    float total = 0 ;
    cout << "\n\nICode\tIName\tIprice\tItems\n";
    for(int i = 0; i < inum2; i++)
    {
        cout << slist[i].Code_No << "\t";
        cout << slist[i].name<<"\t";
        cout << slist[i].price<<"\t";
        cout << slist[i].Nitems<<"\t";
        cout << "\n";
        total += (slist[i].price * slist[i].Nitems);
    }
    cout << "\nTotal Price = " << total << "\n" ;
    
}


int main()
{
    cout << "\n\nMenu\n\n";
    cout << "1. To Add items\n";
    cout << "2. To Delete items\n";
    cout << "3. To Create a bill\n";
    cout << "4. Exit\n";
    int choice = 0;
    while (choice != 4)
    {
        cout << "\n\nPick an option : ";
        cin >> choice;
        if (choice == 1)
        {
            slist[inum2].additem();
            inum2++;
        }
        else if (choice == 2)
        {
            cout << "Enter item code to delete : ";
            int icode;
            cin >> icode;
            cout << "\n";
            deleteitem(icode, inum2);
        }
        else if (choice == 3)
        {
            createbill(inum2);
        }
        else if (choice == 4)
        {
            cout << "Thanks for using!!!\n";
        }
        else
        {
            cout << "Invalid option\nTry again";
        }
    }
}
