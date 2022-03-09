/*Write a C++ program to design a class having static member function named
showcount() which has the property of displaying the number of objects created
of the class*/
#include<iostream>
using namespace std ;

class students{
    static int count ;
    string name ;
    public:
    void getname(){
        cout << "ENTER NAME : ";
        cin >> name ; 
        count++;
    }
    static void showcount(){
        cout << "The number of objects created are " << count << "\n";
    }
};
int students::count = 0;

int main()
{
    cout << "MENU : \n";
    cout << "1 Add an object\n";
    cout << "2 Number of objects created\n";
    cout << "3 Exit\n";
    students slist[10];
    int choice = 0 ;
    int i = 0 ;
    while(choice != 3)
    {
        cout << "Enter a choice :";
        cin >> choice ;
        if (choice == 1)
        {
            slist[i].getname();
            i++;
        }
        else if (choice == 2)
        {
            slist[i].showcount();
        }
        else if (choice == 3)
        {
            choice = 3 ;
        }
        else
        {
            cout << "Invalid option\n";
        }
    }
}

