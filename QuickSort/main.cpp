#include <iostream>
#include <algorithm>
#include <string>

// 自己定义的，所以使用""引入 
#include "SortTestHelper.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

using namespace std;

int __partition(int* arr, int l, int r) {
	int pivot = arr[l];
	int j = l;
	for(int i = l + 1; i < r; i ++)
		if(arr[i] < pivot)
			swap(arr[++j], arr[i]);
	swap(arr[j], arr[l]);
	return j;
}

// [l...r)
void __quickSortDemo(int* arr, int l, int r) {
	if(r - l <= 1) 
		return;
	int p = __partition(arr, l, r);
	__quickSortDemo(arr, l, p);
	__quickSortDemo(arr, p + 1, r);
}

// [0...n)
void quickSortDemo(int* arr, int n) {
	
	__quickSortDemo(arr, 0, n);
}

int main() {
	int n = 100000;
	int *arr = SortTestHelper::generateRandomArray(n, 0, n);
	int *arr2 = SortTestHelper::copyIntArray(arr, n);
	int *arr3 = SortTestHelper::copyIntArray(arr, n);
	int *arr4 = SortTestHelper::copyIntArray(arr, n);
	int *arr5 = SortTestHelper::copyIntArray(arr, n);
	int *arr6 = SortTestHelper::copyIntArray(arr, n);

	SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
	SortTestHelper::testSort("Bubble Sort", bubbleSort, arr2, n);
	SortTestHelper::testSort("Insertion Sort", insertionSort2, arr3, n);
	SortTestHelper::testSort("MergeSort  Sort", mergeSort, arr4, n);
	SortTestHelper::testSort("mergeSortBU  Sort", mergeSortBU, arr5, n);
	SortTestHelper::testSort("quickSort sort", quickSortDemo, arr6, n);
	
	cout<<"Nearly Order Array: "<<endl;
	int n2 = 60000; 
	int *arr7 = SortTestHelper::generateNearlyOrderedArray(n2, 100);
	int *arr8 = SortTestHelper::copyIntArray(arr7, n2);
	SortTestHelper::testSort("MergeSort  Sort", mergeSort, arr7, n2);
	SortTestHelper::testSort("quickSort sort", quickSort, arr8, n2);
	
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
