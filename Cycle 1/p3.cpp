//program using classes to perform bank transaction for n customers
//(cust_name, acc_no, acc_type, balance).
//The program should be menu driven and it should have the following menus like adding new account, withdraw
//(keep a min balance of 500), deposit, balance enquiry and account statement
//(cust_name, acc_no, acc_type, balance)*/

#include<iostream>
#include<string>
using namespace std ;



class customer{
    int count;
    string cust_name;
    int acc_no;
    char acc_type ;
    float balance;
    public:
        int getAC(){return acc_no ;}
        int cust_index(int acno);
        void addacc(void) ;
        void acc_state() ;
        void withdraw(float amount);
        void deposit(float amount){
            balance = balance + amount ;
            cout << "Balance : " << balance<< endl ;
        }
        void balance_enq(){
            cout << cust_name << "\n";
            cout << "Balance : " << balance<< endl ;
        }
        void setcount(void){
            count = 0;
        }
};


//To add an account
void customer::addacc(){
    cout << "Enter your details below :\n\n"; 
    cout << "Enter your name :" ;
    cin >> cust_name;
    cout << "Enter the account number : ";
    cin >> acc_no;
    cout << "Enter the account type : " ;
    cin >> acc_type;
    cout << "Enter the account balance : " ;
    cin >> balance;
    count++ ;
}
//To get the account statement
void customer::acc_state(void){
    cout << "NAME      :" << cust_name << "\n" ;
    cout << "AC NUMBER :" << acc_no << "\n";
    cout << "AC TYPE   :" << acc_type<< "\n";
    cout << "BALANCE   :" << balance<< "\n";
}
//withdraw
void customer::withdraw(float amount){
    
    if (amount < (balance - 500)){
        balance -= amount ;
        cout << "Success!!!\ncurrent balance is"<< balance <<endl; 
    }
    else if (amount > balance ){
        cout << "Insufficient Balance "<<balance<<" withdrawal not possible"<<endl;}
    else 
        {cout << "Balance "<<balance<<" less than 500 , withdrawal not possible\n";}
}



int main()
{
    customer clist[30];
    int eno = 1 ; 
    //To help add customers
    int lcontrol = 0 ;
    int lc = 0 ;
    cout << "   \nWELCOME  " << "\n" ;
    cout << "\n\n" ;
    cout << "1 : TO ADD YOUR ACCOUNT\n";
    cout << "2 : TO GET AN ACCOUNT STATEMENT\n";
    cout << "3 : DEPOSIT CASH\n";
    cout << "4 : WITHDRAW CASH\n";
    cout << "5 : BALANCE ENQUIRY\n\n";
    cout << "6 : EXIT               ";
    cout << "\n";
    while (lcontrol == 0 && lc < 30){
        cout << "\nPLEASE SELECT AN OPTION : " ;
        int ch;
        cin >> ch ;
        cout << "\n\n" ;
        if (ch==1){
            clist[eno].addacc(); 
            aclist[eno] = clist[eno].getAC();
            eno++;
        }
        else if(ch>=2 && ch <= 5){//restructure
            int RefNo,C_index;
            cout << "Enter your Account number :" ;
            cin >> RefNo ;
			int ctrl = 0;
            for(int i=0;i<30;i++){
                if (clist.getAC()==RefNo){
                    C_index = i ;
					ctrl = 1 ;
                }
				if (ctrl == 0){cout << "Incorrect ID";
					}
            }
            if(ch == 2){
                clist[C_index].acc_state();
            }
            else if(ch==3){
                float amt ;
                cout << "Enter the amount to deposit: ";
                cin >> amt; 
                clist[C_index].deposit(amt);
            }
            else if(ch==4){
                float amt ;
                cout << "Enter the amount to withdraw: ";
                cin >> amt; 
                clist[C_index].withdraw(amt);
            }
            else if(ch == 5){
                clist[C_index].balance_enq();
            }
        }
        else if(ch == 6){lc = 31;}
        else{cout << "Invalid option\n";}
        lc++;
    }
    return 0 ;
}
