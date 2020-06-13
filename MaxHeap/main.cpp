#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>

// 自己定义的，所以使用""引入 
#include "SortTestHelper.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "MaxHeap.h" 

using namespace std;

// 堆排序1 时间复杂度 O(nlogn) 
template<typename T>
void heapSort1(T arr[], int n) {
	
	MaxHeap<T> maxHeap = MaxHeap<T>(n);
	for(int i = 0; i < n; i ++)
		maxHeap.insert(arr[i]);
	for(int i = n - 1; i >= 0; i --)
		arr[i] = maxHeap.extractMax();
}

// 堆排序2 减少时间复杂度 时间复杂度 O(n)
template<typename T>
void heapSort2(T arr[], int n) {
	
	MaxHeap<T> maxHeap = MaxHeap<T>(arr, n);
	for(int i = n - 1; i >= 0; i --) 
		arr[i] = maxHeap.extractMax();
}

template<typename T>
void __shiftDown(T arr[], int n, int k) {
	
	while(2 * k + 1 < n) {
		int j = 2 * k + 1; // 在此轮循环中，data[k] 和 data[j] 交换位置
		if(j + 1 < n && arr[j + 1] > arr[j])
			j += 1;
		if(arr[k] >= arr[j])
			break;
		swap(arr[k], arr[j]);
		k = j;
	}
}

// 堆排序3 减少空间复杂度 
// 数组原地进行堆排序
// 与经典堆排序相比，由于是原地进行堆排序，所以索引从 0 开始 
template<typename T>
void heapSort3(T arr[], int n) {
	
	// 从第一个非叶子节点开始，执行 shiftDown 操作
	// 最后一个不是叶子节点的索引 = （最后一个元素的索引 - 1) / 2
	for(int i = (n - 1 - 1) / 2; i >= 0; i --) 
		__shiftDown(arr, n, i);
	
	// 交换第一个元素和最后一个元素的位置，即将最大的元素放到数组的末尾
	// 然后对 剩下的元素 重新进行堆排序 
	for(int i = n - 1; i > 0; i --) {
		swap(arr[0], arr[i]);
		__shiftDown(arr, i , 0);
	}
}

int main() {
	
	int n = 100001;
	int *arr = SortTestHelper::generateRandomArray(n, 0, n);
	int *arr2 = SortTestHelper::copyIntArray(arr, n);
	int *arr3 = SortTestHelper::copyIntArray(arr, n);
	int *arr4 = SortTestHelper::copyIntArray(arr, n);
	int *arr5 = SortTestHelper::copyIntArray(arr, n);
	int *arr6 = SortTestHelper::copyIntArray(arr, n);
	int *arr7 = SortTestHelper::copyIntArray(arr, n);
	int *arr8 = SortTestHelper::copyIntArray(arr, n);

	SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
	SortTestHelper::testSort("Bubble Sort", bubbleSort, arr2, n);
	SortTestHelper::testSort("Insertion Sort", insertionSort2, arr3, n);
	SortTestHelper::testSort("MergeSort  Sort", mergeSort, arr4, n);
	SortTestHelper::testSort("quickSort sort", quickSort, arr5, n);
	SortTestHelper::testSort("heapSort1 sort", heapSort1, arr6, n);
	SortTestHelper::testSort("heapSort2 sort", heapSort2, arr7, n);
	SortTestHelper::testSort("heapSort3 sort", heapSort3, arr8, n);
	
	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;
	delete[] arr7;
	delete[] arr8;
	return 0;
}
