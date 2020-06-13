#ifndef QUICKSORT_INSERTTIONSORT_H
#define QUICKSORT_INSERTTIONSORT_H

#include <iostream>
#include <algorithm>

using namespace std;

// ��������  ʱ�临�Ӷ� O(n^2)
// 
// ���ѡ����������������ܿ�����ֹ����Ҫ���ڲ�ѭ�� 
// �Խ�������ĵ������������ʱ�����ֹ۵������ʱ�临�Ӷ��ܴﵽ O(n) 
// 
// ģ������ ������Java�еķ��� 
template<typename T> 
void insertionSort(T arr[], int n) {
	
	for(int i = 1; i < n; i ++) {
		
		// Ѱ��Ԫ�� arr[i] ���ʵĲ���λ��
		// �������� �� ѡ�������������� ������ǰ��ֹѭ��
		for(int j = i; j > 0 && arr[j] < arr[j - 1]; j --)
			swap(arr[j], arr[j - 1]);
	}
}

// ���������Ż����� ��� �ȽϺ�Ľ������� ��� �ȽϺ��һ�θ�ֵ���� 
template<typename T> 
void insertionSort2(T arr[], int n) {
	
	for(int i = 1; i < n; i ++) {
		
		// Ѱ��Ԫ�� arr[i] ���ʵĲ���λ��
		T e = arr[i];
		int j;  // j ����Ԫ�� e Ӧ�ò����λ��
		for(j = i; j > 0 && arr[j - 1] > e; j --)
			arr[j] = arr[j - 1];
		arr[j] = e;
	}
}

// �� arr[l...r]��Χ��������в�������, �Ը߼������������ٵ�����µ��Ż� 
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
