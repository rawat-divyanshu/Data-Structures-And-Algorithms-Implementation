#include <iostream>
#include <algorithm>
using namespace std;

// Function for Binary Search
int binarySearch(int *arr, int lb, int ub, int data) {
    int mid = lb + (ub - lb)/2;

    if(ub < lb) {
        return -1;
    }

    if(arr[mid] == data) {
        return mid;
    } else if(data < arr[mid]) {
        return binarySearch(arr, lb, mid - 1, data);
    } else {
        return binarySearch(arr, mid + 1, ub, data);
    }

}

// Main Function
int main() {
    int arr[] = {2,5,6,9,1,0,8,7};
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    sort(arr, arr+n);

    int choice;
    while(true) {
        cout << endl << "Select your Choice :" << endl;
        cout << "1. Search and Element." << endl;
        cout << "2. Exit" << endl;
        cout << endl << "Enter your choice : ";
        cin >> choice;

        if(choice == 1) {
            int data;
            cout << "Enter element to Search : ";
            cin >> data;
            int pos = binarySearch(arr, 0, 8, data);
            if(pos != -1) {
                cout << endl << "Element Found" << endl;
            } else {
                cout << endl << "Element not Found." << endl;
            }
            continue;
        }
        return 0;
    }


}