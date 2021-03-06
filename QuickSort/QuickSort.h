#ifndef QUICKSORT_QUICKSORT_H
#define QUICKSORT_QUICKSORT_H

#include <iostream>
#include <algorithm>

// 对 arr[l...r]部分进行partition操作
// 返回 p, 使得 arr[l...p-1] < arr[p]; arr[p+1...r] > arr[p] 
template <typename T>
int __partition(T arr[], int l, int r) {
	
	T v = arr[l];
	
	int j = l;
	for(int i = l + 1; i <= r; i ++) {
		if(arr[i] < v) {
			swap(arr[j + 1], arr[i]);
			j ++;
		}
	}
	swap(arr[l], arr[j]);
	return j;
}

// 优化 1
template <typename T>
int __partition1(T arr[], int l, int r) {
	
	// 使用随机选择,尽量避免快排进入最坏的情况 O(n^2) 
	swap(arr[l], arr[rand() %(r - l + 1) + l]);
	T v = arr[l];
	
	int j = l;
	for(int i = l + 1; i <= r; i ++) {
		if(arr[i] < v) {
			swap(arr[j + 1], arr[i]);
			j ++;
		}
	}
	swap(arr[l], arr[j]);
	return j;
}

// 优化 2 双路快排 
template <typename T>
int __partition2(T arr[], int l, int r) {
	
	// 优化 1
	// 使用随机选择,尽量避免快排进入最坏的情况 O(n^2) 
	swap(arr[l], arr[rand() %(r - l + 1) + l]);
	T v = arr[l];
	
	int i = l + 1, j = r;
	while(true) {
		while(i <= r && arr[i] < v) i ++;
		while(j > l + 1 && arr[j] > v) j --;
		if(i > j) break;
		swap(arr[i], arr[j]);
		i ++;
		j --;
	}
	swap(arr[l], arr[j]);
}

// 对 arr[l...r]部分进行快速排序 
template <typename T>
void __quickSort(T arr[], int l, int r) {
	
	if(l >= r) 
		return;

	int p = __partition2(arr, l, r);
	__quickSort(arr, l, p - 1);
	__quickSort(arr, p + 1, r);
}

// 同样的，对于高级的排序算法，当数量较少时可以选用 插入排序  优化
template <typename T>
void __quickSort2(T arr[], int l, int r) {

	//	 当数组长度较小时，选用插入排序进行优化 
	if(r - l <= 15) {
		insertionSort3(arr, l, r);
		return;
	}

	int p = __partition(arr, l, r);
	__quickSort(arr, l, p - 1);
	__quickSort(arr, p + 1, r);
}

// 优化 3 三路快排 
template <typename T>
void __quickSort3(T arr[], int l, int r) {
	
	//	 当数组长度较小时，选用插入排序进行优化 
	if(r - l <= 15) {
		insertionSort3(arr, l, r);
		return;
	}

	// 优化 1
	// 使用随机选择,尽量避免快排进入最坏的情况 O(n^2) 
	swap(arr[l], arr[rand() %(r - l + 1) + l])
	T v = arr[l];
	
	int lt = l;
	int gt = r + 1;
	int i =  l + 1;
	while(i < gt) {
		if(arr[i] < v) {
			swap(arr[i], arr[lt + 1]);
			lt ++;
			i ++;
		}else if (arr[i] > v) {
			swap(arr[i], arr[gt - 1]);
			gt --;
		}else {
			i ++;
		}
	}
	
	swap(arr[l], arr[lt]);
	
	__quickSort3(arr, l, lt - 1);
	__quickSort3(arr, gt, r);
}

template <typename T>
void quickSort(T arr[], int n) {
	
	// quickSort(arr, 0, n - 1); 
	
	srand(time(NULL));
	__quickSort3(arr, 0, n - 1);
}

#endif //QUICKSORT_QUICKSORT_H
