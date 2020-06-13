#include <iostream>
#include <cmath>
#include <cassert>
#include <ctime>

#include "MyUtil.h"

using namespace std;

// 二分查找  时间复杂度 O(logn) 
template<typename T>
int binarySearch(T arr[], int n, T target) {
	
	// 在 [l...r]的范围里寻找target 
	int l = 0, r = n - 1;
	
	// 当 l == r时，区间 [l...r]依然有效，所以 l<=r 
	while(l <= r) {
		// 使用减法求中间索引，避免溢出 
		int mid = l + (r - l) / 2;
		if(arr[mid] == target)
			return mid;
		if(target > arr[mid])
			// target 在 [mid+1...r] 中 
			l = mid + 1;
		else 
			r = mid - 1; 
	}
	
	return -1;
}

int main() {
	int n = 1000000;
	int* data = MyUtil::generateOrderedArray(n);
	
	clock_t startTime = clock();	
	for(int i = 0; i < n; i ++) 
		assert(i == binarySearch(data, n, i));
	clock_t endTime = clock();
	
	cout<<"binarySearch test complete."<<endl;
	cout<<"Time cost: "<<double(endTime - startTime) / CLOCKS_PER_SEC<<" s"<<endl;
	return 0;
}
