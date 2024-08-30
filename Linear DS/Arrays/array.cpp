//In this code we are going to implement a menu-driven program to insert and delete elements from an array. The program will provide the following options to the user:
#include <iostream>
using namespace std;
// Function to print all elements of the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// Function to insert a value at a specific position in the array
void insertAt(int arr[], int &size, int position, int value) 
{
    // Shift elements to the right to make space for the new value
    for (int i = size; i > position; i--) 
    {
        arr[i] = arr[i-1];
    }
    // Insert the new value
    arr[position] = value;
    // Increase the size of the array
    size++;
}
// Function to delete an element from a specific position in the array
void deleteAt(int arr[], int &size, int position) 
{
    // Shift elements to the left to fill the gap created by the deleted value
    for (int i = position; i < size - 1; i++) 
    {
        arr[i] = arr[i+1];
    }
    // Decrease the size of the array
    size--;
}
int main() 
{
    int arr[100]; // Assuming a maximum size of 100 for simplicity
    int size, choice, value, position;
    // Read the number of grades from the user
    cout << "Enter the number of grades: ";
    cin >> size;
    // Read the grades from the user
    cout << "Enter the grades: ";
    for (int i = 0; i < size; i++) 
    {
        cin >> arr[i];
    }
    // Print the current grades
    cout << "Current grades: ";
    printArray(arr, size);
    // Menu-driven interface for user interaction
    while (true) 
    {
        cout << "Menu:\n";
        cout << "1. Insert at first position\n";
        cout << "2. Insert at last position\n";
        cout << "3. Insert at specific position\n";
        cout << "4. Delete from first position\n";
        cout << "5. Delete from last position\n";
        cout << "6. Delete from specific position\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) 
        {
            case 1:
                // Insert a value at the first position
                cout << "Enter value to insert at first position: ";
                cin >> value;
                insertAt(arr, size, 0, value);
                break;
            case 2:
                // Insert a value at the last position
                cout << "Enter value to insert at last position: ";
                cin >> value;
                insertAt(arr, size, size, value);
                break;
            case 3:
                // Insert a value at a specific position
                cout << "Enter position to insert (0-based index): ";
                cin >> position;
                cout << "Enter value to insert: ";
                cin >> value;
                if (position >= 0 && position <= size) 
                {
                    insertAt(arr, size, position, value);
                } 
                else 
                {
                    cout << "Invalid position!" << endl;
                }
                break;
            case 4:
                // Delete a value from the first position
                if (size > 0) 
                {
                    deleteAt(arr, size, 0);
                } 
                else 
                {
                    cout << "Array is empty!" << endl;
                }
                break;
            case 5:
                // Delete a value from the last position
                if (size > 0) 
                {
                    deleteAt(arr, size, size - 1);
                } 
                else 
                {
                    cout << "Array is empty!" << endl;
                }
                break;
            case 6:
                // Delete a value from a specific position
                cout << "Enter position to delete (0-based index): ";
                cin >> position;
                if (position >= 0 && position < size) 
                {
                    deleteAt(arr, size, position);
                } 
                else 
                {
                    cout << "Invalid position!" << endl;
                }
                break;
            case 7:
                // Exit the program
                return 0;
            default:
                // Handle invalid menu choices
                cout << "Invalid choice!" << endl;
        }

        // Print the current grades after each operation
        cout << "Current grades: ";
        printArray(arr, size);
    }
    return 0;
}
