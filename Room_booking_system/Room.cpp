#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<cmath>

using namespace std;


class Rnode{        //Room node 
public:
    string name;
	float area;
	int no_of_doors;
	int x;
	int y;
	int status;        // booking status (0 if unbooked and 1 if booked)
    Rnode* next;       // next pointer of the node

friend class RoomLinkedList;    // just for safety
};

class RoomLinkedList{
	public:
	Rnode* headr;         // head pointer to room linked list
	RoomLinkedList();
//	~RoomLinkedList();
	void Add_Front(string &e,float f,int a,int b,int c,int d); // add the node in front
	void Remove(string &e);          //removes the desired node
    void PrintList();                                          // print the whole data in the list
    void BookRoom(string &e);                                  // books the desired room
    void UnbookRoom(string &e);                                // unbooks desired room
    void PrintDetails(string &e); 
    void Nearest_Room(int x,int y);
    void MinRooms(int x);
};


RoomLinkedList::RoomLinkedList()             // constructor
:headr(NULL){}


void RoomLinkedList::MinRooms(int x){
	Rnode *temp=headr;
	int y=0;
	float rooms_arr[1000];
	while(temp!=NULL)
	{
		rooms_arr[y] = temp->area;
		y++;
		temp=temp->next;
	}
	sort(rooms_arr,rooms_arr+y);
	int i;
	int counter;
	counter=0;
	//temp=headr;
	for(i=y-1;i>=0 && x>0;i--)
	{
         x=x-(int)(rooms_arr[i]/30);
         //temp=temp->next;
         counter++;
	}
	if(i==-1 && x>0)
	{
		cout<<"Rooms don't have enough space"<<endl;
	}
	else
    cout<<"Minimum number of rooms required are : "<<counter<<endl;
}

void RoomLinkedList::PrintDetails(string &e){
	Rnode *ptr=headr;
	int flag=0;
	while(ptr!=NULL){       // traversing through the loop
		if(ptr->name==e){
			flag=1;
			break;
		}
		//else{
	ptr=ptr->next;
	}
	 if ((flag==1)){            //booking conditions
	cout<<ptr->name<<"\t"<<ptr->area<<"\t"<<ptr->no_of_doors<<"\t"<<ptr->x<<"\t"<<ptr->y<<"\t"<<ptr->status<<endl;
}
 else{
	cout<<"room not found\n";
}
}

void RoomLinkedList::Nearest_Room(int x,int y){
	float smt=999.0;
	Rnode* ptr= headr;
   string nme="";
	while(ptr!=NULL){
		float diff=sqrt((((ptr->x)-x)*((ptr->x)-x))+(((ptr->y)-y)*((ptr->y)-y)));
		if(smt>diff)
		{
			smt=diff;
			nme=ptr->name;

		}
		ptr=ptr->next;
	}
	cout<<"Nearest_Room IS "<<nme<<endl;
		
}


void RoomLinkedList::BookRoom(string &e){
	Rnode *ptr=headr;
	int flag=0;
	while(ptr!=NULL){       // traversing through the loop
		if(ptr->name==e){
			flag=1;
			break;
		}
		else{
	ptr=ptr->next;
	}
}
 if ((flag==1) && (ptr->status!=1)){            //booking conditions
	ptr->status=1;
	cout<<"Room Booked\n";
}
 else{
	cout<<"room cannot be booked\n";
}
}
//RoomLinkedList::~RoomLinkedList(){
//	Remove( &e,f,a,b, c);
//}
void RoomLinkedList::PrintList(){
	Rnode*ptr=headr;
	while (ptr!=NULL){                         //print the whole file till eof is reached
	cout<<ptr->name<<"\t"<<ptr->area<<"\t "<<ptr->no_of_doors<<"\t"<<ptr->x<<"\t"<<ptr->y<<"\t"<<ptr->status<<endl;
	ptr=ptr->next;
}
}
void RoomLinkedList::UnbookRoom(string &e){
	Rnode *ptr=headr;
	int flag=0;
	while(ptr!=NULL){                          // reach to the desired location
		if(ptr->name==e){
			flag=1;
			break;
		}
	else{
		ptr=ptr->next;
	}
}
 if ((flag==1) && (ptr->status!=0)){
	ptr->status=0;      
	cout<<"Room unbooked\n";                      // if booked then change the status
}
 else{
	cout<<"room is already unbooked\n";
}
}


