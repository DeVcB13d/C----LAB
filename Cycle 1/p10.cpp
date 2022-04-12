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
    int stock = 0;
    int N_bought = 0;
public:
    //Stock related fns
    friend void Delete_stock(int,int);
    void Add_stock();
    friend void Full_stock_details();
    //Bill related fns
    void Add_item_Bill(int);
    friend void Delete_item_Bill(int, int);
    friend void createBill(int);
    //general fns
    void copy(const Sitems &A);
    int getcode(void) { return Code_No; }
    float getprice(void);
};

//Global variable to have item numbers
int Stock_num = 0;
int Bill_num = 0;
//List to store the stock
Sitems Stock_list[m]; 
//List to store the Bill
Sitems Bill[m];

void Sitems::copy(const Sitems &A)
{
    Code_No = A.Code_No;
    name = A.name;
    price = A.price;
    stock = A.stock;
}

//Add a new item to the stock
void Sitems::Add_stock(void)
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

void Delete_stock(int code ,int &enums)
{
    int Del_index;
    int rcheck = 0;
    for(int i = 0; i < enums;i++)
    {
        if (Stock_list[i].getcode() == code)
        {
            Del_index = i;
            rcheck = 1;
        }  
    } 
    if (rcheck == 1)
    {
        for(int i = Del_index;i<Stock_num;i++)
        {
            Stock_list[i-1].copy(Stock_list[i]);
        }
        cout << "Deleted successfully\n";
    }
    else
    {
        cout << "ItemIndex not found\n";
    }
}

void Delete_item_Bill(int code, int &enums)
{
    int Rcode;
    int rcheck = 0;
    //To search and return the index
    for (int i = 0; i < enums; i++)
    {
        if (Bill[i].getcode() == code)
        {
            Rcode = i;
            rcheck = 1;
        }
    }
    if (rcheck == 1)
    {
        for (int j = Rcode; j < enums; j++)
        {
            Bill[j].copy(Bill[j + 1]);
        }
        enums--;
        cout << "Deleted successfully\n";
    }
    else 
    {
        cout << "ItemIndex not found\n";
    }
}

void Full_stock_details()
{
    float total = 0 ;
    cout << "\n\nICode\tIName\tIprice\tItems\tTotal\n";
    for(int i = 0; i < Stock_num; i++)
    {
        cout << Bill[i].Code_No << "\t";
        cout << Bill[i].name<<"\t";
        cout << Bill[i].price<<"\t";
        cout << Bill[i].stock<<"\t";
        cout << Bill[i].stock*Bill[i].price;
        cout << "\n";
        total += (Bill[i].price * Bill[i].stock);
    }
    cout << "\nTotal Price = " << total << "\n" ;   
}

void Sitems::Add_item_Bill(int &TotalItems)
{
    cout << "Enter Item code : ";
    cin >> 
    for(int i = 0;i<TotalItems;i++)
    {
        if 
    }
}






int main()
{
    cout << "\n\nMenu\n\n";
    cout << "1. To add items to the stock\n";
    cout << "2. To delete items from the stock\n";
    cout << "3. To Display the stock details\n";
    cout << "4. To Add items\n";
    cout << "5. To Delete items\n";
    cout << "6. To Create a Bill\n";
    cout << "7. Exit\n";

    int choice = 0;
    while (choice != 7)
    {
        cout << "Choose an option : " ;
        cin >> choice;
        if (choice == 1)
        {
            Stock_list[Stock_num].addstock();
        }
        else if (choice == 2)
        {

        }
    }
}
