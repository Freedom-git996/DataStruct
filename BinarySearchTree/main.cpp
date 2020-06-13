#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <queue>
#include "SequenceST.h"
#include "FileOps.h"

using namespace std;

template<typename Key, typename Value>
class BST {
	
private:
	struct Node {
		Key key;
		Value value;
		Node* left;
		Node* right;
		
		Node(Key key, Value value) {
			this->key = key;
			this->value = value;
			this->left = this->right = NULL;
		}
		
		Node(Node* node) {
			this.key = node->key;
			this.value = node->value;
			this.left = node->left;
			this.right = node->right;
		}
	};
	
	Node* root;
	int count;
	
	Node* insert(Node* node, Key key, Value value) {
		
		if(node == NULL) {
			count ++;
			return new Node(key, value);
		}
		
		if(key == node->key) 
			node->value = value;
		else if(key < node->key)
			node->left = insert(node->left, key, value);
		else
			node->right = insert(node->right, key, value);
		
		return node; 
	}
	
	bool contain(Node* node, Key key) {
		
		if(node == NULL)
			return false;
			
		if(key == node->key) 
			return true;
		else if(key < node->key) 
			return contain(node->left, key);
		else 
			return contain(node->right, key);
	}
	
	Value* search(Node* node, Key key) {
		
		if(node == NULL) 
			return NULL;
		
		if(key == node->key)
			return &(node->value);
		else if(key < node->key) 
			return search(node->left, key);
		else
			return search(node->right, key);
	}
	
	void preOrder(Node* node) {
		
		if(node != NULL) {
			cout<<node->key<<endl;
			preOrder(node->left);
			preOrder(node->right);
		}
	}
	
	void inOrder(Node* node) {
		
		if(node != NULL) {
			inOrder(node->left);
			cout<<node->key<<endl;
			inOrder(node->right);
		}
	}
	
	void postOrder(Node* node) {
		
		if(node != NULL) {
			postOrder(node->left);
			postOrder(node->right);
			cout<<node->key<<endl;
		}
	}

	// 采用后序的思路，回收节点空间	
	void destroy(Node* node) {
		
		if(node != NULL) {
			destroy(node->left);
			destroy(node->right);
			
			delete node;
			count --;
		}
	}
	
	// 寻找最小值 
	Node* minimum(Node* node) {
		if(node->left ==NULL)
			return node;
		return minimum(node->left);
	}
	
	// 寻找最大值 
	Node* maximum(Node* node) {  
		if(node->right ==NULL)
			return node;
		return maximum(node->right);
	}
	
	// 移除最小值
	Node* removeMin(Node* node) {
		if(node->left == NULL) {
			Node* rightNode = nodee->right;
			delete node;
			count --;
			return rightNode;
		}
		
		node->left = removeMin(node->left);
		return node;
	} 
	
	// 移除最大值
	Node* removeMax(Node* node) {
		if(node->right == NULL) {
			Node* leftNode = nodee->left;
			delete node;
			count --;
			return leftNode;
		}
		
		node->right = removeMax(node->right);
		return node;
	} 
	
	// 移除指定元素
	Node* remove(Node* node, Key key) {
		if(node == NULL)
			return NULL;
		if(key < node->key) {
			node->left = remove(node->left, key);
			return node;
		}else if(key > node->key) {
			node->right = remove(node->right, key);
			return node;
		}else {
			if(node->left == NULL) {
				Node* rightNode = node->right;
				delete node;
				count --;
				return rightNode;
			} 
			
			if(node->right == NULL) {
				Node* leftNode = node->left;
				delete node;
				count --;
				return leftNode;
			} 
			
			Node* successor = new Node(minimum(node->right));
			count ++;
			
			successor->right = removeMin(node->right);
			successor->left = node->left;
			
			delete node;
			count --;
			
			return successor;
		}
	} 
	
public:
	BST() {
		root = NULL;
		count = 0;
	}
	
	// 析构函数调用 destroy(root); 
	~BST() {
		destroy(root);
	}
	
	int size() {
		return count;
	}
	
	bool isEmpty() {
		return count == 0;
	}
	
	void insert(Key key, Value value) {
		
		root = insert(root, key, value);
	}
	
	bool contain(Key key) {
		
		return contain(root, key);
	}
	
	Value* search(Key key) {
		
		return search(root, key);
	}
	
	// 前序遍历 
	void preOrder() {
		
		preOrder(root);
	}
	
	// 中序遍历 
	void inOrder() {
		
		inOrder(root);
	}
	
	// 后序遍历 
	void postOrder() {
		
		postOrder(root);
	}
	
	// 层序遍历 
	void levelOrder() {
		
		// 使用队列 
		queue<Node*> q;
		q.push(root);
		while(!q.empty()) {
			Node* node = q.front();
			q.pop();
			
			cout<<node->key<<endl;
			
			if(node->left)
				q.push(node->left);
			if(node->right)
				q.push(node->right);
		}
	}
	
	// 返回最小值 
	Key minimum() {
		
		assert(count != 0);
		Node* minNode = minimum(root); 
		return minNode->key;
	} 
	
	// 返回最大值 
	Key maximum() {
		
		assert(count != 0);
		Node* maxNode = maximum(root); 
		return maxNode->key;
	} 
	
	// 移除最小值 
	void removeMin() {
		if(root ) 
			root = removeMin(root);
	}
	
	// 移除最小值 
	void removeMax() {
		if(root ) 
			root = removeMax(root);
	}
	
	// 移除指定元素
	void remove(Key key) {
		root = remove(root, key);
 	}
	 
};                    

int main() {
	BST<int, string> bst = BST<int, string>();
	bst.insert(28, "a");
	bst.insert(16, "b");
	bst.insert(30, "c");
	bst.insert(13, "d");
	bst.insert(22, "e");
	bst.insert(29, "f");
	bst.insert(42, "g");
	
	cout<<"######### 前序遍历 #########"<<endl;
	bst.preOrder();
	cout<<endl;
	
	cout<<"######### 中序遍历 #########"<<endl;
	bst.inOrder();
	cout<<endl;
	
	cout<<"######### 后序遍历 #########"<<endl;
	bst.postOrder();
	cout<<endl;
	
	cout<<"######### 层序遍历 #########"<<endl;
	bst.levelOrder();
	cout<<endl;
	
	// 使用圣经作为我们的测试用例
    string filename = "bible.txt";
    vector<string> words;
    if( FileOps::readFile(filename, words) ) {

        cout << "There are totally " << words.size() << " words in " << filename << endl;
        cout << endl;


        // 测试 BST
        time_t startTime = clock();

        // 统计圣经中所有词的词频
        // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
        // 在这里只做性能测试用
        BST<string, int> bst = BST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = bst.search(*iter);
            if (res == NULL)
                bst.insert(*iter, 1);
            else
                (*res)++;
        }

        // 输出圣经中god一词出现的频率
        if(bst.contain("god"))
            cout << "'god' : " << *bst.search("god") << endl;
        else
            cout << "No word 'god' in " << filename << endl;

        time_t endTime = clock();

        cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;


        // 测试顺序查找表 SST
        startTime = clock();

        // 统计圣经中所有词的词频
        // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
        // 在这里只做性能测试用
        SequenceST<string, int> sst = SequenceST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = sst.search(*iter);
            if (res == NULL)
                sst.insert(*iter, 1);
            else
                (*res)++;
        }

        // 输出圣经中god一词出现的频率
        if(sst.contain("god"))
            cout << "'god' : " << *sst.search("god") << endl;
        else
            cout << "No word 'god' in " << filename << endl;

        endTime = clock();

        cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
    }

    return 0;
}
