#include <iostream>
using namespace std;

// Function for Linear Search
int linearSearch(int *arr, int size, int data) {
    int pos;
    for(pos = 0; pos < size; pos++) {
        if(arr[pos] == data) {
            return pos + 1;
        }
    }
    return -1;
}

// Main Function
int main() {

    int arr[] = {2,5,6,9,1,0,8,7};
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
            int pos = linearSearch(arr, 8, data);
            if(pos != -1) {
                cout << endl << "Element found is present at position " << pos << endl;
            } else {
                cout << endl << "Element not Found." << endl;
            }
            continue;
        }
        return 0;
    }

}