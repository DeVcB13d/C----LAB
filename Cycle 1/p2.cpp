//Program 2 

//program to calculate the area of different shapes like 
//Rectangle,Square etc (at least 5 shapes) using 
//overloaded function area()

#include<iostream>
#include<cmath>
using namespace std ;

//Rectangle
float area(int l , int b){
    cout << "Area of rectangle\n";
    return l*b;
}

//square
float area(int a){
    cout << "Area of a square \n";
    return a*a;
}

//triangle 
float area(float a , float b , float c){
    cout << "Area of a triangle\n";
    float s = ( a + b + c ) / 2 ;
    int ar = sqrt(s*(s-a)*(s-b)*(s-c));
    return ar ;

}
//circle

float area (double r){
    cout << "Area of circle \n";
    return (3.14*r*r);
}

//CSA of cone 
float area(double r ,double l)
{
    cout << "CSA of cone \n";
    return 3.14*r*l ;
}


int main(){
    cout << "MENU\n";
    cout << "1. Rectangle\n";
    cout << "2. Square\n";
    cout << "3. Triangle\n";
    cout << "4. Circle\n";
    cout << "5. CSA of cone\n";
    cout << "6. To Exit\n";
    
    int lc = 0 ;
    while (lc == 0){
        int choice;
        cout << "Pick a shape to find area :";
        cin >> choice ;
        if (choice == 1){
            int L,B ;
            cout << "Enter Length and Breadth :";
            cin >> L >> B ;
            cout <<area(L,B) << "\n";
        }
        else if (choice == 2){
            int Sl;
            cout << "Enter side length : ";
            cin >> Sl ;
            cout<<area(Sl)<<"\n";
        }
        else if (choice == 3){
            float A,B,C ;
            cout << "Enter the 3 sides :";
            cin >> A >> B >> C ;
            cout<<area(A,B,C)<<"\n";
        }
        else if (choice == 4){
            double R;
            cout << "Enter the Radius : ";
            cin >> R;
            cout<<area(R)<<"\n";
        }
        else if (choice == 5){
            double R,L;
            cout << "Enter Radius and slanting length : ";
            cin >> R >> L;
            cout<<area(R,L)<<"\n";
        }
        else if (choice == 6){
            cout << "Thanks\n";
            lc = 1 ;
        }
        else{cout << "Invalid option";}
    }
    return 0 ;
}