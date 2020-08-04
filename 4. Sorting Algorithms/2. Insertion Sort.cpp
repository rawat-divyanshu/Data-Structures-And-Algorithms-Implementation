#include <iostream>
#include <vector>
using namespace std;

vector<int> arr = {4,2,5,7,3,1,0,6,-1};

// Function for Insertion Sort
void insertionSort() {
    int n = arr.size();
    int i,j;

    for(i = 0; i < n; i++) {
      j = i - 1;
      int current = i;
      while(arr[current] < arr[j] && j >= 0) {
        int temp = arr[current];
        arr[current] = arr[j];
        arr[j] = temp;
        current = j;
        j--;
      }
    }
}

// Main Funcntion
int main() {
    cout << "Array Before Sorting : " << endl;
    for(auto num : arr) {
        cout << num << "\t";
    }
    insertionSort();
    cout << endl << "Array After Sorting (Insertion Sort) : " << endl;
    for(auto num : arr) {
        cout << num << "\t";
    }
}