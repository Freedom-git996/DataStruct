#ifndef QUICKSORT_INSERTTIONSORT_H
#define QUICKSORT_INSERTTIONSORT_H

#include <iostream>
#include <algorithm>

using namespace std;

// 插入排序  时间复杂度 O(n^2)
// 
// 相比选择排序的优势在于能快速终止不必要的内层循环 
// 对近乎有序的的数组进行排序时，最乐观的情况下时间复杂度能达到 O(n) 
// 
// 模板类型 类似于Java中的泛型 
template<typename T> 
void insertionSort(T arr[], int n) {
	
	for(int i = 1; i < n; i ++) {
		
		// 寻找元素 arr[i] 合适的插入位置
		// 插入排序 较 选择排序，优势在于 可以提前终止循环
		for(int j = i; j > 0 && arr[j] < arr[j - 1]; j --)
			swap(arr[j], arr[j - 1]);
	}
}

// 插入排序优化：将 多次 比较后的交换操作 变成 比较后的一次赋值操作 
template<typename T> 
void insertionSort2(T arr[], int n) {
	
	for(int i = 1; i < n; i ++) {
		
		// 寻找元素 arr[i] 合适的插入位置
		T e = arr[i];
		int j;  // j 保存元素 e 应该插入的位置
		for(j = i; j > 0 && arr[j - 1] > e; j --)
			arr[j] = arr[j - 1];
		arr[j] = e;
	}
}

// 对 arr[l...r]范围的数组进行插入排序, 对高级排序在数量少的情况下的优化 
template<typename T>
void insertionSort3(T arr[], int l, int r) {
	
	for(int i = l + 1; i <= r; i ++) {
		T e = arr[i];
		int j;
		for(j = i; j > l && arr[j - 1] > e; j --) 
			arr[j] = arr[j - 1];
		arr[j] = e;
	}
	return;
}

#endif //QUICKSORT_INSERTTIONSORT_H
