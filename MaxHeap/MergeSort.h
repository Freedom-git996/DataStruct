//#ifndef MAXHEAP_MERGESORT_H
//#define MAXHEAP_MERGESORT_H

#include <iostream>
#include <algorithm>

using namespace std;

// �鲢����  ʱ�临�Ӷ� O(nlogn)
// 
// �� arr[l...mid] �� arr[mid+1...r]�����ֽ��й鲢 
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
	
	// ֻ�е�����������һ��С��������ĵ�һ��ʱ������Ҫ�ںϲ�ʱ�������� 
	if(arr[mid] > arr[mid + 1])
		__merge(arr, l, mid, r);
}

// �Թ鲢������Ż���������Сʱѡ��ʹ�ò������� 
// �ݹ�ʹ�ù鲢���򣬶� arr[l...r]�ķ�Χ�������� 
template<typename T>
void __mergeSort2(T arr[], int l, int r) {

//	 �����鳤�Ƚ�Сʱ��ѡ�ò�����������Ż� 
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

// �鲢����  ʱ�临�Ӷ� O(nlogn)
// ģ������ ������Java�еķ��� 
// �� [0...length-1]���й鲢���� 
template<typename T>
void mergeSort(T arr[], int n) {
	
//	__mergeSort(arr, 0, n - 1);
	
	__mergeSort2(arr, 0, n - 1); 
}

// �Ե����ϵĹ鲢���򣬱����˵ݹ� 
template <typename T>
void mergeSortBU(T arr[], int n) {
	
	for(int sz = 1; sz <= n; sz += sz) {
		for(int i = 0; i + sz < n; i += sz + sz) {
			__merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));  
		}
	}
}




// �ı�߽������� DEMO 
void __mergeDemo(int* arr, int l, int mid, int r) {
	int aux[r - l];
	for(int i = l; i < r; i ++) 
		aux[i - l] = arr[i];
		
	int i = l, j = mid;
	for(int k = l; k < r; k ++) {
		if(i >= mid) {
			arr[k] = aux[j - l];
			j ++;
		}else if(j >= r) {
			arr[k] = aux[i - l];
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

void __mergeSortDemo(int* arr, int l, int r) {
	if(r - l <= 1) 
		return;
	int mid = l + (r - l) / 2;
	__mergeSortDemo(arr, l, mid);
	__mergeSortDemo(arr, mid, r);
	__mergeDemo(arr, l, mid, r);
}

void mergeSortDemo(int* arr, int n) {
	
	__mergeSortDemo(arr, 0, n);
}

//#endif //MAXHEAP_MERGESORT_H
