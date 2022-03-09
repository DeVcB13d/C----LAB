/*Write a C++ progtram to perform operations such as compare,
concatenate and length on String objects*/
#include <iostream>
#include <cstring>
using namespace std ;

int m =100;

class String{
    int l;
    char *str ;
    public:
        String(const char *x);
        String(){}
        friend void isequal(String A, String B);
        friend String concatnate(String A , String B);
        friend int length(String A){return A.l;}
        void display(){cout << str << endl;}
        friend int len(const char* x);
};

int len(const char*x)
{
    int c = 0;
    int l = 0;
    int i = 0;
    while (c<=0){
        if (x[i] != '\0'){
            l++ ;
            i++ ;
        }
        else if (x[i] == '\0'){
            c++;
        }
    }
    return l ;
}

String concatnate(String x,String y){
    String  z ;
    z.l = x.l + y.l ;
    z.str = new char[z.l + 1];
    for(int i = 0 ; i < x.l ; i ++){
        z.str[i] = x.str[i];
    }
    int k = 0 ;
    for(int j = x.l ; j < z.l ; j++){
        z.str[j] = y.str[k];
        k++;
    }
    return z ;
}

void isequal(String A ,String B){
    if (A.l == B.l){
        int s = 0 ;
        for(int i = 0 ; i < A.l ; i++ ){
            if (A.str[i] == B.str[i]){
                s++;
            }
        }
        if (s == A.l){cout<<"\nsame\n";}
        else{cout << "\nDifferent\n";}
    }
    else{cout<<"\ndifferent\n" ;}
    
}



String::String(const char* y)
{
    l = len(y);
    str = new char[l+1];
    for(int i = 0 ; i < l ; i++){
        str[i] = y[i];
    }
}
//get user input
int main()
{
    String A("Welcome to ") ;
    String B("New ");
    String G("York");
    String C = concatnate(A,B) ;
    C = concatnate(C,G) ;
    String D = ("xyz");
    String E = ("New ") ;
    cout << "A = ";
    A.display();
    cout << "B = ";
    B.display();
    cout << "C = ";
    C.display();
    cout << "G = ";
    G.display();
    cout << "Are they equal ?\n";
    cout << "B and E ";
    isequal(B,E);
    cout << "\nD and E ";
    isequal(D,E);

    return 0 ;
}
