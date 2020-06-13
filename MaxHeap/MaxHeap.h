#ifndef MAXHEAP_HEAP_H
#define MAXHEAP_HEAP_H

#include <algorithm>
#include <cassert>
#include <typeinfo> 

using namespace std;

// �� ʹ������ʵ�֣���������Ϊ 0 ��λ�ò������� 
template<typename Item>
class MaxHeap {
	
private:
	Item* data;
	int count;
	int capacity; 
	
	void shiftUp(int k) {
		while(k > 1 && data[k / 2] < data[k]) {
			swap(data[k / 2], data[k]);
			k /= 2;
		}
	}
	
	void shiftDown(int k) {
		while(2 * k <= count) {
			int j = 2 * k; // �ڴ���ѭ���У�data[k] �� data[j] ����λ��
			if(j + 1 <= count && data[j + 1] > data[j])
				j += 1;
			if(data[k] >= data[j])
				break;
			swap(data[k], data[j]);
			k = j;
		}
	}
	
public:
	MaxHeap(int capacity) {
		data = new Item[capacity + 1];
		this->count = 0;
		this->capacity = capacity;
	}
	
	// Heapify �Ĺ��췽����ʹ�ö������ʱ�临�Ӷȱ�Ϊ O(n) 
	MaxHeap(Item arr[], int n) {
		data = new Item[n + 1];
		capacity = n;
		
		for(int i = 0; i < n; i ++) 
			data[i + 1] = arr[i];
		count = n;
		
		// �����һ������Ҷ�ӽڵ�Ľڵ㿪ʼ��ִ��shiftDown����
		for(int i = count / 2; i >= 1; i --) 
			shiftDown(i);
	} 
	
	~MaxHeap() {
		delete[] data;
	}
	
	int size() {
		return this->count;
	}
	
	bool isEmpty() {
		return this->count == 0;
	}
	
	void insert(Item item) {
		
		assert(count + 1 <= capacity);
		data[count + 1] = item;
		this->count ++;
		shiftUp(count);
	}
	
	Item extractMax() {
		
		assert(this->count > 0);
		Item ret = data[1];
		
		swap(data[1], data[count]);
		this->count --;
		shiftDown(1);
		
		return ret;
	}
};

#endif //MAXHEAP_HEAP_H
