#ifndef INSERTIONSORT_SORTTESTHELPER_H
#define INSERTIONSORT_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper {
	
	// 生成有n个元素的随机数组，每个元素的随机范围为 [rangeL, rangeR] 
	int* generateRandomArray(int n, int rangeL, int rangeR) {
		
		// 断言 rangeL <= rangeR 
		assert(rangeL <= rangeR);
		int *arr = new int[n];
		// 生成随机数种子 
		srand(time(NULL));
		for(int i = 0; i < n; i ++)
			// 生成随机数 
			arr[i] = rand() % (rangeR- rangeL + 1) + rangeL;
		return arr;
	}
	
	// 生成一个近乎有序的数组
	int* generateNearlyOrderedArray(int n, int swapTimes) {
		
		int *arr = new int[n];
		// 生成有序数组 
		for(int i = 0; i < n; i ++)
			arr[i] = i;
		// 随机打乱顺序 
		srand(time(NULL));
		for(int i = 0; i < swapTimes; i ++) {
			int posx = rand() % n;
			int posy = rand() % n;
			swap(arr[posx], arr[posy]);
		}
		return arr;
	}
	
	// 打印 
	template<typename T>
	void printArray(T arr[], int n) {
		for(int i = 0; i < n; i ++)
			cout<<arr[i]<<" ";
		cout<<endl;
		return;
	}
	
	// 验证排序的正确性 
	template<typename T>
	bool isSorted(T arr[], int n) {
		
		for(int i = 0; i < n - 1; i ++)
			if(arr[i] > arr[i + 1])
				return false;
		return true;
	}
	
	// 测试方法性能
	// 第二个参数表示，方法的 返回值为 void，参数为 T[], int 
	template<typename T>
	void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {
		
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();
		
		// 验证排序的正确性 
		assert(isSorted(arr, n));
		cout<<sortName<<" : "<<double(endTime - startTime) / CLOCKS_PER_SEC<<" s"<<endl; 
		return;
	}
	
	// 复制数组 
	int* copyIntArray(int a[], int n) {
		int* arr = new int[n];
		copy(a, a+n, arr);
		return arr;
	}
}

#endif //INSERTIONSORT_SORTTESTHELPER_H
