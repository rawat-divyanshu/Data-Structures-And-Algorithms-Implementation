#include <iostream>
using namespace std;

int smallestValueIndex(int *arr, int lb, int ub) {
    if(lb == ub) {
        return lb;
    }

    int smallestIndex = smallestValueIndex(arr, lb + 1, ub);

    return arr[smallestIndex] <= arr[lb] ? smallestIndex : lb;
}

// Sorting using Recursion
void sortArray(int *arr, int lb, int ub) {
    if(lb == ub) {
        return;
    }
    int smallestIndex = smallestValueIndex(arr, lb, ub);

    int temp = arr[smallestIndex];
    arr[smallestIndex] = arr[lb];
    arr[lb] = temp;

    sortArray(arr, lb + 1, ub);
}

int main() {
    int arr[] = {3,7,1,5,9,2,8,4,0};

    cout << "Array Before Sorting : " << endl;
    for(auto num : arr) {
        cout << num << "\t";
    }
    sortArray(arr,0,8);
    cout << endl << "Array After Sorting : " << endl;
    for(auto num : arr) {
        cout << num << "\t";
    }

    return 0;
}