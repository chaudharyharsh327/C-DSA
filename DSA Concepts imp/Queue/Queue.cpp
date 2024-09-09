#include<iostream>
#include<queue>
using namespace std;
int main(){
    //create queue
    queue<int>q;
    q.push(10);
    cout<<"queue front is: "<<q.front()<<endl;
    q.push(11);
    q.push(12);
    cout<<"size of queue: "<<q.size()<<endl;
    q.pop();
    cout<<"size of queue after pop: "<<q.size()<<endl;
    return 0;

}