#ifndef MERGESORT_MERGESORT_H
#define MERGESORT_MERGESORT_H

#include <iostream>
#include <algorithm>

using namespace std;

// 将 arr[l...mid] 和 arr[mid+1...r]两部分进行归并 
template<typename T>
void __merge(T arr[], int l, int mid, int r) {
	
	T aux[r - l + 1];
	for(int i = l; i <= r; i ++)
		aux[i - l] = arr[i];
	int i = l, j = mid + 1;
	for(int k = l; k <= r; k ++) {
		if(i > mid) {
			arr[k] = aux[j - l];
			j ++;
		}else if(j > r) {
			arr[k] = aux[i -l];
			i ++;
		}else if(aux[i - l] < aux[j - l]) {
			arr[k] = aux[i - l];
			i ++;
		}else {
			arr[k] = aux[j - l];
			j ++;
		}
	}
}

template<typename T>
void __mergeSort(T arr[], int l, int r) {
	
	if(l >= r)
		return;
	int mid = l + (r - l) / 2;
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid + 1, r);
	
	// 只有当左数组的最后一个小于右数组的第一个时，才需要在合并时重新排序 
	if(arr[mid] > arr[mid + 1])
		__merge(arr, l, mid, r);
}

// 对归并排序的优化，当数量小时选择使用插入排序 
// 递归使用归并排序，对 arr[l...r]的范围进行排序 
template<typename T>
void __mergeSort2(T arr[], int l, int r) {

//	 当数组长度较小时，选用插入排序进行优化 
	if(r - l <= 15) {
		insertionSort3(arr, l, r);
		return;
	}
	int mid = l + (r - l) / 2;
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid + 1, r);
	if(arr[mid] > arr[mid + 1])
		__merge(arr, l, mid, r);
}

// 归并排序  时间复杂度 O(nlogn)
// 模板类型 类似于Java中的泛型 
template<typename T>
void mergeSort(T arr[], int n) {
	
//	__mergeSort(arr, 0, n - 1);
	
	__mergeSort2(arr, 0, n - 1); 
}

// 自底向上的归并排序，避免了递归 
template <typename T>
void mergeSortBU(T arr[], int n) {
	
	for(int sz = 1; sz <= n; sz += sz) {
		for(int i = 0; i + sz < n; i += sz + sz) {
			__merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));  
		}
	}
}

#endif //MERGESORT_MERGESORT_H
