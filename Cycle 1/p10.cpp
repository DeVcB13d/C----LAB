//Write a C++ program using class to process shopping list for a DepartmentalStore. 
//The list include details such as the Code-no and price of each item and
//perform the operations like adding & deleting items to the list and printing the
//total value of an order.

//Not complete

#include<iostream>
using namespace std ;
const int m = 20 ;

class item{
    int Code_No[m] ;
    char name[m] ;
    float price[m] ;
    int count ;
    static float totalitems ;
    public:
        void setcount(void){
            count = 0 ;
        }
        void additem(void);
        void showitem(void);
        void deleteitem(void);
        float getprice(void){
            return price;
        }
};



void item::additem(void){
    cout << "Enter item code: " ;
    cin >> Code_No[count] ;
    cout << "Enter item name: " ;
    cin >> name[count] ;
    cout << "Enter item price: " ;
    cin >> price[count] ;
}

void item::showitem(void){
    cout << "Item code\t"<< Code_No<<"\n";
    cout << "Name     \t"<<name<<"\n";
    cout << "Price    \t"<<price<<"\n";
}

int main(){
    cout << "Menu\n" ;
    cout << "1. Add an item\n 2.Delete an item\n";
    cout << "3. Create bill";
}
