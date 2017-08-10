//QUESTION
//level order traversal of the BST

void level_order(Node *root){
    queue<Node *> q1, q2;
    
    if (root == NULL)
    return;
    
    q1. push(root);
    
    while(!q1.empty() && !q2.empty()){
        
        while(!q1.empty){
            
            if(q1.front()->left)
                q2.push(q1.front()->left);
            if(q1.front()->right)
                q2.push(q1.front()->right);    
            
            cout << q1.front()->data << " ";
            q1.pop();
        }
        
        while(!q2.empty){
            if(q2.front()->left)
                q1.push(q2.front()->left);
                    
            if(q2.front()->right)
                q1.push(q2.front->right);
        }
    
        cout << q2.front()->data << " ";
            q2.pop();
    }
}
