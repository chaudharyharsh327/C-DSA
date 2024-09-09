#include <iostream>
using namespace std;

class Heap
{
public:
    int *arr;
    int size;
    int capacity;

    Heap(int capacity)
    {
        this->arr = new int[capacity];
        this->capacity = capacity;
        // size = current number of elements in heap
        this->size = 0;
    }
    void insert(int val) //tc=logn
    {
        if (size == capacity)
        {
            cout << "Heap Overflow" << endl;
            return;
        }
        // size bhada dia aur arr ke is index pe value insert krni h
        size++;
        int index = size;
        arr[index] = val;

        // take the value of correct position
        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                //swap krdo aur index ko update krdo
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }
    void printHeap()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }
    int remove()//tc=logn
    {
        // root node delte krni hai to last element aur root node ko swap krdo
        int answer = arr[1];
        // replacement
        arr[1] = arr[size];
        // root node delete krdi toh size--
        size--;

        // hippification
        int index = 1;
        while (index <= size)
        {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;

            // find out krna h sabse bada kon
            int largestKaIndex = index;
            // check left child
            if (leftIndex <= size && arr[largestKaIndex] < arr[leftIndex])
            {
                largestKaIndex = leftIndex;
            }
            if (rightIndex <= size && arr[largestKaIndex] < arr[rightIndex])
            {
                largestKaIndex = rightIndex;
            }
            // no change
            if (index == largestKaIndex)
            {
                break;
            }
            else
            {
                swap(arr[index], arr[largestKaIndex]);
                index = largestKaIndex;
            }
        }
        return answer;
    }
};

//****IMP
void heapify(int *arr, int n, int index)
{
    int largestkaIndex = index;
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;

    // teeeno mein se max lao
    if (leftIndex <= n && arr[leftIndex] > arr[largestkaIndex])
    {
        largestkaIndex = leftIndex;
    }
    if (rightIndex <= n && arr[rightIndex] > arr[largestkaIndex])
    {
        largestkaIndex = rightIndex;
    } 
    // after these 2 conditions largestKaIndex will be poinitn toward largest element among 3
    if (index != largestkaIndex)
    {
        swap(arr[index], arr[largestkaIndex]);
        // ab recusrion sambhal lega
        index = largestkaIndex;
        heapify(arr ,n, index);
    }
}

// leaf node = valid heap wale formula se
//n/2+ se leke n tk saare leaf nodes hote hai which are already heaps
//so 1 sen/2 tak chalane ki zaroorat h code ko 
void buildHeap(int arr[], int n)
{
    for (int index = n / 2; index > 0; index--)
    {
        heapify(arr, n, index);
    }
}

void heapsort(int arr[], int n) //tc=nlogn
{
    while (n != 1)
    {
        // 1st element ko last ke saath swap krdia
        //kuki heap ka first ya root element sabse bada hi hoga
        swap(arr[1], arr[n]);
        // we will let ki humne jo element swap krke last mein bhjea hai
        // use delete krdia islea n--
        n--;
        heapify(arr, n, 1);
    }
}

int main()
{
    //oth index pe -1 kuki actual element 1st index se chaalu hone chhaiye
    int arr[] = {-1,5, 10, 15, 20, 25, 12};
    int n = 6;
    buildHeap(arr, 6);

    cout << "printing heap: " << endl;
    for (int i = 1; i <= 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;


    heapsort(arr, n);
    cout << "printing heap: " << endl;
    for (int i = 1; i <= 6; i++)
    {
        cout << arr[i] << " ";
    }

    // Heap h(20);
    // // insertion
    // h.insert(10);
    // h.insert(20);
    // h.insert(5);
    // h.insert(11);
    // h.insert(6);

    // cout << "Printint the content of heap: " << endl;
    // h.printHeap();
    // int ans = h.remove();
    // cout << endl
    //      << "Answer:" << ans << endl;
    // h.printHeap();

    return 0;
};

