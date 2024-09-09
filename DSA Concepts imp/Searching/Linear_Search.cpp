

#include<iostream>
using namespace std;

int main(){
    int i, n, target;
    cin >> n;
    int arr[n];
    
    for(i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    cin >> target;
    
    bool found = false;
    for(i = 0; i < n; i++){
        if(target == arr[i]){
            found = true;
            break;
        }
    }
    
    if(found){
        cout << "Element found in the array.";
    } else {
        cout << "Element not found in the array.";
    }
    
    return 0;
}