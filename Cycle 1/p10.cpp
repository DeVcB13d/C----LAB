// Write a C++ program using class to process shopping list for a DepartmentalStore.
// The list include details such as the Code-no and price of each item and
// perform the operations like adding & deleting items to the list and printing the
// total value of an order.
// 


#include <iostream>
#include <string>
using namespace std;

const int m = 20;


class Sitems
{
    int Code_No;
    string name;
    float price;
    int stock;

public:
    void copy(const Sitems &A);
    int getcode(void) { return Code_No; }
    void additem(void);
    friend void deleteitem(int, int);
    friend void deletestock(int,int);
    float getprice(void);
    void addstock();
    friend void createbill(int);
    friend void stockdetails();
};

//Global variable to have item numbers
int inum2 = 0;
Sitems stocklist[m];
Sitems bill[m];

void Sitems::copy(const Sitems &A)
{
    Code_No = A.Code_No;
    name = A.name;
    price = A.price;
    stock = A.stock;
}


void Sitems::addstock(void)
{
    cout << "Enter item code: ";
    cin >> Code_No;
    cout << "Enter item name: ";
    cin >> name;
    cout << "Enter item price: ";
    cin >> price;
    cout << "Amount of items: ";
    cin >> stock;
}

void deletestock(int code ,int &enums)
{
    int Rcode;
    int rcheck = 0;
    for(int i = 0; i < enums;i++)
    {
        if (stocklist[i].getcode() == code)
        {
            Rcode = i;
            rechek = 1;
        }  
    } 
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
        cout << slist[i].stock<<"\t";
        cout << "\n";
        total += (slist[i].price * slist[i].stock);
    }
    cout << "\nTotal Price = " << total << "\n" ;
    
}


int main()
{
    cout << "\n\nMenu\n\n";
    cout << "1. To add items to the stock\n";
    cout << "2. To delete items from the stock\n";
    cout << "3. To Display the stock details\n";
    cout << "4. To Add items\n";
    cout << "5. To Delete items\n";
    cout << "6. To Create a bill\n";
    cout << "7. Exit\n";

    int choice = 0;
    while (choice != 7)
    {
        cout << "Choose an option : " ;
        cin >> choice;
        if (choice == 1)
        {
            stocklist[inum2].addstock();
        }
        else if (choice == 2)
        {

        }
    }
}
