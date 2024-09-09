// #include<iostream>
// #include<stack>
// using namespace std;
// int main()
// {
//     stack<int> s;
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     s.push(40);

//     while(!s.empty())
//     {
//         cout<<s.top()<<" ";
//         s.pop();
//     }

// }

/////////////////////////////////////////////////
// CREATING STACK FROM SCRATCH SO WE DONT HAVE TO USE DEPENDABILITY
//  #include<iostream>
//  using namespace std;
//  class Stack{
//      public:

//     int*arr;
//     int top;
//     int size;

//     Stack(int size){
//         arr = new int[size];
//         this-> size = size;
//         top = -1; //top is top element of array if top is -1 then array is empty
//      }

//     void push(int data){
//         if(size - top >1){
//             top++;
//             arr[top] = data;
//         }
//         else{
//             cout<<"stack overflow"<<endl;
//         }

//     }

//     void pop(){
//         if(top==-1){
//             //means stack is empty
//             cout<<"Stack underflow, cannot delete element";
//         }
//         else{
//             top--;
//         }
//     }

//     int getTop(){
//         if(top==-1){
//             //means stack is empty
//             cout<<"Stack is empty";
//         }
//         else{
//             return arr[top];
//         }

//     }

//     //returns number of valid elements
//     int getSize(){
//         return top + 1;// as top is a index if a array have 3 elements than last element's index is 2 so 2+1=3

//     }

//     bool isEmpty(){
//         if(top == -1){
//             return true;
//         }
//         else {
//             return false;
//         }
//     }
// };
// int main()
// {
//     Stack s(10);

//     s.push(10);
//     s.push(20);
//     s.push(30);
//     s.push(40);
//     s.pop();

//     while(!s.isEmpty()){
//         cout<<s.getTop()<<" ";
//         s.pop();
//     }

// }

///////////////////////////////////////////////////////
// 2 STACKS IN AN ARRAY

//[1,2,3,4,5,6,7,8,9,0]
//---->           <----  two stacks
// top=-1           top=size

// #include <iostream>
// using namespace std;

// class Stack
// {
// public:
//     int *arr;
//     int size;
//     int top1;
//     int top2;

//     Stack(int size)
//     {
//         arr = new int[size];
//         this->size = size;
//         top1 = -1;
//         top2 = size;
//     }

//     void push1(int data)
//     {
//         if (top2 - top1 == 1)
//         {
//             cout << "overflow";
//         }
//         else
//         {
//             top1++;
//             arr[top1] = data;
//         }
//     }

//     void pop1()
//     {
//         if (top1 == -1)
//         {
//             cout << "stack underflow in s1";  
//         }
//         else
//         {
//             top1--;
//         }
//     }

//     void push2(int data)
//     {
//         if (top2 - top1 == 1)
//         {
//             cout << "overflow";
//         }
//         else
//         {
//             top2--;
//             arr[top2] = data;
//         }
//     }

//     void pop2()
//     {
//         if (top2 == size)
//         {
//             cout << "underflow in stack 2";
//         }
//         else
//         {
//             top2++;
//         }
//     }

//     void print()
//     {
//         cout << endl;
//         cout << "top1: " << top1 << endl;
//         cout << "top2: " << top2 << endl;
//         for (int i = 0; i < size; i++)
//         {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }
// };

// int main()
// {
//     Stack s(10);
//     s.push1(10);
//     s.print();
//     s.push1(20);
//     s.print();
//     s.push1(30);
//     s.print();
//     s.push1(40);
//     s.print();
//     s.push1(50);
//     s.print();

//     s.push2(100);
//     s.print();
//     s.push2(110);
//     s.print();
//     s.push2(120);
//     s.print();

//     return 0;
// }

////////////////////////////////////////////////////
// REVERSE OF STRING USING STACK

// #include <iostream>
// #include <stack>
// using namespace std;
// int main()
// {
//     string str = "harsh";
//     stack<char> s;

//     for (int i = 0; i < str.length(); i++)
//     {
//         s.push(str[i]);
//     }

//     while (!s.empty())
//     {
//         cout << s.top() << " ";
//         s.pop();
//     }
//     cout << endl;

//     return 0;
// }

////////////////////////////////////////////////////////
//FINDING MIDDLE USING STACK
//middle=size/2+1 

// #include<iostream>
// #include<stack>
// using namespace std;
// void printMiddle(stack <int> &s, int &totalSize){
//     //base case
//     if(s.size() == totalSize/2+1)
//     {
//         cout<<"Middle element is:"<<s.top()<<endl;
//         return;
//     }

//     int temp=s.top();
//     s.pop();

//     //recursive call
//     printMiddle(s, totalSize);

//     //backtrack
//     s.push(temp);

// }

// int main(){
//     stack<int> s;
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     s.push(40);
//     s.push(50);
//     s.push(60);
//     s.push(70);

//     int totalSize = s.size();
//     printMiddle(s,totalSize);
  
// }


//////////////////////////////////////////
//INSERT AT BOTTOM

#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &s, int target)
{
    if(s.empty()){
        s.push(target);
        return;
    }

    int topElement = s.top();
    s.pop();
    //rec cal
    solve(s, target);
    //bt
    s.push(topElement);
}
void insertAtBottom(stack<int> &s){
    if(s.empty()){
        cout<<"stack is empty, cant insert at bottom"<<endl;
        return;
    }
    int target = s.top();//while performing s.top stack should never be empty
    s.pop();
    solve(s, target);
}
int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    insertAtBottom(s);

    cout<<"prinitng"<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    return 0;
    
}