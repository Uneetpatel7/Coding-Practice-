#include<iostream>
#include<vector>
#include<fstream>
#include<stdexcept>
#include<cstdlib>


using namespace std;
using std::vector;

class stack{
public:
	vector <int> vect;
	void push(char x);
	void pop();
	int top();
	bool empty() ;
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


int stack::top(){

	if (vect.empty()){
    throw out_of_range("Stack<>::top(): empty stack");
    }

	// return copy of last element
    return vect.back();
}


bool stack::empty(){
     return vect.empty();
}


int main(){
	int k;
	cout<<"enter the no. of inputs:\n";
	cin>>k;
	cout<<"enter the inputs:\n";
	int input[100];
	int i;
	for (i=0;i<k;i++){
	cin>>input[i];
	}

	int output[]={0,0,0,0,0,0,0};
    stack stack1;

    for(i=0;i<k;i++){
            if(i==0){
    		output[i]=-1;
    		stack1.push(input[i]);
    	}

       if(i>0 && i<k){
            while (1>0) {

                if (stack1.empty()) {output[i]=-1; break;}

                if(input[i]>stack1.top() || input[i]==stack1.top()){
                                stack1.pop();}

                if (stack1.empty()) {output[i]=-1; break;}

                if(stack1.top() >= input[i])
                    {output[i]=stack1.top();
                    break;}


                         } //ends while

            	stack1.push(input[i]);

                    }   // ends if
                    }   // ends for
    for(i=0;i<k;i++){
    	cout<<output[i]<<" ";
    }

	return 0;
           }
