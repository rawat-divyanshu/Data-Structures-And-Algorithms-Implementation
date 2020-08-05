#include <iostream>
using namespace std;

// Function for merging two sorted arrays.
void merge(int *arr, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int lArr[n1];
    int rArr[n2];

    for(int i = 0; i < n1; i++) {
        lArr[i] = arr[start + i];
    }
    for(int i = 0; i < n2; i++) {
        rArr[i] = arr[mid + i + 1];
    }

    int i = 0;
    int j = 0;
    int k = start;

    while(i < n1 && j < n2) {
        if(lArr[i] <= rArr[j]) {
            arr[k] = lArr[i];
            i++;
        } else {
            arr[k] = rArr[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = lArr[i];
        k++;
        i++;
    }

    while(j < n2) {
        arr[k] = rArr[j];
        k++;
        j++;
    }

}

// Function for merge Sort.
void mergeSort(int *arr, int start, int end) {
    if(end > start) {
        int mid = start + (end - start)/2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }
}

// Main Function
int main() {

    int arr[] = {4,2,5,7,3,1,0,6,-1};

    cout << "Array Before Sorting : " << endl;
    for(auto num : arr) {
        cout << num << "\t";
    }
    mergeSort(arr, 0, 8);
    cout << endl << "Array After Sorting (Merge Sort) : " << endl;
    for(auto num : arr) {
        cout << num << "\t";
    }
}