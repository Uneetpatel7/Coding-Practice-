#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

typedef int keytype;
typedef string valuetype;

class AVL_node{
public:	
	keytype data;
	valuetype value;
	AVL_node* Left_child;
	AVL_node* Right_child;	
	};
AVL_node* root=NULL;

AVL_node* arr[100];
int i=0;


class  AVL_tree{
public:
	int height(AVL_node* temp);
	int difference(AVL_node* temp); 
	AVL_node* left_left_rotation(AVL_node*  parent);
	AVL_node* right_right_rotation(AVL_node*  parent);
	AVL_node* left_right_rotation(AVL_node*  parent);
	AVL_node* right_left_rotation(AVL_node*  parent);
	AVL_node* restore_balance(AVL_node* temp);
	AVL_node* insert_node(AVL_node* root,keytype key,valuetype val);
	AVL_node* delete_node(AVL_node* root,keytype key);
	AVL_node* min_value_node(AVL_node* temp);
	void postorder(AVL_node* p,int indent);
	AVL_node* firstEntry( AVL_node* root);
	AVL_node* lastEntry( AVL_node* root);
	AVL_node* ceilingEntry(keytype key);
	AVL_node* floorEntry(keytype key);
	AVL_node* lowerEntry(keytype key);
	AVL_node* higherEntry(keytype key);
	void size();
	bool empty(AVL_node* root);
	AVL_node* find(AVL_node* root,keytype key);
	void inorder(AVL_node* root );
};

AVL_node* AVL_tree::lowerEntry(keytype key){
	int j=0;
	if(key<=arr[j]->data){
		cout<<"no lower value exists\n";
		return NULL;
	}
	if(key>arr[i-1]->data){
		return arr[i-1];
	}
	while(arr[j]->data<key){
		j++;
	}
	return arr[j-1];
	}


AVL_node* AVL_tree::higherEntry(keytype key){
	int j=0;
	if(key<arr[j]->data){
		return arr[j];
	}
	if(key>=arr[i-1]->data){
		cout<<"no higher value exists\n";
		return NULL;
	}
	while(arr[j]->data<key){
		j++;
	}
	if(arr[j]->data==key){
		return arr[j+1];
	}
	else if(arr[j]->data>key){
		return arr[j];
	}

}

AVL_node* AVL_tree::floorEntry(keytype key){
	int j=0;
	if(key<arr[0]->data){
		cout<<"floor doesnot exist\n";
		return NULL;}
	else if(key>=arr[i-1]->data){
		return arr[i-1];
	}
	while(arr[j]->data<=key){
		j++;
	}
	return arr[j-1];
	}


AVL_node* AVL_tree::ceilingEntry(keytype key){
	int j=0;
	if(key<arr[0]->data){
		return arr[j];
	}
	else if(key>arr[i-1]->data){
		cout<<"ceiling doesnot exist\n";
		return NULL;
	}
	while(arr[j]->data<key){
		j++;
	}
	return arr[j];
}




bool AVL_tree::empty(AVL_node* root){
	if (root==NULL)
		return true;
	else 
		return false;
}

void AVL_tree::inorder(AVL_node* root ){
	//i=0;
	if(root==NULL)
		return;
	else{
		inorder(root->Left_child);
		arr[i++]=root;
			
		inorder(root->Right_child);
	}

}

void AVL_tree::size(){
	cout<<"the size of map is: "<<i<<endl;
}


AVL_node* AVL_tree::find(AVL_node* root,keytype key){
	AVL_node* s=root;
	if(root==NULL)
	return NULL;
	while(s!=NULL){
	if(key>s->data)
		s=s->Right_child;
	else if(key<s->data)
		s=s->Left_child;
	else 
		break;
}
	if(s==NULL){
		cout<<"Entry doesnot exist\n";
		return NULL;
	}
	return s;


}




