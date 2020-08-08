#include <iostream>
using namespace std;

// Recursive Function to check Array is Sorted or not.
bool isArraySorted(int *arr, int n) {
    if(n <= 1) {
        return true;
    }
    if(arr[0] <= arr[1] && isArraySorted(arr + 1, n - 1)) {
        return true;
    }
    return false;
}

int main() {
    int arr1[] = {1,2,3,4,5,6,7,8};
    int arr2[] = {1,2,5,4,9,10,7,8};
    
    cout << "Array 1 is " << (isArraySorted(arr1,8) ? "in Sorted order" : "not in Sorted order") << endl;
    cout << "Array 2 is " << (isArraySorted(arr2,8) ? "Sorted order" : "not in Sorted order") << endl;

    return 0;
}