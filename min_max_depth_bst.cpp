#inlude <bits/stdc++.h>
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
  int min_depth(Node* root);
};
//both the function computes the min depth of the tree
int BST::min_depth(Node* root){

  if( root == NULL)
    return 0;
  if( !root->right && !root->left)
    return 1;
  if( !root->left)
    return min_depth(root->right) + 1;
  if( !root->right)
    return min_depth(root->left) + 1;

  return min(min_depth(left->root), min_depth(right->root)) + 1;
}


int BST::min_height(Node *root)
{
    // Base Case
    if (root == NULL)
        return 0;

    // Create an empty queue for level order tarversal
    queue<qItem> q;

    // Enqueue Root and initialize height
    qItem qi = {root, 1};
    q.push(qi);

    while (q.empty() == false)
    {
       qi = q.front();
       Node *n = qi.n;
       int depth = qi.depth;
       q.pop();
       if (n->left == NULL && n->right == NULL)
          return qi.depth;
       if (n->left != NULL)
       {
          qi.n = n->left;
          qi.depth = depth+1;
          q.push(qi);
       }
       if (n->right != NULL)
       {
          qi.n = n->right;
          qi.depth = depth+1;
          q.push(qi);
       }
    }

    return 0;
}

//computes the height or max height of BST
int BST::height(Node* root){
	int h=0;
	if(temp!=NULL){
		int Left_height= height(temp->Left_child);
		int Right_height= height(temp->Right_child);
		int max_height= max(Left_height,Right_height);
		h=max_height+1;

	}
	return h;
}
