#include <iostream>
#include <cassert>

using namespace std;

// ·��ѹ�� 
namespace UF5 {
	
	class UnionFind {
		
	private:
		int* parent;
		int* rank; // rank[i]��ʾ�� i Ϊ���ļ�������ʾ�����Ĳ��� 
		int count;
		
	public:
		UnionFind(int n) {
			count = n;
			parent = new int[n];
			rank = new int[n];
			for(int i = 0; i < n; i ++) {
				parent[i] = i;
				rank[i] = 1;
			}	
		}
		 
		~UnionFind() {
			delete[] parent;
			delete[] rank;
		}
		
		int find(int p) {
			
			assert(p >= 0 && p < count);
			
			// �汾һ ·��ѹ�� 
			
			while(parent[p] != p) {
				parent[p] = parent[parent[p]]; // ·��ѹ�� 
				p = parent[p];
			}
			
			return p;
			
			// �汾�� ·��ѹ����Ҫ�������Ϊ�����������еݹ�ջ���������� 
			
//			if(p != parent[p]) 
//				parent[p] = find(parent[p]);
//			return parent[p];
		}
		
		bool isConnected(int p, int q) {
			
			return find(p) == find(q);
		}
		
		void unionElements(int p, int q) {
			
			int pRoot = find(p);
			int qRoot = find(q);
			
			if(pRoot == qRoot) 
				return;
			
			if(rank[pRoot] < rank[qRoot]) {
				parent[pRoot] = qRoot;
			} else if(rank[pRoot] > rank[qRoot]) {
				parent[qRoot] = pRoot;
			} else {
				parent[pRoot] = qRoot;
				rank[qRoot] += 1;
			}
			
		}
	};
}

	
