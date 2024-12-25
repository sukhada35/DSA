#include<iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertAt(int arr[], int &size, int pos, int value)
{
    for(int i = size; i > pos; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[pos] = value;
    size++;
}

int main()
{
    int arr[20];
    int size, choice, value, pos;
    cout << "Enter the number of elements: ";
    cin >> size;
    cout << "Enter the elements: ";
    for(int i = 0; i < size; i++)
    {
        cin>> arr[i];
    }
    cout << "Current elements: ";
    printArray(arr, size);
    
    while(true)
    {
        cout<<"Menu:\n";
        cout<<"1. Insert at first position\n";
        cout<<"2. Insert at last position\n";
        cout<<"3. Insert at specific position\n";
        cout<<"4. Delete from first position\n";
        cout<<"5. Delete from last position\n";
        cout<<"6. Delete from specific position\n";
        cout<<"7. Exit\n";
        cout<<"Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
            cout << "Enter value to insert";
            cin >> value;
            insertAt(arr, size, 0, value);
            break;
            case 2:
            cout << "Enter value to insert";
            cin >> value;
            insertAt(arr, size, size, value);
            break;
            case 3:
            cout << "Enter position to insert (0-based index): ";
            cin >> pos;
            cout << "Enter value to insert: ";
            cin >> value;
            if(pos >= 0 && pos <= size)
            {
                insertAt(arr, size, pos, value);
            }
            else
            {
                cout << "Invalid position!" << endl;
            }
            printArray(arr, size);
            break;
        }

    }
    return 0;
}