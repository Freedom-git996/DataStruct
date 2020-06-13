#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>

// �Լ�����ģ�����ʹ��""���� 
#include "SortTestHelper.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "MaxHeap.h" 

using namespace std;

// ������1 ʱ�临�Ӷ� O(nlogn) 
template<typename T>
void heapSort1(T arr[], int n) {
	
	MaxHeap<T> maxHeap = MaxHeap<T>(n);
	for(int i = 0; i < n; i ++)
		maxHeap.insert(arr[i]);
	for(int i = n - 1; i >= 0; i --)
		arr[i] = maxHeap.extractMax();
}

// ������2 ����ʱ�临�Ӷ� ʱ�临�Ӷ� O(n)
template<typename T>
void heapSort2(T arr[], int n) {
	
	MaxHeap<T> maxHeap = MaxHeap<T>(arr, n);
	for(int i = n - 1; i >= 0; i --) 
		arr[i] = maxHeap.extractMax();
}

template<typename T>
void __shiftDown(T arr[], int n, int k) {
	
	while(2 * k + 1 < n) {
		int j = 2 * k + 1; // �ڴ���ѭ���У�data[k] �� data[j] ����λ��
		if(j + 1 < n && arr[j + 1] > arr[j])
			j += 1;
		if(arr[k] >= arr[j])
			break;
		swap(arr[k], arr[j]);
		k = j;
	}
}

// ������3 ���ٿռ临�Ӷ� 
// ����ԭ�ؽ��ж�����
// �뾭���������ȣ�������ԭ�ؽ��ж��������������� 0 ��ʼ 
template<typename T>
void heapSort3(T arr[], int n) {
	
	// �ӵ�һ����Ҷ�ӽڵ㿪ʼ��ִ�� shiftDown ����
	// ���һ������Ҷ�ӽڵ������ = �����һ��Ԫ�ص����� - 1) / 2
	for(int i = (n - 1 - 1) / 2; i >= 0; i --) 
		__shiftDown(arr, n, i);
	
	// ������һ��Ԫ�غ����һ��Ԫ�ص�λ�ã���������Ԫ�طŵ������ĩβ
	// Ȼ��� ʣ�µ�Ԫ�� ���½��ж����� 
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