void RoomLinkedList::Add_Front( string &e,float f,int a,int b,int c,int d){
	Rnode* ptr= new Rnode;
	ptr->name=e;
	ptr->area=f;
	ptr->no_of_doors=a;
	ptr->x=b;
	ptr->y=c;
	ptr->status=d;
    ptr->next=headr;                          // ptr becomes head 
    headr=ptr;
    //cout<<"Room added\n";
}
void RoomLinkedList::Remove(string &e){
                                                                                              // case 1 empty list
if (headr==NULL){
	cout<< "room cannot be deleted from an empty linked list"<<endl;
}  	

else
 {      //if not empty
	Rnode* curr=headr;
	Rnode* trail=NULL;
	while (curr!=NULL){                                                                      // traverse through the loop     
		if ((curr->name==e))//&&(curr->area==f) &&(curr->no_of_doors==a)&& (curr->x==b) &&(curr->y==c))
		{
			break;                                                                  
		}
			trail=curr;
			curr=curr->next;
		
	}
	if (curr==NULL){                                                                         // if desired node not found
		cout<<"required room "<< e<<"not found"<<endl;           
	}
	else{
		if (headr==curr){                                                                   // deletion on head
			headr=headr->next;
		}
		else{

			trail->next=curr->next;                                                        // deletion other than head
		}
		delete curr;
	}
}
cout<<"Room deleted\n";
}	

class Lnode: public Rnode{
public:

	int no_of_computers;
	friend class LabLinkedList;
    Lnode* next; 
};

class LabLinkedList{
public:
	Lnode* head;

	LabLinkedList();
	void Add_Front(string &e,float f,int a,int b,int c,int d,int g);
	void Remove(string &e);
    void printList();
    void BookLab(string &e);
    void UnbookLab(string &e);
    float Least_Density();
    void Add_computers(string &e, int a);
    void PrintDetails (string &e);
};
LabLinkedList::LabLinkedList()
:head(NULL){}

void LabLinkedList::PrintDetails(string &e){
	Lnode *ptr=head;
	int flag=0;
	while(ptr!=NULL){       // traversing through the loop
		if(ptr->name==e){
			flag=1;
			break;
		}
		
	ptr=ptr->next;
	}
	 if ((flag==1)){            //booking conditions
	cout<<ptr->name<<"\t"<<ptr->area<<"\t"<<ptr->no_of_doors<<"\t"<<ptr->x<<"\t"<<ptr->y<<"\t"<<ptr->no_of_computers<<endl;
}
 else{
	cout<<"lab not found\n";
}
}


float LabLinkedList::Least_Density(){
	Lnode* temp=head;
	float density[150];
	int i;
	i=0;
	while (temp!=NULL ){
      //density[i]=temp->no_of_computers;
      density[i]=(temp->no_of_computers)/(temp->area);
	temp =temp->next;
	i=i+1;
	}
	sort(density,density+i);
return density[0];
}

void LabLinkedList::Add_computers(string &e, int a){
	Lnode*temp=head;
	while (temp!=0){
		if (temp->name==e){
			break;
		}
		else{
			temp=temp->next;
		}
	}
		if ((temp!=0) && (temp->name==e)){
			temp->no_of_computers=temp->no_of_computers+a;
		    cout<<"Computers added\n";
		}
		else{
			cout<<"operation cant be performed\n";
		}

	


}

