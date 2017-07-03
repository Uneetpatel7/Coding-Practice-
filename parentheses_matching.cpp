#include<iostream>
#include<vector>
#include<fstream>
#include<stdexcept>
#include<cstdlib>


using namespace std;
using std::vector;



class stack{
public:
	vector<char> vect;
	void push(char x);
	void pop();
	char top();
	bool empty();
};


void stack::push(char x){
	vect.push_back(x);
}


void stack::pop(){

	if (vect.empty()) {
    throw out_of_range("Stack<>::pop(): empty stack");
    }
 
	// remove last element
    vect.pop_back();
}


char stack::top(){

	if (vect.empty()){
    throw out_of_range("Stack<>::top(): empty stack");
    }

	// return copy of last element
    return vect.back();
}


bool stack::empty(){
     return vect.empty();
}


bool compare(stack x,stack y);
void copystack(stack x,stack y);

int main(){
	stack stack1;
	stack stack2;
	stack stack3;
	char var;
	int flag2=0;
	ifstream sample;
	sample.open("Q1T1.txt");
    while(!sample.eof()){
    sample>>var;

    if(!sample){
    	break;
    }

    if(var=='$')
    flag2++;

    if(var=='$' && ((flag2-1)%2)==0){
    stack1.push(var);
    }

     if(var=='{'||var=='('||var=='['){
    stack1.push(var);
    }

     if(var=='}'||var==')'||var==']')
     					{

    					if((var=='}'&& stack1.top()=='{') ||(var==')'&& stack1.top()=='(')||(var==']'&& stack1.top()=='[')){
   					 stack1.pop();
    }

    }

     if (var=='$' && (flag2)%2==0 && stack1.top()=='$'){
    				stack1.pop();

    }



}

    if (stack1.empty()){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;

}
