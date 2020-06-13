#include <iostream>
#include <algorithm>
#include <string>

// Student.h是自己定义的，所以使用""引入 
#include "Student.h"
#include "SortTestHelper.h"

using namespace std;

// 选择排序  时间复杂度 O(n*n)
// 模板类型 类似于Java中的泛型 
template<typename T> 
void selectionSort(T arr[], int n) {
	for(int i = 0; i < n; i ++) {
		
		// 寻找 [i, n)区间里的最小值
		int minIndex = i;
		for(int j = i + 1; j < n; j ++)
			if(arr[j] < arr[minIndex])
				minIndex = j;
		swap(arr[i], arr[minIndex]);
	}
}

int main() {
	
	int n = 100000;
	int *arr = SortTestHelper::generateRandomArray(n, 0, n);
	SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
	cout<<endl;
	// 释放内存 
	delete[] arr;
	
	return 0;
}