void LabLinkedList::Add_Front( string &e,float f,int a,int b,int c,int d,int g){
	Lnode* ptr= new Lnode;
	ptr->name=e;
	ptr->area=f;
	ptr->no_of_doors=a;
	ptr->x=b;
	ptr->y=c;
	ptr->no_of_computers=d;
	ptr->status=g;
    ptr->next=head;
    head=ptr;
    //cout<<"Lab added\n";
}
void LabLinkedList::Remove(string &e){
// case 1 empty list
if (head==NULL){
	cout<< "room cannot be deleted from an empty linked list"<<endl;
}  	
else {
	Lnode* curr=head;
	Lnode* trail=NULL;
	while (curr!=0){
		if ((curr->name==e))//&&(curr->area==f) &&(curr->no_of_doors==a)&& (curr->x==b) &&(curr->y==c)&& (curr->no_of_computers==d))
		{
			break;
		}
		else{
			trail=curr;
			curr=curr->next;
		}
	}
	if (curr==0){
		cout<<"required room "<< curr->name<<"not found"<<endl; 
	}
	else{
		if (head==curr){
			head=head->next;
		}
		else{

			trail->next=curr->next;
		}
		delete curr;
	}
}	
cout<<"Lab removed";
}


void LabLinkedList::BookLab(string &e){
	Lnode *ptr=head;
	while(ptr!=NULL){
		if(ptr->name==e){
			break;
		}
		else{
	ptr=ptr->next;
	}
}
 if ((ptr!=0) && (ptr->status!=1)){
	ptr->status=1;
	cout<<"Lab booked\n";
}
 else{
	cout<<"Lab cannot be booked\n";
}
}
void LabLinkedList::printList(){
	Lnode*ptr=head;
	while (ptr!=NULL){
	cout<<ptr->name<<"\t"<<ptr->area<<"\t "<<ptr->no_of_doors<<"\t"<<ptr->x<<"\t"<<ptr->y<<"\t"<<ptr->no_of_computers<<"\t"<<ptr->status<<endl;
	ptr=ptr->next;
}
}

void LabLinkedList::UnbookLab(string &e){
	Lnode *ptr=head;
	while(ptr!=NULL){
		if(ptr->name==e){
			break;
		}
	else{
		ptr=ptr->next;
	}
}
 if ((ptr!=0) && (ptr->status!=0)){
	ptr->status=0;
    cout<<"lab unbooked\n"; 
}
 else{
	cout<<"Lab is already unbooked\n";
}
}



class LCnode:public Rnode{
public:

	int no_of_chairs;
	friend class LecLinkedList;
    LCnode* next; 
};

class LecLinkedList{
public:
	LCnode* headl;

	LecLinkedList();
	void Add_Front(string &e,float f,int a,int b,int c,int d,int g);
	void Remove(string &e);
    void printList();
    void BookLec(string &e);
    void UnbookLec(string &e);
    void PrintDetails(string &e);
    void Smallest_lec(int x);

};
LecLinkedList::LecLinkedList()
:headl(NULL){}


void LecLinkedList::Smallest_lec(int x){
    LCnode* temp=headl;
	float density[150];
	int i,k;
	i=0;
	while (temp!=NULL ){
      //density[i]=temp->no_of_computers;
      density[i]=(temp->no_of_chairs);
	temp =temp->next;
	i=i+1;
	}
	sort(density,density+i);
    k=0;
    while(x>=density[k]){
    	k=k+1;
    }
    cout<<"smallest ecture hall of availabe size is:"<<density[k]<<endl;


}


void LecLinkedList::PrintDetails(string &e){
	LCnode *ptr=headl;
	int flag=0;
	while(ptr!=NULL){       // traversing through the loop
		if(ptr->name==e){
			flag=1;
			break;
		}
	
	ptr=ptr->next;
	}

	 if ((flag==1)){            //booking conditions
	cout<<ptr->name<<"\t"<<ptr->area<<"\t"<<ptr->no_of_doors<<"\t"<<ptr->x<<"\t"<<ptr->y<<"\t"<<ptr->no_of_chairs<<endl;
}
 else{
	cout<<"lecture hall not found\n";
}
}


