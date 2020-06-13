#include <iostream>
#include <algorithm>
#include <string>

// Student.h���Լ�����ģ�����ʹ��""���� 
#include "Student.h"
#include "SortTestHelper.h"

using namespace std;

// ѡ������  ʱ�临�Ӷ� O(n*n)
// ģ������ ������Java�еķ��� 
template<typename T> 
void selectionSort(T arr[], int n) {
	for(int i = 0; i < n; i ++) {
		
		// Ѱ�� [i, n)���������Сֵ
		int minIndex = i;
		for(int j = i + 1; j < n; j ++)
			if(arr[j] < arr[minIndex])
				minIndex = j;
		swap(arr[i], arr[minIndex]);
	}
}

int main() {
	
	int n = 100000;
	int *arr = SortTestHelper::generateRandomArray(n, 0, n);
	SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
	cout<<endl;
	// �ͷ��ڴ� 
	delete[] arr;
	
	return 0;
}
