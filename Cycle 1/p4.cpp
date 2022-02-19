/*Write a C++ progtram to perform operations such as compare,
concatenate and length on String objects*/
#include <iostream>
#include <cstring>
using namespace std ;

int m =100;
int length(char *x){
    int c = 0 ;
    for(int i = 0; i < m ; i++){
        char k = x[i] ;
        if (k != '\0'){
            c++ ;
        }
    }
    return c ;
}
class String{
    int len;
    char *str ;

    public:
        String(char *x);
        String(){
            str = new char[1];
        };
        bool compare(String A, String B);
        friend String concatnate(String A , String B);
        friend int length(String A){return A.len;}
        void display(){cout << str << endl;}

};



bool String::compare(String A ,String B){
    if (A.str == B.str){
        return 1 ;
    }
    else {return 0 ;}
}

String concatnate(String A , String B){
    String f ;
    int lA = A.len;
    int lB = B.len;
    int t = lA + lB ;
    char *As = A.str; // store a values 
    char *Bs = B.str; 
    for(int i = lA + 1; i < t ; i++ ){
        for(int j = 0 ; j < lB; j++ ){
            As[i] = Bs[j];
        }
    }
    f.str = As ;
    return f ;
    
}

String::String(char *x){
    len = length(x);
    str = new char[len+1]; 
    strcpy(str,x);
}

int main()
{
    String A("dev ") ;
    String B("Cdede");
    String C = concatnate(A,B) ;
    cout << "A = ";
    A.display();
    cout << "B = ";
    B.display();
    cout << "C = ";
    C.display();
    return 0 ;
}