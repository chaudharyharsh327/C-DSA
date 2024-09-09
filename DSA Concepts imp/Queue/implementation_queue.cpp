//rear == front can be single element or emepty

#include<iostream>
using namespace std;

class Queue{
    int* arr;
    int front;
    int rear;
    int size;

public:
    Queue(){
        size = 100001;
        arr = new int[size];
        front = 0;
        rear = 0;
    }
//pop front se push rear se
//agr khaali nhi h toh rear mein daalo aage bhadao like megazine
    void enqueue(int data){
        if(rear == size)
            cout<<"Queue is full"<<endl;
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue(){
        if(front == rear){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        //jaha element hai vaha -1 krdo front ko aage bhada do
        else{
            int ans = arr[front];
            arr[front] = -1;
            front++;
            //jab pop krdia toh vo dabba khaali hogya
            //fir front aur rear ko new loaction pe point
            //krane ke liye unhe 0 krdenge
            if(front == rear){
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int getFront(){
        if(front == rear){
            return -1;
        }
        else{
            return arr[front];
        }
    }

    bool isEmpty(){
        if(front == rear){
            return true;
        }
        else{
            return false;
        }
    }

    void printQueue(){
        if(front == rear){
            cout<<"Queue is empty"<<endl;
        }
        else{
            cout<<"Queue elements are: ";
            for(int i=front; i<rear; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.printQueue();
    int front = q.getFront();
    cout<<"front element is: "<<front<<endl;

    int empty = q.isEmpty();
    if(empty){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"not empty";
    }
     

    return 0;
}