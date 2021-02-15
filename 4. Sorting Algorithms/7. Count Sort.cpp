#include<iostream>
using namespace std;

// Count Sort Function
void countSort(int* nums, int n, int m) {
	int count[m+1] = {0};
	for(int i = 0; i < n; i++) {
		count[nums[i]]++;
	}
	for(int i = 1; i <= m; i++) {
		count[i] = count[i] + count[i-1];
	}
	for(int i = m; i >= 1; i--) {
		count[i] = count[i-1];
	}
	int* res = new int[n];
	for(int i = 0; i < n; i++) {
		res[count[nums[i]]] = nums[i];
		count[nums[i]]++;
	}
	for(int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
}

// Main Function
int main() {
	int n;
	cin >> n;
	int* nums = new int[n];
	int m = 0;
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
		m = max(m,nums[i]);
	}
	countSort(nums,n,m);
	return 0;
}
