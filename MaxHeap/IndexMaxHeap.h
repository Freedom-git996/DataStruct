#ifndef MAXHEAP_INDEXMAXHEAP_H
#define MAXHEAP_INDEXMAXHEAP_H

#include <algorithm>
#include <cassert>
#include <typeinfo> 

using namespace std;

// �� ʹ������ʵ�֣���������Ϊ 0 ��λ�ò������� 
template<typename Item>
class IndexMaxHeap {
	
private:
	Item* data;
	int* indexs;
	int* reverse; 
	int count;
	int capacity; 
	
	void shiftUp(int k) {
		while(k > 1 && data[indexs[k / 2]] < data[indexs[k]]) {
			swap(indexs[k / 2], indexs[k]);
			reverse[indexs[k / 2]] = k / 2;
			reverse[indexs[k]] = k;
			k /= 2;
		}
	}
	
	void shiftDown(int k) {
		while(2 * k <= count) {
			int j = 2 * k; // �ڴ���ѭ���У�data[k] �� data[j] ����λ��
			if(j + 1 <= count && data[indexs[j + 1]] > data[indexs[j]])
				j += 1;
			if(data[indexs[k]] >= data[indexs[j]])
				break;
			swap(indexs[k], indexs[j]);
			reverse[indexs[k]] = k;
			reverse[indexs[j]] = j;
			k = j;
		}
	}
	
public:
	IndexMaxHeap(int capacity) {
		data = new Item[capacity + 1];
		indexs = new int[capacity + 1];
		reverse = new int[capacity + 1];
		for(int i = 0; i <= capacity; i ++)
			reverse[i] = 0;
		this->count = 0;
		this->capacity = capacity;
	}
	
	~IndexMaxHeap() {
		delete[] data;
		delete[] indexs;
		delete[] reverse;
	}
	
	int size() {
		return this->count;
	}
	
	bool isEmpty() {
		return this->count == 0;
	}
	
	// ����� i ���û����ԣ��Ǵ� 0 ��ʼ�� 
	void insert(int i, Item item) {
		
		assert(count + 1 <= capacity);
		assert(i + 1 >= 1 && i + 1 <= capacity);
		
		// �ֶ��� i ��Ϊ�� 1 ��ʼ���� 
		i += 1;
		data[i] = item;
		indexs[count + 1] = i;
		reverse[i] = count + 1;
		
		this->count ++;
		shiftUp(count);
	}
	
	Item extractMax() {
		
		assert(this->count > 0);
		
		Item ret = data[indexs[1]];
		
		swap(indexs[1], indexs[count]);
		reverse[indexs[1]] = 1;
		reverse[indexs[count]] = 0;
		this->count --;
		shiftDown(1);
		
		return ret;
	}
	
	// ����� i ���û����ԣ��Ǵ� 0 ��ʼ�� 
	int extractMaxIndex() {
		
		assert(this->count > 0);
		
		int ret = indexs[1] - 1;
		
		swap(indexs[1], indexs[count]);
		reverse[indexs[1]] = 1;
		reverse[indexs[count]] = 0;
		this->count --;
		shiftDown(1);
		
		return ret;
	}
	
	bool contain(int i) {
		
		assert(i + 1 >= 1 && i + 1 <= capacity)
		return reverse[i + 1] != 0;
	}
	
	Item getItem(int i) {
		
		assert( contain(i) );
		
		return data[i + 1];
	}
	
	// ���Ӷ� O(n) 
	void change1(int i, Item newItem) {
		
		assert( contain(i) );
		
		i += 1;
		data[i] = newItem;
		
		// �ҵ�indexs[j] = i, j ��ʾ data[i] �ڶ��е�λ��
		// ֮�� shiftUp(j)����shiftDown(j)
		for(int j = 1; j <= count; j ++) {
			if(indexs[j] == i) {
				shiftUp(j);
				shiftDown(j);
				return;
			}
		} 
	}
	
	// �Ż������Ӷ� O(1) 
	void change2(int i, Item newItem) {
		
		assert( contain(i) );
		
		i += 1;
		data[i] = newItem;

		int j = reverse[i];
		shiftUp(j);
		shiftDown(j);
	}
};

#endif //MAXHEAP_INDEXMAXHEAP_H
