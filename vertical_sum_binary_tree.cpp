// Vertical sum of the levels of the binary tree geeksforgeeks.

/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/
void calculateVerticalSum(Node *node, int hd, map<int,int> &Map){
       
    if (node==NULL)
    return;
    calculateVerticalSum(node->left, hd-1, Map);
    Map[hd] += node->data;
    calculateVerticalSum(node->right, hd+1, Map);
}

void printVertical(Node *root)
{
map<int,int> Map;
map<int,int> :: iterator itr;
calculateVerticalSum(root, 0 , Map);
for (itr = Map.begin(); itr!= Map.end(); ++itr ){
    
    cout << itr->second<< " " ;
}
}
