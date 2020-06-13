#ifndef MAXHEAP_SELECTIONSORT_H
#define MAXHEAP_SELECTIONSORT_H

#include <iostream>
#include <algorithm>

using namespace std;

// 选择排序  时间复杂度 O(n^2) 不稳定	 
// 选择排序 可以 延申成 冒泡排序，区别在于不需要记录最小处的索引，而是每次将较小的元素 前移一个 
template<typename T>
void selectionSort(T arr[], int n) {
	
	for(int i = 0; i < n; i ++) {
		
		// 寻找 [i, n)区间里的最小值的索引 
		int minIndex = i;
		for(int j = i + 1; j < n; j ++)
			if(arr[j] < arr[minIndex])
				minIndex = j;
		// 然后将索引位置的值与当前 i 位置做交换操作 
		swap(arr[i], arr[minIndex]);
	}
}

// 冒泡排序  时间复杂度 O（n^2) 稳定 
// 选择排序与冒泡排序 比较的次数是一样的，但是交换次数冒泡排序要多，所以总的来说，选择排序优于冒泡排序 
template<typename T>
void bubbleSort(T arr[], int n) {
	
	for(int i = 0; i < n; i ++) 
		for(int j = i + 1; j < n; j ++) 
			if(arr[j] < arr[i])
				swap(arr[i], arr[j]);
}

#endif //MAXHEAP_SELECTIONSORT_H
