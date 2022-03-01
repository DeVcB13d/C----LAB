//Write a C++ program using class to process shopping list for a DepartmentalStore. 
//The list include details such as the Code-no and price of each item and
//perform the operations like adding & deleting items to the list and printing the
//total value of an order.

//Not complete

#include<iostream>
#include<cstring>
using namespace std ;
const int m = 20 ;

class Slist{
    int Code_No[m] ;
    string name[m] ;
    float price[m] ;
    int Nitems[m];
    int count;
    public:
    void setcount(){count = 0;}
    void additem(void);
    void deleteitem(int);
    float getprice(void){
            float total = 0;
            for (int i = 0 ; i<count ; i++){
                total+=(price[i]*Nitems[i]);
            }
            return total ;
        }
    void createbill();
};



void Slist::additem(void){
    cout << "Enter item code: " ;
    cin >> Code_No[count];
    cout << "Enter item name: " ;
    cin >> name[count] ;
    cout << "Enter item price: " ;
    cin >> price[count] ;
    cout << "How many ";
    cin >> Nitems[count];
    count++;
}

void Slist::deleteitem(int code){
    int index;
    for(int i = 0 ; i < count ; i++){
        if (Code_No[i] == code){
            index = i;
        }
    }
    for(int j = index;j<count ;j++ ){
        Code_No[j] = Code_No[j-1];
        name[j] = name[j+1];
        price[j] = price[j+1];
        Nitems[j] = Nitems[j+1];
    }
    count--;
    cout << "Deleted successfully !!\n";
}

void Slist::createbill(){
    cout <<"No\tCode\tName  \tPrice\tCost\n";
    for(int j = 0; j <count ; j++){
        cout << j << " \t" << Code_No[j] << "\t";
        cout << name[j] << "\t" << price[j] << "\t";
        cout << Nitems[j] << "\n";
    }
    cout << "\nTotal price = " << getprice() << endl;
}


int main(){
    Slist A ;
    A.setcount();
    cout << "Menu\n" ;
    cout << "1. Add an item\n2.Delete an item\n";
    cout << "3. Create bill\n";
    int ch = 0;
    while (ch == 0){
        int choice ;
        cout << "Pick an option :";
        cin >> choice ;
        if (choice == 1){A.additem();}
        else if (choice == 2){
            int c ;
            cout << "Enter item code to delete :";
            cin >> c ;
            A.deleteitem(c);
        }
        else if (choice == 3){
            A.createbill();
        }
        else{cout << "Invalid option ";}
        cout << "\nEnter 0 to continue : " ;
        cin >> ch ;
    }
    return 0 ;
}
