//LINEAR SEARCH USING RECURSION 

#include <iostream>
using namespace std;

bool linearSearch(int arr[], int n,int k) {
    if (n == 0) {
        return 0;
    }
    if(arr[0]==k){
        return true;
    }
    return linearSearch(arr+1,n-1,k);
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k;
    cout<<"enter the value of key:";
    cin>>k;
    bool ans=linearSearch(arr,n,k);
    if(ans){
        cout<<"present"<<endl;
    }
    else{
        cout<<"absent"<<endl;
    }

    return 0;
}