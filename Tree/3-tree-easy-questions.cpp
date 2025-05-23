#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left = NULL;
    Node *right = NULL;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right= NULL;
    }
};

Node *buildTree(Node* root) {
    cout<<"Enter the root Element: "<<endl;
    int data;
    cin>>data;

    root = new Node(data);

    if(data == -1) {
        return NULL;
    }

    cout<< "Enter left element for "<< data<< endl;
    root->left = buildTree(root->left);
    cout<<"Enter right element for "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

//HEIGHT OF TREE
int treeHeight(Node *root) {
    if(root == NULL) {
        return -1;
    }

    int left = treeHeight(root->left);
    int right = treeHeight(root->right);

    int ans = max(left, right) + 1;
    return ans;
}

//DIAMETER OF TREE

//Approach 1
// Uses height and the diameter both functions complexity -> O(n^2);
int diameter(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = treeHeight(root->left) + treeHeight(root->right) + 1;
    
    int ans = max(op1, max(op2, op3));
    return ans;
}

//Approach 2

//Count Leaf
//Leaf Sum

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    cout<< treeHeight(root) <<endl;

    cout<<diameter(root);
    return 0;
}