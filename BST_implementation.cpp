/*Read a randomly ordered sequence of integers and store them in a doubly linked list. 
Use in-place insertion sort to sort the elements of the linked list. 
Now convert this list into a binary search tree with minimum height possible. 
Write another program to test whether a given tree is BST or not. 
Use this program to test the correctness of your previous program, 
i.e., whether or not the binary tree you have constructed is a BST.
*/


#include<iostream>
#include<vector>
#include<fstream>
#include<stdexcept>
#include<cstdlib>

using namespace std;

class Dnode{
public:
    int x;
    Dnode* prev;
    Dnode* next;
    friend class DLinkedList;

};

class DLinkedList{
	public:
    DLinkedList();
    ~DLinkedList();
    bool empty();
    int front();
    int back();
    void addfront(int a);
    void addback(int a);
    void removefront();
    void removeback();
    void add(Dnode* v,int a);
    void remove(Dnode* v);
    void printlist();
    Dnode* header;
    Dnode* trailer;
};

void DLinkedList::printlist(){
Dnode* temp=header;
while(temp->next!=trailer){
cout<<temp->next->x;
temp=temp->next;}

}

DLinkedList::DLinkedList(){
	header=new Dnode;
	trailer=new Dnode;
	header->next=trailer;
	trailer->prev=header;
}

DLinkedList::~DLinkedList(){
	while (!empty()) removefront();
	delete header;
	delete trailer;
}

bool DLinkedList::empty(){
	return (header->next==trailer);
}

int DLinkedList::front(){
	return header->next->x;
}

int DLinkedList::back(){
	return trailer->prev->x;
}

void DLinkedList::add(Dnode*v,int a){
    Dnode* u =new Dnode;
    u->x=a;
    u->next=v;
    u->prev=v->prev;
    v->prev->next=v->prev=u;
}
void DLinkedList::addfront(int a){
	add(header->next,a);

}

void DLinkedList::addback(int a){
	add(trailer,a);
}

void DLinkedList::remove(Dnode *v){
	Dnode*u=v->prev;
	Dnode*w=v->next;
	u->next=w;
	w->prev=u;
	delete v;
}

void DLinkedList::removefront(){
	remove(header->next);
}

void DLinkedList::removeback(){
remove(trailer->prev);
}



class BSTree
{
    public:
        BSTree();
        ~BSTree();
        BSTree* CreateBST(int arr[],int,int);
        void TravelTree(BSTree*);
        void PrintValue();
        int CheckBST(BSTree*);
        int LeftTreeLess(BSTree*,int);
        int RightTreeGreater(BSTree*,int);
    private:
        BSTree *LeftChild;
        BSTree *RightChild;
        int Value;
};

BSTree::BSTree()
{
    LeftChild = NULL;
    RightChild = NULL;
    Value = -1;
}

BSTree::~BSTree()
{
    //dtor
}
BSTree* BSTree::CreateBST(int a[],int Start,int End){
    BSTree *Root = new BSTree;

    int RootPosition = (End - Start + 1)/2 + Start;    

    if(End<Start){return NULL;}                        
    if(End == Start){Root->Value = a[RootPosition];return Root;} 

    int LchildPosition = (RootPosition-Start)/2 + Start;        
    int RchildPosition = (End-RootPosition+2)/2 + RootPosition; 

   
    Root->Value = a[RootPosition];
  

    Root->LeftChild = CreateBST(a,Start,RootPosition-1);      
    Root->RightChild = CreateBST(a,RootPosition+1,End);
    return Root;

    
}

void BSTree::TravelTree(BSTree* Root){
    if(Root == NULL){return;}
    TravelTree(Root->LeftChild);
    cout<<"Value = "<<Root->Value<<" ";
    TravelTree(Root->RightChild);
}

void BSTree::PrintValue(){
    cout<<this->Value<<endl;
}



int main(){
	DLinkedList l1;
	int var;

	ifstream sample;
	sample.open("input.txt");
	while(!sample.eof()){
          sample>>var;
          if(!sample){
          	break;
          }
          if(l1.empty()){
          l1.addfront(var);

            continue;
          }
          if(l1.header->next->x >= var){
          	l1.add(l1.header->next,var);


          }
          else{
          	 Dnode *current = l1.header;
       while(current->next != l1.trailer && current->next->x < var) {
           current = current->next;
       }
           l1.add(current->next,var);
          }


}
l1.printlist();
cout<<"\n";

int i=0,arr[30];
Dnode* temp=l1.header;
while(temp->next!=l1.trailer){
	arr[i]=temp->next->x;
	i++;
	temp=temp->next;
}
cout<<i<<endl;

BSTree t1;
BSTree *ptr=t1.CreateBST(arr,0,i-1);
t1.TravelTree(ptr);

return 0;
}

