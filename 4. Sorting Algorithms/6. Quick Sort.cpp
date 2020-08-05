#include <iostream>

using namespace std;

// Partitioning Function for finding pivot element.
int partition(int *arr, int lb, int ub) {

    int pivot = arr[lb];

    int start = lb;
    int end = ub;

    int temp;

    while(start < end) {

        while(arr[start] <= pivot) {
            start++;
        }

        while(arr[end] > pivot) {
            end--;
        }

        if(start < end) {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }

    }

    temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;

    return end;
}

// Function for Quicksort
void quickSort(int *arr, int lb, int ub) {

    if(lb < ub) {

        int pivot = partition(arr, lb, ub);

        quickSort(arr, lb, pivot - 1);
        quickSort(arr, pivot + 1, ub);

    }    

}

// Main Function
int main() {

    int arr[] = {4,2,5,7,3,1,0,6,-1};

    cout << "Array Before Sorting : " << endl;
    for(auto num : arr) {
        cout << num << "\t";
    }
    quickSort(arr, 0, 8);
    cout << endl << "Array After Sorting (Quick Sort) : " << endl;
    for(auto num : arr) {
        cout << num << "\t";
    }
}