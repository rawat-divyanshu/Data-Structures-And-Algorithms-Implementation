#include <iostream>
#include <vector>
using namespace std;

vector<int> arr = {2,4,5,7,3,1,0,6};

// Function for Bubble Sort
void bubbleSort() {
    int n = arr.size();

    for(int i = 0; i < n; i++) {
        for(int j = 1; j < n - i; j++) {
            if(arr[j] < arr[j-1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

// Main Funcntion
int main() {
    cout << "Array Before Sorting : " << endl;
    for(auto num : arr) {
        cout << num << "\t";
    }
    bubbleSort();
    cout << endl << "Array After Sorting (Bubble Sort) : " << endl;
    for(auto num : arr) {
        cout << num << "\t";
    }
}
