/*program using classes to perform bank transaction for n customers
(cust_name, acc_no, acc_type, balance). The program should be menu driven The program should be menu driven
and it should have the following menus like adding new account, withdraw
(keep a min balance of 500), deposit, balance enquiry and account statement
(cust_name, acc_no, acc_type, balance)*/
#include<iostream>
#include<cmath>
using namespace std ;

class customer{
    string cust_name;
    int acc_no;
    char acc_type ;
    float balance ;
    public:
        void addacc(void) ;
        void acc_state(void) ;
        void withdraw(float amount);
        void deposit(float amount){
            balance = balance + amount ;
        }
        void balance_enq(void){
            cout << cust_name << "\n";
            cout << "Balance : " << balance << endl ;
        }
};

//To add an account
void customer::addacc(){
    cout << "Enter your details below :\n\n"; 
    cout << "Enter your name :" ;
    cin >> cust_name ;
    cout << "Enter the account balance : ";
    cin >> acc_no;
    cout << "Enter the account type : " ;
    cin >> acc_type ;
    cout << "Enter the account balance : " ;
    cin >> balance ;
}

//To get the account statement
void customer::acc_state(){
    cout << "NAME      :" << cust_name << "\n" ;
    cout << "AC NUMBER :" << acc_no << "\n";
    cout << "AC TYPE   :" << acc_type << "\n";
    cout << "BALANCE   :" << balance << "\n";
}

void customer::withdraw(float amount){
    if (balance > 500){
        balance = balance - amount ;
    }
    else{cout << "Balance less than 500 , withdrawal not possible"<<endl;}
}

void menu(){
    cout << "   WELCOME  " << "\n" ;
    cout << "\n\n" ;
    cout << "1 : TO ADD YOUR ACCOUNT\n";
    cout << "2 : TO GET AN ACCOUNT STATEMENT\n";
    cout << "3 : DEPOSIT CASH\n";
    cout << "4 : WITHDRAW CASH\n";
    cout << "5 : BALANCE ENQUIRY\n\n";
    cout << "PLEASE SELECT AN OPTION : " ;
    int choice;
    cin >> choice ;
    
    switch (choice){
        case 1 : 

    }
}