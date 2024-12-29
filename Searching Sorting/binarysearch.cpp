#include<iostream>
using namespace std;

int BinarySearch(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int size, target;
    cout <<"Enter the size of the array: ";
    cin >> size;

    cout << "Enter " << size << " elements in sorted order: ";
    int arr[size];
    for(int i = 0; i < size; i ++)
    {
        cin >> arr[i];
    }

    cout << "Enter the element to search: ";
    cin >> target;

    int result = BinarySearch(arr, size, target);
    
    if(result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found!" << endl;
    }
    return 0;
}