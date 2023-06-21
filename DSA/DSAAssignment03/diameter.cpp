#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
int diameter(node *root, int *height);
int main() {
    node* root = new node(1);
    root->left = new node(4);
    root->left->left = new node(2);
    root->left->right = new node(5);
    root->left->right->left = new node(6);
    root->right = new node(3);
    root->right->right = new node(8);
    root->right->right->left = new node(7);
    root->right->right->left->left = new node(0);
    root->right->right->left->right = new node(9);
    int h = 0;
    cout << "Diameter of the tree is: ";
    cout << diameter(root, &h);
    return 0;
}
int diameter(node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int left_height = 0, right_height = 0;
    int left_diameter = diameter(root->left, &left_height);
    int right_diameter = diameter(root->right, &right_height);
    int curr_diameter = left_height + right_height + 1;
    *height = max(left_height, right_height) + 1;

    return max(curr_diameter, max(left_diameter, right_diameter));
}