#include <iostream>
using namespace std;

void pancakeSort(int n, int* nums) {
    for(int i = n-1; i > 0; i--) {
        int max_index = i;
        for(int j = 0; j < i; j++) {
            if(nums[j] > nums[max_index]) {
                max_index = j;
            }
        }
        if(max_index != i) {
            int a = 0, b = max_index;
            while(a < b) {
                swap(nums[a++],nums[b--]);
            }
            a = 0; b = i;
            while(a < b) {
                swap(nums[a++],nums[b--]);
            }
        }
    }
}

void printArray(int n, int* nums) {
    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
}

int main() {
    int n;
    cin >> n;
    int* nums = new int[n];

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    pancakeSort(n,nums);
    printArray(n,nums);
    return 0;
}
