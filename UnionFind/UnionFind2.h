#include <iostream>
#include <cassert>

using namespace std;

// QUICK UNION ģʽ 

// ����û�й˼����鼯�ĸ߶����⣬������ n �ܴ��ʱ�����ǵĲ��鼯������Ǹ߸��ʸ߶Ȳ�ƽ�⣬
// �������������𲻴󡣴�ʱ�����鼯�� union ������ find �������� O(h) �������������� h 
// �� n �Ĳ��û����ô��Ļ������鼯��������ֲ������ƣ��� Quick Find �ж� isConnected 
// �㶨��O(1)��ʱ�临�Ӷȣ��кܴ������
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

	