void LecLinkedList::Add_Front( string &e,float f,int a,int b,int c,int d,int g){
	LCnode* ptr= new LCnode;
	ptr->name=e;
	ptr->area=f;
	ptr->no_of_doors=a;
	ptr->x=b;
	ptr->y=c;
	ptr->no_of_chairs=d;
	ptr->status=g;
    ptr->next=headl;
    headl=ptr;
}
void LecLinkedList::Remove(string &e){
// case 1 empty list
if (headl==NULL){
	cout<< "Lec hall cannot be deleted from an empty linked list"<<endl;
}  	
else {
	LCnode* curr=headl;
	LCnode* trail=NULL;
	while (curr!=0){
		if ((curr->name==e))//&&(curr->area==f) &&(curr->no_of_doors==a)&& (curr->x==b) &&(curr->y==c)&& (curr->no_of_chairs==d))
		{
			break;
		}
		else{
			trail=curr;
			curr=curr->next;
		}
	}
	if (curr==0){
		cout<<"required Lec hall "<< e<<"not found"<<endl; 
	}
	else{
		if (headl==curr){
			headl=headl->next;
		}
		else{

			trail->next=curr->next;
		}
		delete curr;
	}
}
cout<<"lecture hall removed\n";	
}


void LecLinkedList::BookLec(string &e){
	LCnode *ptr=headl;
	while(ptr!=NULL){
		if(ptr->name==e){
			break;
		}
		else{
	ptr=ptr->next;
	}
}
 if ((ptr!=0) && (ptr->status!=1)){
	ptr->status=1;
    cout<<"lecture hall booked\n";
}
 else{
	cout<<"Lec hall cannot be booked\n";
}
}
void LecLinkedList::printList(){
	LCnode*ptr=headl;
	while (ptr!=NULL){
	cout<<ptr->name<<"\t"<<ptr->area<<"\t "<<ptr->no_of_doors<<"\t"<<ptr->x<<"\t"<<ptr->y<<"\t"<<ptr->no_of_chairs<<"\t"<<ptr->status<<endl;
	ptr=ptr->next;
}
}

void LecLinkedList::UnbookLec(string &e){
	LCnode *ptr=headl;
	while(ptr!=NULL){
		if(ptr->name==e){
			break;
		}
	else{
		ptr=ptr->next;
	}
}
 if ((ptr!=0) && (ptr->status!=0)){
	ptr->status=0;
	cout<<"lecture hall unbooked\n";
}
 else{
	cout<<"Lec hall is already unbooked\n";
}
}






