/*
BUILD A BINARY TREE GIVEN PRE AND INORDER TRAVERSAL
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
Node* buildTree(int in[],int pre[], int inStrt, int inEnd)
{
      static int preIndex=0;
      int inIndex=0;
      if (inStrt > inEnd){
          return Node;
      }
      
      Node* tNode = newnode(pre[preindex]);
      preindex++;
    
      if(inStrt == inEnd)
        return tNode;
      
      inIndex = search (in, inStrt, inEnd, root->data);
      
      tNode->left = biuldTree(in, pre, inStrt, inIndex-1);
      tNode->right = biuldTree(in, pre, inStrt, inIndex+1);

      return tNode;    
}

int search(char arr[], int strt, int end, char value)
{
  int i;
  for(i = strt; i <= end; i++)
  {
    if(arr[i] == value)
      return i;
  }
}
 
Node* newNode(char data)
{
  Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
} 
