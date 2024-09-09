 //POORI ARRAY KO 2 HISSE MEIN DIVIDE KRO UNHE AUR 2 HISSO MEIN KRO JAB TAK SINGLE SINGLE NA REH JAAYE
//FIR UN DONO KO SORT  AUR MERGE KRTE CHLE JAAO UPAR TAK 
//FASTEST SORTING METHOD

#include<iostream>
using namespace std;

void merge(int *arr, int s, int e){
    int mid = (s+e)/2;

//mid nikal lia upar uske baad mid se left and right mein 
//2 array create krliye
    int len1 = mid-s+1;
    int len2= e - mid;

    //CREATION OF NEW ARRAY
    int *first = new int[len1];
    int *second = new int[len2];

    //ab jo start se leke mid ki value hai means left of mid
    //use new array mein copy kro
    int mainArrayIndex = s;
    for(int i=0;i<len1;i++){
        //new array ke first index ke ander dalna hai arr[kth] element
        //jo ki start se shuru kia hua h
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++){
        second[i] = arr[mainArrayIndex++];
    }

    //merge 2 sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex =s;

    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
             arr[mainArrayIndex++] = second[index2++];
        }
    }

    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    
    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }

}

void mergeSort(int *arr, int s, int e){
    //base case
    if(s>=e){
        return;
    }

    int mid = (s+e)/2;
    //left part sort krna hai
    mergeSort(arr, s, mid);

    //left part sort krna hai
    mergeSort(arr, mid+1, e);

    //merge
    merge(arr, s, e);

}

int main(){
    int arr[5] = {2,5,1,6,9};
    int n=5;

    mergeSort(arr,0, n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
        cout<<endl;
    return 0;
}