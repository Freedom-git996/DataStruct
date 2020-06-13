#include <iostream>
#include <algorithm>
#include <string>

// �Լ�����ģ�����ʹ��""���� 
#include "SortTestHelper.h"
#include "SelectionSort.h"

using namespace std;

// ��������  ʱ�临�Ӷ� O(n*n)
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

int main() {
	int n = 10000;
	int *arr = SortTestHelper::generateNearlyOrderedArray(n, 10);
	int *arr2 = SortTestHelper::copyIntArray(arr, n);
	int *arr3 = SortTestHelper::copyIntArray(arr, n);
	
	SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
	SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
	SortTestHelper::testSort("Insertion2 Sort", insertionSort2, arr3, n);
	
	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	return 0;
}
