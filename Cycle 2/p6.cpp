//Write a C++ program to design a student class representing student roll no. and
//a test class (derived class of student) representing the scores of the student in
//various subjects and sports class representing the score in sports. The sports and
//test class should be inherited by a result class having the functionality to add
//the scores and display the final result for a student. Demonstrate the concept of
//Virtual base class on Hybrid inheritance.
#include <iostream>
#include <cstring>
using namespace std;

class student 
{
    string Name;
    int Rno ;
    public:
        void get_student_details(int r,string n)
        {
            Rno = r;
            Name = n;
        }
        void show_student_details(void)
        {
            cout << "Name    : " << Name << endl ;
            cout << "Roll No : " << Rno  << endl ;
        }
};

class test : virtual public student 
{
    protected:
        float S1,S2,S3 ;
    public:
        void get_test_score(float a,float b,float c)
        {
            S1 = a ; S2 = b ; S3 = c ;
        }
        void show_test_score(void)
        {
            cout << "\nMArks in Subject 1 :" << S1 << endl;
            cout << "MArks in Subject 2 :" << S2 << endl;
            cout << "MArks in Subject 3 :" << S3 << endl;
        }
};

class sports : virtual public student
{
    protected:
        float E1,E2 ;
    public:
        void get_sport_score(float e1,float e2)
        {
            E1 = e1 ; E2 = e2 ; 
        }
        void show_sport_score(void)
        {
            cout << "\nMArks in Sport 1 :" << E1 << endl;
            cout << "MArks in Sport 2 :" << E2 << endl;
        }
};

class Result : public test , public sports
{
    public:
        void show_result(void)
        {
            get_test_score(100,90,98);
            get_student_details(13,"Dev");
            get_sport_score(90,90);
            float total = S1 + S2 + S3 + E1 + E2 ;
            float avg = total / 5 ;
            show_student_details();
            show_test_score();
            show_sport_score();
            cout << "\nTotal marks :" << total << "\n";
            cout << "\nAverage     :" << avg   << "\n";
        }
};

int main()
{
    Result A ;
    A.show_result();
    return 0 ;
}