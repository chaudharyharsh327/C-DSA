#include<iostream>
#include<queue>
using namespace std;
int main(){
    //max heap 
    priority_queue<int>pq;

    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(50);

    cout<<"Top element of heap: "<<pq.top()<<endl;
    pq.pop();
     cout<<"Top element of heap after pop: "<<pq.top()<<endl;
     cout<<"size of max heap: "<<pq.size()<<endl;




     //MIN HEAP
     priority_queue<int, vector<int>,greater<int>> minheap;

    minheap.push(10);
    minheap.push(20);
    minheap.push(30);
    minheap.push(40);
    minheap.push(50);

    cout<<"Top element of min heap: "<<minheap.top()<<endl;
    minheap.pop();
     cout<<"Top element of min heap after pop: "<<minheap.top()<<endl;
     cout<<"size of min heap: "<<minheap.size();


     return 0;
}

