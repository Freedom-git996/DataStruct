#ifndef MAXHEAP_SELECTIONSORT_H
#define MAXHEAP_SELECTIONSORT_H

#include <iostream>
#include <algorithm>

using namespace std;

// ѡ������  ʱ�临�Ӷ� O(n^2) ���ȶ�	 
// ѡ������ ���� ����� ð�������������ڲ���Ҫ��¼��С��������������ÿ�ν���С��Ԫ�� ǰ��һ�� 
template<typename T>
void selectionSort(T arr[], int n) {
	
	for(int i = 0; i < n; i ++) {
		
		// Ѱ�� [i, n)���������Сֵ������ 
		int minIndex = i;
		for(int j = i + 1; j < n; j ++)
			if(arr[j] < arr[minIndex])
				minIndex = j;
		// Ȼ������λ�õ�ֵ�뵱ǰ i λ������������ 
		swap(arr[i], arr[minIndex]);
	}
}

// ð������  ʱ�临�Ӷ� O��n^2) �ȶ� 
// ѡ��������ð������ �ȽϵĴ�����һ���ģ����ǽ�������ð������Ҫ�࣬�����ܵ���˵��ѡ����������ð������ 
template<typename T>
void bubbleSort(T arr[], int n) {
	
	for(int i = 0; i < n; i ++) 
		for(int j = i + 1; j < n; j ++) 
			if(arr[j] < arr[i])
				swap(arr[i], arr[j]);
}

#endif //MAXHEAP_SELECTIONSORT_H
