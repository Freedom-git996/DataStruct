#include <iostream>
#include <cassert>

using namespace std;

// QUICK UNION 模式 

// 由于没有顾及并查集的高度问题，所以在 n 很大的时候，我们的并查集这棵树是高概率高度不平衡，
// 甚至和链表区别不大。此时，并查集的 union 操作和 find 操作都是 O(h) 这个数量级，如果 h 
// 和 n 的差别没有那么大的话，并查集整体就体现不出优势；而 Quick Find 判断 isConnected 
// 恒定是O(1)的时间复杂度，有很大的优势
namespace UF2 {
	
	class UnionFind {
		
	private:
		int* parent;
		int count;
		
	public:
		UnionFind(int n) {
			count = n;
			parent = new int[n];
			for(int i = 0; i < n; i ++)
				parent[i] = i;
		}
		 
		~UnionFind() {
			delete[] parent;
		}
		
		int find(int p) {
			
			assert(p >= 0 && p < count);
			while(parent[p] != p)
				p = parent[p];
			return p;
		}
		
		bool isConnected(int p, int q) {
			
			return find(p) == find(q);
		}
		
		void unionElements(int p, int q) {
			
			int pRoot = find(p);
			int qRoot = find(q);
			
			if(pRoot == qRoot) 
				return;
			
			parent[pRoot] = qRoot;
		}
	};
}

	
