#include <iostream>
using namespace std;
template <typename T>
struct Node {
	T data;
	Node* left;
	Node* right;
};
template <typename T>
class BST {
public:
	Node<T>* root;
	BST() {
		root = nullptr;
	}
	void insertRec(Node<T>*& p, Node<T>* newNode) {
		if (p == nullptr) {
			p = newNode;
			return;
		}
		if (newNode->data < p->data) {
			insertRec(p->left, newNode);
		}
		else {
			insertRec(p->right, newNode);
		}
	}
	void postorder(Node<T>* p) {
		if (p == nullptr) {
			return;
		}
		postorder(p->left);
		postorder(p->right);
		cout << p->data << " ";
	}
	void INSERT(T d) {
		Node<T>* newNode = new Node<T>{ d, NULL, NULL };
		insertRec(root, newNode);
	}
};
int main() {
	BST<int> tree;
	tree.INSERT(100);
	tree.INSERT(50);
	tree.INSERT(75);
	tree.INSERT(25);
	tree.INSERT(55);
	tree.INSERT(150);
	cout << "Postorder Traversal is: " << endl;
	tree.postorder(tree.root);
	cout << endl;
	return 0;
}