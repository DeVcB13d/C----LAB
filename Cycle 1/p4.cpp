/*Write a C++ progtram to perform operations such as compare,
concatenate and length on String objects*/
#include <iostream>
#include <cstring>
using namespace std ;

int m =100;

class String{
    int len;
    char *str ;

    public:
        String(const char *x);
        String(){
            str = new char[1];
        };
        friend bool compare(String A, String B);
        friend String concatnate(String A , String B);
        friend int length(String A){return A.len;}
        void display(){cout << str << endl;}

};

int length(const char *x){
    int c = 0 ;
    for(int i = 0; i < m ; i++){
        char k = x[i] ;
        if (k != '\0'){
            c++ ;
        }
    }
    return c ;
}

bool compare(String A ,String B){
    if (A.str == B.str){
        return true ;
    }
    else {return false ;}
}

String concatnate(String A , String B){
    String f ;
    int lA = A.len;
    int lB = B.len;
    f.str = new char [lA + lB + 1];
    strcpy(f.str,A.str);
    strcat(f.str,B.str);
    return f ;
}

String::String(const char* x){
    len = length(x);
    str = new char[len+1]; 
    strcpy(str,x);
}

int main()
{
    String A("dev") ;
    String B("Cdede");
    String C = concatnate(A,B) ;
    String D = ("alpha");
    String E = ("dev") ;
    cout << "A = ";
    A.display();
    cout << "B = ";
    B.display();
    cout << "C = ";
    C.display();
    cout << "Are they equal ?\n";
    cout << "A and E " << compare(A,E)<<endl ;
    cout << "A and D " << compare(A,D)<<endl ;

    return 0 ;
}