/*Write a C++ program to design a class having static member function named
showcount() which has the property of displaying the number of objects created
of the class*/
#include<iostream>
using namespace std ;

class students{
    static int count ;
    string name ;
    public:
    students(){count++;}
    void getname(){
        cout << "ENTER NAME : ";
        cin >> name ; 
    }
    static void showcount(){
        cout << "The number of objects created are " << count << "\n";
    }
};
int students::count;

int main(){
    students A , B ;
    A.getname();
    B.getname();
    students::showcount();
    students C ;
    C.getname();
    students::showcount();
    return 0 ;

}