int main(){
	RoomLinkedList r1;
	string name;
	float area;
	int no_of_doors;
	int x;
	int y;
	int no_of_computers;
	int no_of_chairs;
	int status=0;
	float common2;
	ifstream rm;
	rm.open("ROOM.txt");
	while(!rm.eof()){
		rm>>name>>area>>no_of_doors>>x>>y;
		if(!rm){
			break;
		}
	    r1.Add_Front(name,area,no_of_doors,x,y,status);
	}
	//r1.PrintList();
	


	LabLinkedList l1;
	ifstream lm;
	lm.open("LAB.txt");
	while(!lm.eof()){
		lm>>name>>area>>no_of_doors>>x>>y>>no_of_computers;
		if(!lm){
			break;
		}
	    l1.Add_Front(name,area,no_of_doors,x,y,no_of_computers,status);
	}
	//l1.printList();

	
	LecLinkedList lc1;
	ifstream lcm;
	lcm.open("LEC.txt");
	while(!lcm.eof()){
		lcm>>name>>area>>no_of_doors>>x>>y>>no_of_chairs;
		if(!lcm){
			break;
		}
	    lc1.Add_Front(name,area,no_of_doors,x,y,no_of_chairs,status);
	}
	
    
    int k=0,input=0;
    //cout<<"to start the program input the no. in the range of 0 to 10\n";
    
    while (input!=11){
	 
	    int common;
    cout<<"1.Book Room/lab/lecture hall\n";
    cout<<"2.Remove Room/lab/lecture hall\n";
    cout<<"3.Add Room/lab/lecture hall\n";
    cout<<"4.Find the minimun no. of rooms required for persons\n";
    cout<<"5.Find the smallest lecture hall\n";
    cout<<"6.Find the lab with least equipment density\n";
    cout<<"7.Add the Computers to the lab\n";
    cout<<"8.To find the nearest room to the given location\n";
    cout<<"9.Unbook Room/lab/lecture hall\n";
    cout<<"10.Show details of Room/lab/lecture hall\n";
    cout<<"11.Exit and Save\n";
     
   // int input;
    cin>>input;
    string Name;
    switch(input){
    	case 1:
    	cout<<"1. Book Room\n";
    	cout<<"2. Book Lab\n";
    	cout<<"3. Book lecturehall\n";
        int A11;
        cin>>A11; 
        switch(A11){
        	case 1:
        	cout<<"enter the Room name:\n";
        	cin>>Name;
        	r1.BookRoom(Name);
        	break;
        	case 2:
        	cout<<"enter the Lab name:\n";
        	cin>>Name;
        	l1.BookLab(Name);
        	break;
        	case 3:
        	cout<<"enter the lecturehall name:\n";
        	cin>>Name;
        	lc1.BookLec(Name);
        	break;
        }
        break;
        case 2:
        cout<<"1. Remove Room\n";
    	cout<<"2. Remove Lab\n";
    	cout<<"3. Remove lecturehall\n";
        int A22;
        cin>>A22;
        switch(A22){ 
        	case 1:
            cout<<"enter the Room name:\n";
        	cin>>Name;
        	r1.Remove(Name);
        	break;
        	case 2:
        	cout<<"enter the Lab name:\n";
        	cin>>Name;
        	l1.Remove(Name);
        	break;
        	case 3:
        	cout<<"enter the lecturehall name:\n";
        	cin>>Name;
        	lc1.Remove(Name);
        	break;
        }
        break;
        case 3:
        cout<<"1. Add Room\n";
    	cout<<"2. Add Lab\n";
    	cout<<"3. Add lecturehall\n";
        int A33;
        cin>>A33;
        switch(A33){ 
        	case 1:
            cout<<"enter the Room details along with status:\n";
        	cin>>name>>area>>no_of_doors>>x>>y>>status;
        	r1.Add_Front(name,area,no_of_doors,x,y,status);
        	cout<<"room added\n";
        	break;
        	case 2:
        	cout<<"enter the Lab name along with status:\n";
        	cin>>name>>area>>no_of_doors>>x>>y>>no_of_computers>>status;
        	l1.Add_Front(name,area,no_of_doors,x,y,no_of_computers,status);
        	cout<<"lab added\n";
        	break;
        	case 3:
        	cout<<"enter the lecturehall name along with status:\n";
        	cin>>name>>area>>no_of_doors>>x>>y>>no_of_chairs>>status;
        	lc1.Add_Front(name,area,no_of_doors,x,y,no_of_chairs,status);
        	cout<<"lecture added\n";
        	break;
        }
        break;

        case 4:
        cout<<"enter the no. of persons";
        cin>>x;
        r1.MinRooms(x);
        break;

        case 5:
        cout<<"enter the no. of students for lecture hall:\n";
        cin>>x;
        lc1.Smallest_lec(x);
        break;



        case 6:
        common2=l1.Least_Density();
        cout<<"lab with least equipment density\n";
        cout<<common2<<endl;
        break;


        case 7:
        cout<<"enter the name of the lab and no. of computers\n";
        cin>>Name>>common;
        l1.Add_computers(Name,common);
        cout<<"computers added to the lab  "<<name<<endl;
        break;
        
        case 8:
        cout<< "enter your x and y coordinates\n";
        int xx,yy;
        cin>>xx>>yy;
        r1.Nearest_Room(xx,yy);
        break;

        case 9:
    	cout<<"1. UnBook Room\n";
    	cout<<"2. UnBook Lab\n";
    	cout<<"3. UnBook lecturehall\n";
        int A19;
        cin>>A19; 
        switch(A19){
        	case 1:
        	cout<<"enter the Room name:\n";
        	cin>>Name;
        	r1.UnbookRoom(Name);
        	break;
        	case 2:
        	cout<<"enter the Lab name:\n";
        	cin>>Name;
        	l1.UnbookLab(Name);
        	break;
        	case 3:
        	cout<<"enter the lecturehall name:\n";
        	cin>>Name;
        	lc1.UnbookLec(Name);
        	break;
        cout<<"Room unbooked\n";
        }
        break;


        case 10:
        
        cout<<"1. Get details of Room\n";
    	cout<<"2. Get details of Lab\n";
    	cout<<"3. Get details of lecturehall\n";
        int A10;
        cin>>A10; 
        switch(A10){
        	case 1:
        	cout<<"enter the Room name:\n";
        	cin>>Name;
        	r1.PrintDetails(Name);
        	k=11;
        	break;
        	case 2:
        	cout<<"enter the Lab name:\n";
        	cin>>Name;
        	l1.PrintDetails(Name);
        	k=11;
        	break;
        	case 3:
        	cout<<"enter the lecturehall name:\n";
        	cin>>Name;
        	lc1.PrintDetails(Name);
        	k=11;
        	break;
        
        }
        break;
        
        case 11:
        break;
        


       
}
    
}//while ends
//cout<<"Data saved"<<endl;
ofstream rm2 ;
	rm2.open("OROOM.txt");
	string nameo;
	float areao;
	int no_of_doorso;
	int xo;
	int yo;
	int no_of_computerso;
	int no_of_chairso;
	int statuso;
	
	Rnode *p=r1.headr;
	while(p!=NULL){
		nameo=p->name;
		areao=p->area;
		no_of_doorso=p->no_of_doors;
		xo=p->x;
		yo=p->y;
		statuso=p->status;
			rm2<<nameo<<"\t"<<areao<<"\t"<<no_of_doorso<<"\t"<<xo<<"\t"<<yo<<"\t"<<statuso<<endl;
	p=p->next;
	}



	ofstream rl2 ;
	rl2.open("OLAB.txt");
    Lnode *p1=l1.head;
	while(p1!=NULL){
		nameo=p1->name;
		areao=p1->area;
		no_of_doorso=p1->no_of_doors;
		xo=p1->x;
		yo=p1->y;
		no_of_computerso=p1->no_of_computers;
		statuso=p1->status;
	rl2<<nameo<<"\t"<<areao<<"\t"<<no_of_doorso<<"\t"<<xo<<"\t"<<yo<<"\t"<<no_of_computerso<<"\t"<<statuso<<endl;
	p1=p1->next;
	}

	ofstream rlc2 ;
	rlc2.open("OLEC.txt");
    LCnode *p2=lc1.headl;
	while(p2!=NULL){
		nameo=p2->name;
		areao=p2->area;
		no_of_doorso=p2->no_of_doors;
		xo=p2->x;
		yo=p2->y;
		no_of_chairso=p2->no_of_chairs;
		statuso=p2->status;
	rlc2<<nameo<<"\t"<<areao<<"\t"<<no_of_doorso<<"\t"<<xo<<"\t"<<yo<<"\t"<<no_of_chairso<<"\t"<<statuso<<endl;
	p2=p2->next;
	}
    


            cout<<"Data saved"<<endl;





    
	return 0;
}










