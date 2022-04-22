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
    friend void Add_item_Bill(Sitems *Bill_list,Sitems* Stock_list,int &BillItemNum,int &StocKItemNum);
    friend void Delete_item_Bill(int code, int &enums);
    friend void createBill(int&);
    //general fns
    void copy(const Sitems &A);
    int getcode(void){ return Code_No; }
    int getstock(void){return stock;}
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
        enums--;
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
        cout << Stock_list[i].Code_No << "\t";
        cout << Stock_list[i].name<<"\t";
        cout << Stock_list[i].price<<"\t";
        cout << Stock_list[i].stock<<"\t";
        cout << Stock_list[i].stock*Stock_list[i].price;
        cout << "\n";
        total += (Stock_list[i].price * Stock_list[i].stock);
    }
    cout << "\nTotal Price = " << total << "\n" ;   
}

void Add_item_Bill(Sitems *Bill_list,Sitems* Stock_list,int &BillItemNum,int &StockItemNum)
{
    int CodeIn;
    cout << "Enter Item code : ";
    cin >> CodeIn;
    int Item_Index = -1;
    int Stock_index = -1;
    for(int i = 0;i<StockItemNum;i++)
    {
        if (Stock_list[i].Code_No==CodeIn)
        {
            Stock_index = i;
        }  
    }
    if (Stock_index >= 0)
    {
        int Buy_Num;
        cout << "Enter the Number of Items : ";
        cin >> Buy_Num;
        if (Buy_Num < Stock_list[Stock_index].stock){
            for(int i = 0;i<StockItemNum;i++)
            {
                if (Stock_list[i].getcode() == CodeIn)
                {
                    Stock_index = i;
                }
            }
            if (Stock_index>=0)
            {
                Bill_list[BillItemNum].copy(Stock_list[Stock_index]);
                Bill_list[BillItemNum].N_bought = Buy_Num;
                Stock_list[Stock_index].stock -= Buy_Num;
                BillItemNum++;
            }
            else
            {
                cout << "Item does not exist\n";
            }
        }
        else
        {
            cout << "Item is out of stock\n\n";
        }
    }
    else
    {
        cout << "Item code is incorrect\n";
    }
}

void createBill(int &BillItemNum)
{
    cout << "\t\tBILL\n";
    cout << "No.\tCode\tName\tPrice\tAmount\tNetPrice\n";
    float Total = 0;
    for(int i = 0;i<BillItemNum;i++)
    {
        cout<<i<<"\t"<<Bill[i].Code_No<<"\t";
        cout<<Bill[i].name<<"\t";
        cout<<Bill[i].price<<"\t"<<Bill[i].N_bought<<"\t";
        Total+=(Bill[i].price*Bill[i].N_bought);
        cout<<Bill[i].price*Bill[i].N_bought<<"\n";
    }
    cout << "Total : "<<Total ;
}

int main()
{
    cout << "\n\nMenu\n\n";
    cout << "1. To add items to the stock\n";
    cout << "2. To delete items from the stock\n";
    cout << "3. To Display the stock details\n";
    cout << "4. To Add items to the bill\n";
    cout << "5. To Delete items\n";
    cout << "6. To Create a Bill\n";
    cout << "7. Exit\n";
    int choice = 0;
    while (choice != 7)
    {
        cout << "\n\nChoose an option : " ;
        cin >> choice;
        if (choice == 1)
        {
            Stock_list[Stock_num].Add_stock();
            Stock_num++;
        }
        else if (choice == 2)
        {
            int Delcode;
            cout << "Enter the code of the item to delete : ";
            cin >> Delcode;
            Delete_stock(Delcode,Stock_num);
        }
        else if (choice == 3)
        {
            Full_stock_details();
        }
        else if (choice == 4)
        {
            Add_item_Bill(Bill,Stock_list,Bill_num,Stock_num);
        }
        else if (choice == 5)
        {
            int DelCode;
            cout << "Enter the Code of Item to Delete from Bill : ";
            cin >> DelCode;
            Delete_item_Bill(DelCode,Bill_num);
        }
        else if(choice == 6)
        {
            createBill(Bill_num);
        }
        else if(choice == 7)
        {
            cout << "Thanks for using\n\n";
        }
        else
        {
            cout << "Invalid option selected\n";
        }
    }
}
