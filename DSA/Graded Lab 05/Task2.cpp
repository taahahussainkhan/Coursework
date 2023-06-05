#include <iostream>
using namespace std;
struct node {
	int key;
	struct node *left, *right;
};
struct node* newNode(int item)
{
	struct node* temp
		= (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}
struct node* insert(struct node* node, int key)
{
	if (node == NULL)
		return newNode(key);
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);
	return node;
}
struct node* minValueNode(struct node* node)
{
	struct node* current = node;
	while (current && current->left != NULL)
		current = current->left;

	return current;
}
struct node* deleteNode(struct node* root, int key)
{
	if (root == NULL)
		return root;
	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	else {

		if (root->left == NULL && root->right == NULL)
			return NULL;

		else if (root->left == NULL) {
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			struct node* temp = root->left;
			free(root);
			return temp;
		}
		struct node* temp = minValueNode(root->right);
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}
int main()
{
	struct node* root = NULL;
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 70);
	root = insert(root, 60);
	root = insert(root, 80);

	cout << "Inorder traversal of the tree \n";
	inorder(root);
	cout << endl << endl;
	cout << "\n\t\tTEST CASES" << endl;
	//1. Delete a value that is not present in a BST
	cout << "===> Deleting a value that is not present in a BST " << endl;
	root = deleteNode(root, 200);
	cout << "Inorder traversal of the modified tree \n";
	cout << endl;
	inorder(root);
	cout << endl;

	// 2. Delete the value present at the root in such a way that:
	// 3. Root has no children
	cout << "===> Root has no children" << endl;
	root = deleteNode(root, 50);
	cout << "Inorder traversal of the modified tree \n";
	cout << endl;
	inorder(root);
	cout << endl;

	// 4. Root has only one leaf child
	cout << "===>Root has only one leaf child" << endl;
	root = insert(root, 50);
	root = deleteNode(root, 30);
	cout << "Inorder traversal of the modified tree \n";
	cout << endl;
	inorder(root);
	cout << endl;
	// 5. Root has only one NON-LEAF child
	cout << "===>Root has only one NON-LEAF child" << endl;
	root = insert(root, 30);
	root = deleteNode(root, 20);
	cout << "Inorder traversal of the modified tree \n";
	cout << endl;
	inorder(root);
	cout << endl;
	// 6. Root has two leaf children
	cout << "===> Root has two leaf children. " << endl;
	root = insert(root, 20);
	root = deleteNode(root, 40);
	cout << "Inorder traversal of the modified tree \n";
	cout << endl;
	inorder(root);
	cout << endl;
	// 7. Root had two NON-LEAF children
	cout << "===> Root had two NON-LEAF children" << endl;
	root = insert(root, 40);
	root = deleteNode(root, 60);
	cout << "Inorder traversal of the modified tree \n";
	cout << endl;
	inorder(root);
	cout << endl;
	


	return 0;
}


