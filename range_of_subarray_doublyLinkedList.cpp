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
    Dnode* header;
    Dnode* trailer;
};

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




class LinkedDeque{
public:
	//LinkedDeque();
	bool empty();
	int front();
	int back();
	void insertfront(int a);
	void insertback(int a);
	void removefront();
	void removeback();
	DLinkedList D;

};



void LinkedDeque::insertfront(int a){
	D.addfront(a);
}

void LinkedDeque::insertback(int a){
	D.addback(a);
}

void LinkedDeque::removefront(){
	if(empty())
		cout<<"empty deque"<<endl;
	D.removefront();
}

void LinkedDeque::removeback(){
	if(empty())
		cout<<"empty deque"<<endl;
	D.removeback();
}

int LinkedDeque::front(){
	return D.front();
}

int LinkedDeque::back(){
	return D.back();
}

bool LinkedDeque::empty(){
	return D.empty();
}

int main(){
    int n=18;
	int input[18]={1,2,6,4,8,4,0,6,2,5,8,9,4,6,8,9,5,4};
    LinkedDeque q1;
    int k=4,i;
    cout<<"max: ";
    for(i=0;i<k;i++){

        while(!q1.empty() && input[i]>=input[q1.back()])
            q1.removeback();
            q1.insertback(i);

    }
    for(;i<n;i++){
        cout<<input[q1.front()]<<" ";
         while ( (!q1.empty()) && q1.front()<=i-k)
            q1.removefront();

        while((!q1.empty()) && input[i]>= input[q1.back()])
            q1.removeback();
        q1.insertback(i);
    }
 cout<<input[q1.front()]<<endl;

 cout<<"min: ";
 for(i=0;i<k;i++){

        while(!q1.empty() && input[i]<=input[q1.back()])
            q1.removeback();
            q1.insertback(i);

    }
    for(;i<n;i++){
        cout<<input[q1.front()]<<" ";
         while ( (!q1.empty()) && q1.front()<=i-k)
            q1.removefront();

        while((!q1.empty()) && input[i]<= input[q1.back()])
            q1.removeback();
        q1.insertback(i);
    }
 cout<<input[q1.front()];
return 0;
}

