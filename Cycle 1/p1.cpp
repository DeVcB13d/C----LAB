/*program to calculate the grades of a list of students with attributes
(Name, Roll_no, Marks of 3 subjects) using class with member functions
input(), calcGrade(), display().*/
#include<iostream>
using namespace std ;

class student{
    string Name ;
    static int Sno;
    int Roll_no ;
    float s1 ;
    float s2 ;
    float s3 ;
    public:
        void input(void);
        char calcGrade(void);
        void display(void);
};
int student::Sno ;
student slist[10];
void student::input(void){
    cout << "Enter the name : " << endl ;
    cin >> Name ;
    cout << "Enter the Roll No : "<< endl ;
    cin >> Roll_no ;
    cout << "Enter marks in subject 1 "<< endl;
    cin >> s1 ;
    cout << "Enter marks in subject 2 " << endl;
    cin >> s2 ;
    cout << "Enter marks in subject 3 " << endl ;
    cin >> s3 ;
    cout  << "\n\n\n"; 
}

char student::calcGrade(void){
    char grade;
    float avg = (s1 + s2 + s3) / 3;
    if (avg <= 100 && avg > 80 ){
        grade = 'A';
    }
    else if(avg <= 80 && avg > 60){
        grade = 'B';
    }
    else if(avg <= 60 && avg > 40){
        grade = 'C';
    }
    else if(avg <= 40 && avg > 20){
        grade = 'D';
    }
    else if(avg <= 20){
        grade = 'E';
    }
    else{
        grade = 'F';
    };
    return grade ;
}

void student::display(void){
    char grades = calcGrade();
    cout << "ROLL NO :" << Roll_no <<endl ;
    cout << "NAME    :" << Name <<endl;
    cout << "GRADE   :" << grades << endl ;
    cout << "\n\n\n" ;
}

int main()
{
    student A , B , C ; 
    A.input();
    B.input();
    C.input();

    cout << "Grades and details :" << "\n\n" ;
    A.display();
    B.display();
    C.display();
    return 0 ;
}