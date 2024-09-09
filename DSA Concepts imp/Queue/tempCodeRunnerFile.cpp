// sab kuch normal queue ke jaise hi hoga just end mein rear/front
// starting mein lg jaaega

//(front==0 && rear == size-1) queue s full

// rear ==(front-1)%(size-1) circular hai toh rear front ke aage bhi ho skta hai
// which also means queue is full

// if(rear == size-1) && front !=0 rear last mein h aur front
// first mein nhi h means rear can bi at first coz circular

#include <iostream>
using namespace std;

class Cqueue
{
public:
    int *arr;
    int front;
    int rear;
    int size;

    Cqueue(int size)
    {
        arr = new int[size];
        this->size = size;
        front = rear = -1;
    }

    void push(int val)
    {

        // overflow
        if (front = 0 &&rear = size - 1)
        {
            cout << "overflow" << endl;
        }
        // empty case -> single element
        else if (front == -1 &&rear = -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        // circular nature
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = val;
        }
        // normal flow
        else
        {
            rear++;
            arr[rear] = val;
        }
    }

    void pop()
    {
        // underflow
        if (front == -1 && rear == -1)
        {
            cout << "underflow";
        }
        // single element ko hatao aage bhado
        else if (front == rear)
        {
            arr[front] = -1;
            front++;
        }
        // circular nature
        else if (front == size - 1)
        {
            arr[front] = -1;
            front = 0;
        }
        // normal flow
        else
        {
            arr[front] = -1;
            front++;
        }
    }

    void print()
    {
        cout << "printing queue";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Cqueue q(5);
    q.print();
    return 0;
}