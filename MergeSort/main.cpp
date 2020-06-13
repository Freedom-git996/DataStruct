#include <iostream>
#include <algorithm>
#include <string>

// 自己定义的，所以使用""引入 
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"

using namespace std;

int main() {
	int n = 100000;
	int *arr = SortTestHelper::generateRandomArray(n, 0, n);
	int *arr2 = SortTestHelper::copyIntArray(arr, n);
	int *arr3 = SortTestHelper::copyIntArray(arr, n);
	int *arr4 = SortTestHelper::copyIntArray(arr, n);
	
	SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
	SortTestHelper::testSort("Insertion Sort", insertionSort2, arr2, n);
	SortTestHelper::testSort("MergeSort  Sort", mergeSort, arr3, n);
	SortTestHelper::testSort("mergeSortBU  Sort", mergeSortBU, arr4, n);
	
	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	return 0;
}
