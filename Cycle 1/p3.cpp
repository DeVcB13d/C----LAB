/*program using classes to perform bank transaction for n customers
(cust_name, acc_no, acc_type, balance). The program should be menu driven The program should be menu driven
and it should have the following menus like adding new account, withdraw
(keep a min balance of 500), deposit, balance enquiry and account statement
(cust_name, acc_no, acc_type, balance)*/

#include<iostream>
#include<string>
using namespace std ;

const int m = 20;

class customer{
    int count;
    string cust_name[m];
    int acc_no[m];
    char acc_type[m] ;
    float balance[m] ;
    public:
        int cust_index(int acno);
        void addacc(void) ;
        void acc_state(int index) ;
        void withdraw(float amount , int index);
        void deposit(float amount , int index){
            float b = balance[index];
            b = b + amount ;
            balance[index] = b ;
        }
        void balance_enq(int index){
            cout << cust_name[index] << "\n";
            cout << "Balance : " << balance[index] << endl ;
        }
        void setcount(void){
            count = 0;
        }
};
customer A ;
// To find the index of a customer 
int customer::cust_index(int acno){
    int oll = 0;

    for(int i = 0; i <= count ; i++){
        int l = acc_no[i] ;
        if (acno == l){
            oll = 1 ;
            return i ;
        }
    }
    if (oll == 0){cout << acno << " does not exist\n" ;
    return -1 ;}
        
}

//To add an account
void customer::addacc(){
    cout << "Enter your details below :\n\n"; 
    cout << "Enter your name :" ;
    cin >> cust_name[count];
    cout << "Enter the account number : ";
    cin >> acc_no[count];
    cout << "Enter the account type : " ;
    cin >> acc_type[count] ;
    cout << "Enter the account balance : " ;
    cin >> balance[count] ;
    count++ ;
}

//To get the account statement
void customer::acc_state(int index){
    cout << "NAME      :" << cust_name[index] << "\n" ;
    cout << "AC NUMBER :" << acc_no[index] << "\n";
    cout << "AC TYPE   :" << acc_type[index] << "\n";
    cout << "BALANCE   :" << balance[index] << "\n";
}
//withdraw
void customer::withdraw(float amount , int index){
    float b = balance[index];
    if (b > 500){
        b = b - amount ;
        balance[index] = b ;
    }
    else if (amount > b ){
        cout << "Insufficient Balance , withdrawal not possible"<<endl;}
    else {cout << "Balance less than 500 , withdrawal not possible\n";}
}

void menu(){
    
    cout << "   \nWELCOME  " << "\n" ;
    cout << "\n\n" ;
    cout << "1 : TO ADD YOUR ACCOUNT\n";
    cout << "2 : TO GET AN ACCOUNT STATEMENT\n";
    cout << "3 : DEPOSIT CASH\n";
    cout << "4 : WITHDRAW CASH\n";
    cout << "5 : BALANCE ENQUIRY\n\n";
    cout << "___________________________________________________________________\n";
    cout << "PLEASE SELECT AN OPTION : " ;
    
    int ch;
    cin >> ch ;
    cout << "\n\n" ;

    if (ch == 1){A.addacc();}
    else if (2 <= ch && 5>=ch){
        int acn ;
        cout << "Enter your account number : " ;
        cin >> acn ;
        int x = A.cust_index(acn);
        if (x==-1){cout << " " ;}
        else{
            if (ch == 2){A.acc_state(x);}
            else if (ch == 3){
                float amt ;
                cout << "Enter the amount to deposit : " ;
                cin >> amt;
                A.deposit(amt,x);
                A.balance_enq(x) ;
            }
            else if (ch == 4){
                float amt ;
                cout << "Enter the amount to withdraw : " ;
                cin >> amt;
                A.withdraw(amt,x);
                A.balance_enq(x) ;
            }
            else if (ch == 5){
                A.balance_enq(x);
            }
        }
    }
    else{cout << "Please enter a valid option!!!\n";}
}

int main()
{
    A.setcount();
    int lcontrol = 0 ;
    int lc = 0 ;
    while (lcontrol == 0 && lc < 30){
        menu();
        cout << "ENTER 0 TO CONTINUE : " ;
        cin >> lcontrol ;
        lc++ ;
    }
    cout << "\n\nThanks !!!!!\n\n";
    return 0 ;
}