#include<iostream>
using namespace std;

int* insertElement(int arr[], int& size, int insertionIndex, int newItem) {
    if (insertionIndex < 0 || insertionIndex > size) {
        cout << "Invalid insertion index." << endl;
        exit(0);
    }

    int* newArr = new int[++size];
    for(int i = 0; i < size; i++) {

        if(i < insertionIndex)
            newArr[i] = arr[i];

        else if(i == insertionIndex)
            newArr[i] = newItem;

        else if(i > insertionIndex)
            newArr[i] = arr[i-1];
    }

    return newArr;
}

int* deleteElement(int arr[], int& size, int deletionIndex) {
    if (deletionIndex < 0 || deletionIndex >= size) {
        cout << "Invalid deletion index." << endl;
        exit(0);
    }

    int* newArr = new int[--size];

    for (int i = 0; i < size; i++) 
    {
        if (i < deletionIndex)
            newArr[i] = arr[i];
        else
            newArr[i] = arr[i + 1];
    }

    return newArr;
}

int main(int argc, char const *argv[])
{
    int size;
    cout << "Enter number of elements in the list: " << endl;
    cin >> size;

    int* arr = new int[size];
    cout << "Enter the elements: " << endl;
    for(int i = 0; i < size; i++)
        cin >> arr[i];

    cout << "\nChoose which operation to perform: \n1. Insertion \n2. Deletion \nEnter your choice: ";
    int option;
    cin >> option;

    int* resArr;

    switch(option){
        case 1 :
            int newItem;
            cout << "\nEnter item to insert: ";
            cin >> newItem;

            cout << "\nEnter 1 to insert at the start \nEnter 2 to insert in the end \nEnter 3 to insert in any other index \nYour choice: ";
            int choice;
            cin >> choice;

            switch (choice)
            {
                case 1:
                    resArr = insertElement(arr, size, 0, newItem);
                    break;
                
                case 2:
                    resArr = insertElement(arr, size, size, newItem);
                    break;

                case 3:
                    cout << "\nEnter index: ";
                    int idx;
                    cin >> idx;
                    resArr = insertElement(arr, size, idx, newItem);
                    break;
                
                default:
                    cout << "Invalid choice!";
                    break;
            }
            break;

        case 2 :
            cout << "\nEnter 1 to delete at the start \nEnter 2 to delete in the end \nEnter 3 to delete any other index \nYour choice: ";
            cin >> choice;

            switch (choice)
            {
                case 1:
                    resArr = deleteElement(arr, size, 0);
                    break;
                
                case 2:
                    resArr = deleteElement(arr, size, size-1);
                    break;

                case 3:
                    cout << "\nEnter index: ";
                    int idx;
                    cin >> idx;
                    resArr = deleteElement(arr, size, idx);
                    break;
                
                default:
                    cout << "Invalid choice!";
                    break;
            }
            break;

            default:
                cout << "Invalid choice!";
    }

    cout << "\nResultant array:" << endl;
    for (int i = 0; i < size; i++)
        cout << resArr[i] << " ";

    return 0;
}