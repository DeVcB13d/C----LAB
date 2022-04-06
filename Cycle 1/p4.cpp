/*
Write a C++ progtram to perform operations such as compare,
concatenate and length on String objects
*/

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
        String(const String &s)
        {
            l = s.l;
            str = new char[l+1];
            strcpy(str,s.str);
        }
        void gs(){cin >> str;}
        friend void isequal(String A, String B);
        friend String concatnate(String A , String B);
        friend int length(String A){return A.l;}
        void display(){cout << str;}
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
        if (s== A.l){cout<<"\nsame\n";}
        else{cout << "\nDifferent\n";}
    }
    else{cout<<"\ndifferent\n" ;}
    
}

String::String(const char* y)
{
    l = len(y);
    str = new char[l+1];
    strcpy(str,y);
    for(int i = 0 ; i < l ; i++){
        str[i] = y[i];
    }

}

int main()
{
    String *Slist;
    Slist = new String[m];
    int i = 0;
    //Menu
    cout << "1. Add String to the list\n";
    cout << "2. Concatnate 2 Strings\n";
    cout << "3. Check if they are same\n";
    cout << "4. Show Strings in the list\n";
    cout << "5. Exit\n";
    int choice = 0;
    while (choice != 5)
    {
        cout << "\nChoose an option : ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter a text : " ;
            char* x = new char[m];
            cin >> x ;
            Slist[i] = String(x);
            i++;
        }
        else if(choice == 2)
        {
            int i1,i2;
            cout << "Enter 2 object indexes : ";
            cin >> i1 >> i2 ;
            String K ;
            K = concatnate(Slist[i1],Slist[i2]);
            Slist[i1].display();
            cout << " + ";
            Slist[i2].display();
            cout << " = ";
            K.display();
            cout << "\n";
        }
        else if (choice == 3)
        {
            int i1,i2;
            cout << "Enter 2 object indexes : ";
            cin >> i1 >> i2 ;
            isequal(Slist[i1],Slist[i2]);
        }
        else if (choice == 4)
        {
            for(int j = 0 ; j < i ; j++)
            {
                cout << j << " : ";
                Slist[j].display();
                cout << "\n";
            }
            cout << "\n";
        }
        else if (choice == 5)
        {
            cout << "Exit\n";
        }
        else cout << "Invalid option\n";
    }
}