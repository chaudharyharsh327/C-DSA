//    /////////SCOPE RESOLUTION OPERATOR(::)
//    // //int a   global variable
//    // {
//    //    int a  local variable
//    // }

// } 
//    //if we want to use global variable inside the braces of local var
//    //we have to use :: for it

//EXAMPLE

#include<iostream>
using namespace std;
int a=10;
int main(){
    int a=5;
    cout<<"local variable: "<<a<<endl;
    cout<<"global variable: "<<::a<<endl;


}