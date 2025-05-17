#include<bits/stdc++.h>
using namespace std;

class Node {
    public: 
        int data;
        Node* left = NULL;
        Node* right = NULL;
    
    Node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* buildTree (Node* root) {
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    root = new Node(data);

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data to insert at left of " << data << endl;
    root -> left = buildTree(root->left);
     cout << "Enter data to insert at right of " << data << endl;
    root -> right = buildTree(root->right);
    return root;
}

int main () {
    Node* root = NULL;

    root = buildTree(root);

    return 0;
}