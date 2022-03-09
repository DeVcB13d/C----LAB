//Write a C++ program using class to process shopping list for a DepartmentalStore. 
//The list include details such as the Code-no and price of each item and
//perform the operations like adding & deleting items to the list and printing the
//total value of an order.

//Not complete

#include<iostream>
#include<cstring>
using namespace std ;
const int m = 20 ;

class Sitems{
    int Code_No ;
    string name ;
    float price ;
    int Nitems; 
    static int inums;
    public:
    void additem(void);
    void deleteitem(int);
    float getprice(void);
    friend void createbill();
};
int Sitems::inums = 0 ;
void Sitems::additem(void){
    cout << "Enter item code: " ;
    cin >> Code_No;
    cout << "Enter item name: " ;
    cin >> name ;
    cout << "Enter item price: " ;
    cin >> price ;
    cout << "Amount of items: ";
    cin >> Nitems;
}
void Sitems::deleteitem(int code){}
void createbill(){} 

int main()
{
    Sitems slist[m];
    cout << "Menu" ;
    cout << "1. To Add items\n";
    cout << "2. To Delete items\n";
    cout << "3. To Create a bill\n";
    int choice = 0 ;
    while (choice != 4)
    {
        cout << "Pick an option : ";
        cin >> choice;
        if ()
    }
}
