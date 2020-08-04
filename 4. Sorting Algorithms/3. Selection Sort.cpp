#include <iostream>
#include <vector>
using namespace std;

vector<int> arr = {4,2,5,7,3,1,0,6,-1};

// Function for Selection Sort
void selectionSort() {
    int n = arr.size();
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Main Function
int main() {
    cout << "Array Before Sorting : " << endl;
    for(auto num : arr) {
        cout << num << "\t";
    }
    selectionSort();
    cout << endl << "Array After Sorting (Selection Sort) : " << endl;
    for(auto num : arr) {
        cout << num << "\t";
    }
}