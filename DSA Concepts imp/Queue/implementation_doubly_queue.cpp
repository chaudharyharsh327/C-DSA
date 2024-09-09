#include<iostream>
using namespace std;

class Deque{
    public:
    int *arr;
    int size;
    int rear;
    int front;

    Deque(int size){
        arr= new int[size];
        this->size = size;
        front =-1;
        rear = -1;
    }

    
    void pushBack(int val){

        //overflow
        if(rear = size-1){
            cout<<"overflow"<<endl;
        }
         //empty
         else if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[rear] = val;
         }

         //normal flow rear ko aage laate h fir element insert
         else{
            rear++;
            arr[rear] = val;
         }

    }

    void pushFront(int val){

        //overflow
        if(front ==0){
            cout<<"overflow"<<endl;
        }

        //empty or single elment
        else if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[front] = val;
        }
        //normal flow front ko peeche laate hai fir element insert
        else{
            front--;
            arr[front] = val;
        }
        
    }

    void popFront(int val){
        
        // underflow
        if (front == -1 && rear == -1)
        {
            cout << "underflow";
        }
        // single element ko hatao aage bhado
        else if (front == rear)
        {
            //single element remove krne ke baad
            //rear aur front wapas apni positions pe
            arr[front] = -1;
            front = -1;;
            rear = -1;;
        }
        // normal flow
        else
        {
            arr[front] = -1;
            front++;
        }

    }

    void popBack(int val){

        //underflow
        if(front == -1 && rear == -1){
            cout<<"Underflow"<<endl;
        }

        //single element
        else if(front == rear){
            arr[rear] = -1;
            front = -1;
            rear - -1;
        }

        //normal flow
        else{
            arr[rear] = -1;
            rear--;
        }

    }


    void print()
    {
        cout<<"front: "<<front<<" rear: "<<rear<<endl;
        cout << "Printing Queue: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main(){
      Deque dq(5);

    dq.pushBack(10);
    dq.pushFront(20);
    dq.pushFront(30);
    dq.print();

    return 0;
    

    
}


