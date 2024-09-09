
//will select a value namely pivot and will place it as such
//values smaller then pivot comes in left and larger will comes in right of pivot
//it is called partition
//we will compare h and l to the pivot point
//l(low) will be first element and high will be last
//initially l will be pivot
//increment i till you fidn element greater than pivot
//decrement j until you find elemnt smaller or equal to pivot
//when you find both just swap them


#include<iostream>
using namespace std;

int partition(int arr[], int s, int e){
    int pivot = arr[s];
    int cnt=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            cnt++
        }
    }
}
void quickSort(int arr[],int s,int e){
    //base case
    if(s>=r)
    return;

//partioning krenge
int p = partition(arr,s,e);

//left part sort kro
quickSort(arr,s,p-1);

//right wala pert sort
quickSort(arr,p+1,e)

}

int main(){
    int arr[5] = {2,4,1,6,9};
    int n=5;
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}