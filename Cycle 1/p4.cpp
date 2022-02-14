/*Write a C++ progtram to perform operations such as compare, concatenate and
length on String objects*/
#include <iostream>
#include <string>
using namespace std ;

const int m = 100;
class strings{
    string str ;
    public:
        strings(string x){
            str = x ;
        }
        strings(){};
        bool compare(strings A, strings B);
        friend strings concatnate(strings A , strings B);
        int length();
        void display(){cout << str << endl;}

};

int strings::length(){
    int c = 0 ;
    for(int i = 0; i < m ; i++){
        char k = str[i] ;
        if (k != '\0'){
            c++ ;
        }
    }
    return c ;
}

bool strings::compare(strings A ,strings B){
    if (A.str == B.str){
        return 1 ;
    }
    else {return 0 ;}
}

strings concatnate(strings A , strings B){
    strings f ;
    int lA = A.length();
    int lB = B.length();
    int t = lA + lB ;
    string As = A.str ; // store a values 
    string Bs = B.str; 
    for(int i = lA + 1; i < t ; i++ ){
        for(int j = 0 ; j < lB; j++ ){
            As[i] = Bs[j];
        }
    }
    f.str = As ;
    return f ;
    
}



int main(){
    strings C ;
    strings A = strings("Hello");
    strings B = strings("World");
    cout << A.compare(A,B) << "\n";
    C = concatnate(A,B);
    A.display();
    B.display();
    C.display();
    
    return 0;

}