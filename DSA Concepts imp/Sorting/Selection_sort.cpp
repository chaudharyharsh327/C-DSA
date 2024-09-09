//MINM ELEMENT KO SWAP KRKE beginning MEIN LE AAO JAB TAK SORT NA HO


// #include <iostream>
// using namespace std;
// int main()
// {
//     int n, i,j;
//     cin >> n;
//     int arr[n];
//     for (i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

    

//     for(int i=0;i<n-1;i++){
//         for(j=i+1;j<n;j++){
//             if(arr[j]<arr[i]){
//                 swap(arr[i],arr[j]);
//                 //int temp = arr[j];
//                 //arr[j] = arr[i];
//                 // arr[i] = temp;
//             }
//         }

//     }


//     for (i = 0; i < n; i++)
//     {
//         cout<<arr[i]<<" ";   
//     }
//     cout<<endl;
//     for (i = 0; i < n; i++)
//     {
//         if(i%2==0){
//             cout<<arr[i]<<" ";
//         }
        
//     }
// }


#include <iostream>
using namespace std;
int main()
{
    int n, i,j;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }


    for (i = 0; i < n; i++)
    {
        if(arr[i]%2==0)
        cout<<arr[i]<<" ";   
    }
    
}