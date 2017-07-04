#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node(){
		data = 0;
		next = NULL;
	}
};

class l_list{
	Node* head;

public:
	l_list();
	void Add(int data);
	void Remove();

};

l_list::l_list()
:head(NULL){}

void l_list::Add(int data){
	Node* ptr = new Node;
	ptr->data = data;
	ptr->next = head;
	head = ptr;
}

Node* sorted_merge(Node* head1, Node* head2){
	if(head1==NULL)
		return head2;
	if(head2==NULL)
		return head1;

	Node* head_r;

	if(head1->data > head2->data){
		head_r = head2;
		head2 = head2->next;
	}
	else {
		head_r = head1;
		head1 = head1->next;
	}

	Node* itr = head_r;

	while(head1 && head2){
		if(head1->data < head2->data){
			itr->next = head1;
			head1 = head1->next;
		}
		else{
			itr->next = head2;
			head2 = head2->next;
		}
	itr = itr->next;	
	}

	while(head1){
		itr->next = head1;
		head1 = head1->next;
		itr = itr->next;
	}
	while(head2){
		itr->next = head2;
		head2 = head2->next;
		itr = itr->next;
	}
return head_r;
}