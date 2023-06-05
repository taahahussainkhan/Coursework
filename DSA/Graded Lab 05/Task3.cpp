#include <iostream>
using namespace std;
class BST {
	int data;
	BST* left;
	BST* right;
public:
	BST()
	{
		data = 0;
		right = NULL;
		left = NULL;
	}
	// constructor
	BST(int d)
	{
		data = d;
		right = NULL;
		left = NULL;
	}

	BST* Insert(BST* root, int d)
	{
		if (root == NULL)
		{
			return new BST(d);
		}

		if (d > root->data)
		{
			root->right = Insert(root->right, d);
		}
		else if (d < root->data)
		{
			root->left = Insert(root->left, d);
		}
		return root;
	}


	void Inorder(BST* root)
	{
		if (!root)
		{
			return;
		}
		Inorder(root->left);
		cout << root->data << ", ";
		Inorder(root->right);
	}

	void Preorder(BST* root)
	{
		if (!root)
		{
			return;
		}
		cout << root->data << ", ";
		Preorder(root->left);
		Preorder(root->right);
	}

	void Postorder(BST* root)
	{
		if (!root)
		{
			return;
		}
		Postorder(root->left);
		Postorder(root->right);
		cout << root->data << ", ";
	}

	bool search(BST* root, int key)
	{
		if (root == NULL)
		{
			return false;
		}

		if (root->data == key)
		{
			return true;
		}

		if (key > root->data)
		{
			return search(root->right, key);
		}
		else
		{
			return search(root->left, key);
		}

		return false;
	}
	~BST()
	{
		if (left != NULL)
			delete left;
		if (right != NULL)
			delete right;
	}
};



int main()
{
	BST b, *test = NULL;
	test = b.Insert(test, 50);
	b.Insert(test, 30);
	b.Insert(test, 20);
	b.Insert(test, 40);
	b.Insert(test, 70);
	b.Insert(test, 60);
	b.Insert(test, 80);

	cout << "\n\nIn order traversal: \n";
	b.Inorder(test);

	cout << "\n\nPre order traversal: \n";
	b.Preorder(test);

	cout << "\n\nPost order traversal: \n";
	b.Postorder(test);

	delete test;
	cout << "\n\nBST DELETED!!!! : " << endl;

	return 0;
}

