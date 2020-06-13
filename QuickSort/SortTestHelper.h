#ifndef QUICKSORT_MERGESORT_H
#define QUICKSORT_MERGESORT_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper {
	
	// ������n��Ԫ�ص�������飬ÿ��Ԫ�ص������ΧΪ [rangeL, rangeR] 
	int* generateRandomArray(int n, int rangeL, int rangeR) {
		
		// ���� rangeL <= rangeR 
		assert(rangeL <= rangeR);
		int *arr = new int[n];
		// ������������� 
		srand(time(NULL));
		for(int i = 0; i < n; i ++)
			// ��������� 
			arr[i] = rand() % (rangeR- rangeL + 1) + rangeL;
		return arr;
	}
	
	// ����һ���������������
	int* generateNearlyOrderedArray(int n, int swapTimes) {
		
		int *arr = new int[n];
		// ������������ 
		for(int i = 0; i < n; i ++)
			arr[i] = i;
		// �������˳�� 
		srand(time(NULL));
		for(int i = 0; i < swapTimes; i ++) {
			int posx = rand() % n;
			int posy = rand() % n;
			swap(arr[posx], arr[posy]);
		}
		return arr;
	}
	
	// ��ӡ 
	template<typename T>
	void printArray(T arr[], int n) {
		for(int i = 0; i < n; i ++)
			cout<<arr[i]<<" ";
		cout<<endl;
		return;
	}
	
	// ��֤�������ȷ�� 
	template<typename T>
	bool isSorted(T arr[], int n) {
		
		for(int i = 0; i < n - 1; i ++)
			if(arr[i] > arr[i + 1])
				return false;
		return true;
	}
	
	// ���Է�������
	// �ڶ���������ʾ�������� ����ֵΪ void������Ϊ T[], int 
	template<typename T>
	void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {
		
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();
		
		// ��֤�������ȷ�� 
		assert(isSorted(arr, n));
		cout<<sortName<<" : "<<double(endTime - startTime) / CLOCKS_PER_SEC<<" s"<<endl; 
		return;
	}
	
	// �������� 
	int* copyIntArray(int a[], int n) {
		int* arr = new int[n];
		copy(a, a+n, arr);
		return arr;
	}
}

#endif //QUICKSORT_MERGESORT_H