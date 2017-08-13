/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/*this  function serializes 
the binary tree and stores 
it in the vector A*/
#include <bits/stdc++.h>
void serialize(Node *root,vector<int> &A)
{
    if (root == NULL){
        A.push_back(-1);
    }
    
    A.push_back(root->data);
    serialize(root->left, A);
    serialize(root->right, A);
}
/*this function deserializes
 the serialized vector A*/
Node * deSerialize(vector<int> &A)
{
    int extract = A.front(); 
    if (!A.empty()){
    A.erase(A.begin());}
    if( A.empty() || extract == -1)
    {
        return NULL;
    }
    
    Node *root = new Node();
    root->data = extract;
    root->left = root->right = NULL;
    root->left = deSerialize(A);
    root->right = deSerialize(A);
    
    return root;
}
