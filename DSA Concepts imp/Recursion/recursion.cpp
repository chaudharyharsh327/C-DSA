//recusive funtion-->two things
//base case which returns something btata hai ki rukna kab hai
//and recursive function itself


//FACTORIAL OF NUMBER USING RECURSION 
// #include<iostream>
// using namespace std;

// int factorial(int n){
//     //base case
//     if(n==0)
//         return 1;

//     return n*factorial(n-1);
    
// }
// int main(){
//     int n;
//     cin>>n;
//     int ans = factorial(n);
//     cout<<ans<<endl;
//     return 0;
// }


//FIBONACCI SERIES

// #include<iostream>
// using namespace std;

// int fibo(int n){
//     //base case
//     if(n==0)
//         return 1;

//     return n*factorial(n-1);
    
// }
// int main(){
//     int n;
//     cin>>n;
//     int ans = fibo(n);
//     cout<<ans<<endl;
//     return 0;
// }


//////////////////////////////////////////////////////
//CHECK IF ARRAY IS SORTED USING RECURSION
// #include<iostream>
// using namespace std;
// bool sort(int arr[],int n){
//     //base case
//     if(n==0||n==1){
//         return true;
//     }
//     if(arr[0]>arr[1])
//     return false;
//     else{
//         bool remainingPart = sort(arr+1,n-1);
//         return remainingPart;
//     }

// }
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     if (sort(arr, n)) {
//         cout << "The array is sorted.\n";
//     } else {
//         cout << "The array is not sorted.\n";
//     }

//     return 0;
// }

////////////////////////////////////////
//SUM IF ARRAY USING RECURSION
// #include <iostream>
// using namespace std;

// int sum(int arr[], int n) {
//     if (n == 0) {
//         return 0;
//     }
//     if(n==1){
//         return arr[0];
//     }
//     return arr[0] + sum(arr+1, n - 1);
// }

// int main() {
//     int n;
//     cout << "Enter the number of elements in the array: ";
//     cin >> n;
    
//     int arr[n];
//     cout << "Enter the elements of the array: ";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
    
//     int totalSum = sum(arr, n);
//     cout << "The sum of elements in the array is: " << totalSum << endl;

//     return 0;
// }

///////////////////////////////////////////
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}