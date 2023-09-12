
#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;

    Node(int k)
    {
        key = k;
        left = NULL;
        right = NULL;
    }
};

int tree_height(Node* root) {
    // Get the height of the tree
    if (!root)
        return 0;
    else 
    {
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

void printLevel(Node* root, int level, bool leftToRight) {
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->key << " ";
    else if (level > 1) {
        if (leftToRight) {
            printLevel(root->right, level - 1, leftToRight);
            printLevel(root->left, level - 1, leftToRight);
        } else {
            printLevel(root->left, level - 1, leftToRight);
            printLevel(root->right, level - 1, leftToRight);
        }
    }
}

void spiral_trav(Node* root)
{
    int height = tree_height(root);
    bool leftToRight = true;
    for (int i = 1; i <= height; i++) {
        printLevel(root, i, leftToRight);
        leftToRight = !leftToRight;
    }
}

int main()
{
    Node *root = new Node(100);
    root->right = new Node(110);
    root->left = new Node(70);
    root->left->left = new Node(65); 
	  root->left->left->right = new Node(68); 
	  root->left->left->left = new Node(60); 
    root->left->right = new Node(90); 
    root->right->left = new Node(105); 
    root->right->right = new Node(120); 
	  root->right->right->right = new Node(125); 
	  root->right->right->left = new Node(115); 
	  root->left->right->right = new Node(95); 
	  root->left->right->left = new Node(85); 

    spiral_trav(root);
    return 0;
}


