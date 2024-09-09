//ADJACENT ELEMENT KO SWAP KRO JAB TAK SORT NA HO

#include <iostream>
using namespace std;
int main()
{
    int n, i;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int counter = 1;
    while (counter < n - 1)
    {
        for (i = 0; i < n - counter; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }
        counter++;
    }
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
        cout<<endl;
    }
}