
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void deleteFirst(struct Node **head_ref)
{
	if(*head_ref != NULL)
	{
	// store the old value of pointer to head pointer
	struct Node *temp = *head_ref;

	// Change head pointer to point to next node
	*head_ref = (*head_ref)->next;

	// delete memory allocated for the previous head node
	free(temp);
	}
}

int main(){
    Node *root = new Node();
    root->data = 1;
    root->next = NULL;
    Node *x = new Node();
    x->data = 2;
    root->next = x;
    x->next = NULL;
    
    x=root;
    while(x!=NULL){
        cout<<x->data<<" ";
        x = x->next;
    }
    cout<<endl;

    deleteFirst(&root);

    x=root;
    while(x!=NULL){
        cout<<x->data<<" ";
        x = x->next;
    }
    
    return 0;
}
