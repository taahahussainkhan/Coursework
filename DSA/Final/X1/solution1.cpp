#include<iostream>
using namespace std;
class Node{
    public:
    Node* left;
    Node* right;
    int itemCode;
    Node(int itemCode){
        this->itemCode = itemCode;
        left = NULL;
        right = NULL;
    }
};
class Inventory{
    private:
    Node* root;
    public:
    Inventory(){
        root = NULL;
    }
    Node* insertItem(Node* root,int itemCode)
    {
        if(root == NULL)
        {
            root = new Node(itemCode);
            return root;
        }
        else if(itemCode < root->itemCode)
        {
            root->left = insertItem(root->left,itemCode);
        }
        else if(itemCode > root->itemCode)
        {
            root->right = insertItem(root->right,itemCode);
        }
    }
};
int main()
{

}