void AVL_tree::postorder(AVL_node* p, int indent=0)
{
    if(p != NULL) {
        if(p->Right_child) {
            postorder(p->Right_child, indent+4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->Right_child) std::cout<<" /\n" << std::setw(indent) << ' ';
        std::cout<<"("<< p->data <<","<<p->value<<")"<< "\n ";
        if(p->Left_child) {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            postorder(p->Left_child, indent+4);
        }
    }
}

AVL_node* AVL_tree::min_value_node(AVL_node* temp){
	AVL_node* current=temp;
	while(current->Left_child != NULL)
	current = current->Left_child;

	return current;
}


                                                                                                                                                                                            
int AVL_tree::height(AVL_node* temp){
	int h=0;
	if(temp!=NULL){
		int Left_height= height(temp->Left_child);
		int Right_height= height(temp->Right_child);
		int max_height= max(Left_height,Right_height);
		h=max_height+1;
	
	}
	return h;
}

//returns balance factor
int AVL_tree::difference(AVL_node *temp){
	int Left_height=height(temp->Left_child);
	int Right_height=height(temp->Right_child);
	int BF=Left_height - Right_height;
	return BF;
}

AVL_node* AVL_tree::left_left_rotation(AVL_node* parent){
	AVL_node *temp;
	temp=parent->Left_child;		
	parent->Left_child=temp->Right_child;
	temp->Right_child=parent;
	return temp;
}

AVL_node* AVL_tree::right_right_rotation(AVL_node* parent){
	AVL_node* temp;
	temp=parent->Right_child;	
	parent->Right_child=temp->Left_child;
	temp->Left_child=parent;
	return temp;
}

AVL_node* AVL_tree::left_right_rotation(AVL_node* parent){

	AVL_node* temp;
	temp=parent->Left_child;
	parent->Left_child=right_right_rotation(temp);
	return left_left_rotation(parent);

}

AVL_node* AVL_tree::right_left_rotation(AVL_node* parent){

	AVL_node* temp;
	temp=parent->Right_child;
	parent->Right_child=left_left_rotation(temp);
	return right_right_rotation(parent);
}


AVL_node* AVL_tree::insert_node(AVL_node* root,keytype key,valuetype val){

	if(root==NULL){
	root= new AVL_node;
	root->data=key;
	root->value=val;
	root->Left_child=NULL;
	root->Right_child=NULL;
	return root;
	}

	else if(key<root->data){
	root->Left_child=insert_node(root->Left_child,key,val);
	root=restore_balance(root);
	}

	else if(key>root->data){
	root->Right_child=insert_node(root->Right_child,key,val);
	root=restore_balance(root);	
	}
	else if(key==root->data){
	root->data=key;
	root->value=val;

	}

	return root;
}

AVL_node* AVL_tree::delete_node(AVL_node* root,keytype key){
	if(root==NULL)
	{
	return root;
	}
    //cout<<root->data<<endl;
	if(key > root->data){
	root->Right_child=delete_node(root->Right_child,key);	
	}
	else if(key < root->data){
	root->Left_child=delete_node(root->Left_child,key);
	}
	else{

	if((root->Right_child==NULL) || (root->Left_child==NULL)){ //external node
		AVL_node* temp = root->Left_child?root->Left_child:root->Right_child;
		if(temp==NULL){ //empty child
		temp=root;
		root=NULL;
		}
		else
		*root=*temp;  //one child case
//cout<<temp<<"ajsajdasjdnaskjd"<<root<<endl;
		delete temp;	
	}
	else{  //internal node
		AVL_node* successor=min_value_node(root->Right_child);
		root->data=successor->data;
		root->Right_child=delete_node(root->Right_child,successor->data);
	}

	}
	if(root==NULL)
	{
	return root;
	}

	
	int bf=difference(root);
	if(bf>=2){

		if((difference(root->Left_child)>0)){
			root=left_left_rotation(root);
		}
		else{
			root=left_right_rotation(root);
		}
	}
		else if(bf<=-2){
			if((difference(root->Right_child))>0){
				root=left_left_rotation(root);
			}
			else{
				root=right_right_rotation(root);
			}

	

	//return restore_balance(root);
		}
	
	return root;
}

AVL_node* AVL_tree::restore_balance(AVL_node* temp){
	int balance_factor=difference(temp);

	if(balance_factor>=2){
		
		if((difference(temp->Left_child))>0){
		temp=left_left_rotation(temp);	
		}

		else{
		temp=left_right_rotation(temp);
		}

	}

	else if(balance_factor<=-2){
		
		if((difference(temp->Right_child))>0){
		temp=right_left_rotation(temp);
		}

		else{
		temp=right_right_rotation(temp);
		}


	}

	return temp;

}

AVL_node* AVL_tree::firstEntry( AVL_node* root){
	if(root==NULL){
	cout<<"empty map\n";
	return NULL;}
	else 
	return(min_value_node(root));
} 

AVL_node* AVL_tree::lastEntry( AVL_node* root){
	if(root==NULL){
	cout<<"empty map\n";
	return NULL;
	}
	else
	return arr[i-1]; 
	
}

int main()

{
	
    int choice;
    keytype item,var,key;
    valuetype value1;

    AVL_tree avl;
    AVL_node* root=NULL;
    AVL_node* q;
    AVL_node* q1;
    AVL_node* q2;
    AVL_node* q3;
    AVL_node* q5;
    AVL_node* q4;
    AVL_node* q6;

    while (1)

    {

        cout<<"\n---------------------"<<endl;

        cout<<"AVL Tree Implementation"<<endl;

        cout<<"\n---------------------"<<endl;

        cout<<"1.To find a first entry"<<endl;
        cout<<"2.To find a last entry"<<endl;
        cout<<"3.To find a ceiling entry of input"<<endl;
        cout<<"4.To find a floor entry of input"<<endl;
        cout<<"5.To find a lower entry of  input"<<endl;
        cout<<"6.To find a higher entry of input"<<endl;
        cout<<"7.To find size of a map"<<endl;
        cout<<"8.To check wether map is empty?"<<endl;
        cout<<"9.To find a node of given key"<<endl;
        cout<<"10.Insert an Element into the map"<<endl;
        cout<<"11.Delete an Element from the map"<<endl;
        cout<<"12.Display AVL tree"<<endl;
       	cout<<"13.EXIT"<<endl;

        cin>>choice;

        switch(choice)

        {

        case 1:
        	q1=avl.firstEntry(root);
        	if(q1!=NULL)
        	cout<<"key of first entry is:"<<q1->data<<endl;

            break;

        case 2:
        	avl.inorder(root);
			q2=avl.lastEntry(root);
        	if(q2!=NULL)
        	cout<<"key of last entry is:"<<q2->data<<endl;
        
            break;

        case 3:
        	avl.inorder(root);
        	keytype ceiling;
        	cout<<"enter the value of which ceiling is to be calculated: \n";
        	cin>>ceiling;
         	q=avl.ceilingEntry(ceiling);
         	if(q!=NULL)
         	cout<<"ceiling:"<<q->data<<endl;
            

            break;

        case 4:
 			avl.inorder(root);
        	
        	keytype floor;
        	cout<<"enter the value of which floor is to be calculated: \n";
        	cin>>floor;
         	q=avl.floorEntry(floor);
         	if(q!=NULL)
        	cout<<"floor:"<<q->data<<endl;	

        	break;


        
        case 5:
	        avl.inorder(root);
        	
        	keytype lower;
        	cout<<"enter the value of which lower value is to be calculated: \n";
        	cin>>lower;
         	q5=avl.lowerEntry(lower);
         	if(q5!=NULL)
        	cout<<"lower:"<<q5->data<<endl;	


       
         break;

         case 6:
			avl.inorder(root);
        	
        	keytype higher;
        	cout<<"enter the value of which higher value is to be calculated: \n";
        	cin>>higher;
         	q6=avl.higherEntry(higher);
         	if(q6!=NULL)
        	cout<<"higher:"<<q6->data<<endl;	

 			

         break;

        case 7:
        	i=0;
        	avl.inorder(root);
        	avl.size();
        	break;

        

        case 8:
        if(avl.empty(root)==1)
        	cout<<"tree is empty\n";
        else
        	cout<<"tree is not empty\n";
        break;

        case 9:
        cout<<"Enter the key of the desired node:";
        cin>>var;
        q=avl.find(root,var);
        if(q!=NULL){
        cout<<"details\n";
        cout<<"key:"<<q->data<<endl;
        cout<<"value:"<<q->value<<endl;}
        break; 

        case 10:
            cout<<"Enter key and value to be inserted: ";

            cin>>item>>value1;

            root = avl.insert_node(root, item,value1);

        break; 

        case 11:
        	cout<<"enter the node you want to delete\n"<<endl;
            cin>>key;
            root=avl.delete_node(root,key);

            cout<<endl;
        break; 

         
        
        case 12:
          if (root == NULL)

            {

                cout<<"Tree is Empty"<<endl;

                continue;

            }

            cout<<"Balanced AVL Tree:"<<endl;

            avl.postorder(root);

        break;

        case 13:

            exit(1);    

            break;

        default:

            cout<<"Wrong Choice"<<endl;

        }

    }

    

    
    return 0;
}


 
