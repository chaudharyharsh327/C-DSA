
// ///MIN HEAP USING PRIORITY QUEUE
// #include<iostream>
// #include<queue>
// using namespace std;

// int main(){
//     //min heap ceration
//     priority_queue<int,vector<int>,greater<int>>pq;
//     //inseriton
//     pq.push(100);
//     pq.push(90);
//     pq.push(70);

//     cout<<"Top element of heap:"<<pq.top()<<endl;
//     pq.top();

//     return 0;

// }



//SMALLEST AND GREATEST ELEMENT
// #include <iostream>
// #include <queue>
// using namespace std;

// int getKthSmallestElement(int arr[], int n, int k)
// {
//     priority_queue<int> pq;
//     // first k elment ko process kro
//     for (int i = 0; i < k; i++ )
//     {
//         int element = arr[i];
//         pq.push(element);
//     }
//     // remaining element ko tabhi insert krenge jab vo root se chote ho
//     for (int i = k; i < n; i++)
//     {
//         int element = arr[i];
//         if (element < pq.top())
//         {
//             pq.pop();
//             pq.push(element);
//         }
//     }
//     int ans = pq.top();
//     return ans;
// }


// int getKthGreatestElement(int arr[],int n, int k){
//     priority_queue<int,vector<int>, greater<int>>pq;
//      for (int i = 0; i < k; i++ )
//     {
//         int element = arr[i];
//         pq.push(element);
//     }
//     // remaining element ko tabhi insert krenge jab vo root se chote ho
//     for (int i = k; i < n; i++)
//     {
//         int element = arr[i];
//         if (element > pq.top())
//         {
//             pq.pop();
//             pq.push(element);
//         }
//     }
//     int ans = pq.top();
//     return ans;
// }

// int main(){
//     int arr[] = {3,5,4,6,9,8,7};
//     int n = 7;
//     int k = 2;
//     cout<<"4th smallest number is: "<<getKthSmallestElement(arr,n,k)<<endl;
//     cout<<"4th greatest number is: "<<getKthGreatestElement(arr,n,k)<<endl;
//     return 0;
// }



#include<iostream>
using namespace std;
class info{
    public:
    int maxVal;
    bool isHeap;
    Info(int a, bool b){
        this->maxVal = a;
        this->isHeap = b;
    }
};

Info checkMaxHeap(Node* root){
    if(root == NULL){
        Info temp;
        temp.maxVal = INT_MIN;
        temp.isHeap = true;
        return temp;
    }

    if(root->left == NULL && root->right == NULL){
        Info temp;
        temp.maxVal = root->data;
        temp.isHeap = true;
        return temp;
    }
    Info leftAns = checkMaxHeap(root->left);
    Info leftAns = checkMaxHeap(root->left);
    //1 case mughe solve krna h
    if(root->data > leftAns.maxval && root->data >rightAns.maxVal &&
    leftAns.isHeap && rightAns.isHeap){
        Info ans;
        ans.maxVal = root->data;
        ans.isHeap = true;
        return ans;
    }
    else{
        Info ans;
        ans.maxVal = max(root->data,max(leftAns.maxVal,rightAns.maaxVal));
        ans.isHeap = false;
        return ans;
    }

}

int main(){

}