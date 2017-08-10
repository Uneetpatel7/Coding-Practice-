#include <bits/stdc++.h>
using namespace std;

Class Node
{
public:
  int data;
  Node *right, *left;
};

class BST
{
private:
  Node* root;
public:
  Node(){
    root = NULL;
  }
  Node* insert(Node *root, int value);
  bool isBST (Node* root);
};

Node* BST::insert(Node *root, int value){
    if (root==NULL){
        root = new Node;
        root->data = value;
        root->right = NULL;
        root->left = NULL;
        return root;
    }
    
    else if (value < root->data) {
        insert (root->left , value);
    }
    
    else if (value > root->data) {
        insert (root->right , value);
    }
    
    else if (value = root->data) {
        root->data = value;
    }

    return root;
}

bool BST::checkBST(Node* root, int min, int max){
    if (!root)
    return true;
    if (!root->data > min || !root->data < max)
    return false;
    if(checkBST(root->left, min, root->data) && checkBST(root->left, root->data, max))
    return true;
    else 
    return false;
    
}

bool BST::isBST (Node* root){
    return checkBST(root, INT_MIN, INT_MAX);
    
}

