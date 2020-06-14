#include <iostream>
#include <cassert>

using namespace std;

// 路径压缩 
namespace UF5 {
	
	class UnionFind {
		
	private:
		int* parent;
		int* rank; // rank[i]表示以 i 为根的集合所表示的树的层数 
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
			
			// 版本一 路径压缩 
			
			while(parent[p] != p) {
				parent[p] = parent[parent[p]]; // 路径压缩 
				p = parent[p];
			}
			
			return p;
			
			// 版本二 路径压缩，要所成深度为二的树，会有递归栈的性能消耗 
			
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

	
