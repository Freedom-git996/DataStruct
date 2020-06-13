#ifndef MAXHEAP_HEAP_H
#define MAXHEAP_HEAP_H

#include <algorithm>
#include <cassert>
#include <typeinfo> 

using namespace std;

// 堆 使用数组实现，数组索引为 0 的位置不存数据 
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
			int j = 2 * k; // 在此轮循环中，data[k] 和 data[j] 交换位置
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
	
	// Heapify 的构造方法，使得堆排序的时间复杂度变为 O(n) 
	MaxHeap(Item arr[], int n) {
		data = new Item[n + 1];
		capacity = n;
		
		for(int i = 0; i < n; i ++) 
			data[i + 1] = arr[i];
		count = n;
		
		// 从最后一个不是叶子节点的节点开始，执行shiftDown操作
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
