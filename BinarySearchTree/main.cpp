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

	// ���ú����˼·�����սڵ�ռ�	
	void destroy(Node* node) {
		
		if(node != NULL) {
			destroy(node->left);
			destroy(node->right);
			
			delete node;
			count --;
		}
	}
	
	// Ѱ����Сֵ 
	Node* minimum(Node* node) {
		if(node->left ==NULL)
			return node;
		return minimum(node->left);
	}
	
	// Ѱ�����ֵ 
	Node* maximum(Node* node) {  
		if(node->right ==NULL)
			return node;
		return maximum(node->right);
	}
	
	// �Ƴ���Сֵ
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
	
	// �Ƴ����ֵ
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
	
	// �Ƴ�ָ��Ԫ��
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
	
	// ������������ destroy(root); 
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
	
	// ǰ����� 
	void preOrder() {
		
		preOrder(root);
	}
	
	// ������� 
	void inOrder() {
		
		inOrder(root);
	}
	
	// ������� 
	void postOrder() {
		
		postOrder(root);
	}
	
	// ������� 
	void levelOrder() {
		
		// ʹ�ö��� 
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
	
	// ������Сֵ 
	Key minimum() {
		
		assert(count != 0);
		Node* minNode = minimum(root); 
		return minNode->key;
	} 
	
	// �������ֵ 
	Key maximum() {
		
		assert(count != 0);
		Node* maxNode = maximum(root); 
		return maxNode->key;
	} 
	
	// �Ƴ���Сֵ 
	void removeMin() {
		if(root ) 
			root = removeMin(root);
	}
	
	// �Ƴ���Сֵ 
	void removeMax() {
		if(root ) 
			root = removeMax(root);
	}
	
	// �Ƴ�ָ��Ԫ��
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
	
	cout<<"######### ǰ����� #########"<<endl;
	bst.preOrder();
	cout<<endl;
	
	cout<<"######### ������� #########"<<endl;
	bst.inOrder();
	cout<<endl;
	
	cout<<"######### ������� #########"<<endl;
	bst.postOrder();
	cout<<endl;
	
	cout<<"######### ������� #########"<<endl;
	bst.levelOrder();
	cout<<endl;
	
	// ʹ��ʥ����Ϊ���ǵĲ�������
    string filename = "bible.txt";
    vector<string> words;
    if( FileOps::readFile(filename, words) ) {

        cout << "There are totally " << words.size() << " words in " << filename << endl;
        cout << endl;


        // ���� BST
        time_t startTime = clock();

        // ͳ��ʥ�������дʵĴ�Ƶ
        // ע: �����Ƶͳ�Ʒ���Լ�ª, û�п��Ǻܶ��ı������е���������
        // ������ֻ�����ܲ�����
        BST<string, int> bst = BST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = bst.search(*iter);
            if (res == NULL)
                bst.insert(*iter, 1);
            else
                (*res)++;
        }

        // ���ʥ����godһ�ʳ��ֵ�Ƶ��
        if(bst.contain("god"))
            cout << "'god' : " << *bst.search("god") << endl;
        else
            cout << "No word 'god' in " << filename << endl;

        time_t endTime = clock();

        cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;


        // ����˳����ұ� SST
        startTime = clock();

        // ͳ��ʥ�������дʵĴ�Ƶ
        // ע: �����Ƶͳ�Ʒ���Լ�ª, û�п��Ǻܶ��ı������е���������
        // ������ֻ�����ܲ�����
        SequenceST<string, int> sst = SequenceST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = sst.search(*iter);
            if (res == NULL)
                sst.insert(*iter, 1);
            else
                (*res)++;
        }

        // ���ʥ����godһ�ʳ��ֵ�Ƶ��
        if(sst.contain("god"))
            cout << "'god' : " << *sst.search("god") << endl;
        else
            cout << "No word 'god' in " << filename << endl;

        endTime = clock();

        cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
    }

    return 0;
}
