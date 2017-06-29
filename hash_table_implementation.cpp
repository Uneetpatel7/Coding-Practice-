#include<iostream>
#include<vector>
#include<fstream>
#include<stdexcept>
#include<cstdlib>
#include<string>
#include<cmath>

using namespace std;
unsigned int int_cast(char x[]);
unsigned int comp_sum(char x[]);
unsigned int poly_sum(char x[]);
unsigned int clyc_sum(char x[]);
unsigned int division(unsigned int x,unsigned int n);
unsigned int Mad(unsigned int x,unsigned int n);
unsigned int mul(unsigned int x,unsigned int n);

class Data{
public:
  unsigned int key;
  string text;
  Data();
 // ~Data();
};

Data::Data(){
  key=0;
  text="12345";

}


unsigned int int_cast(char x[]){
unsigned int h=0,k=0,p=0,l=0;
	  for(int i=0;i<4;i++){
		h=(h | ((unsigned int)x[i]<<k));
		k=k+8;
	  }
    for(int j=4;j<6;j++){
		p=(p | ((unsigned int)x[j]<<l));
		l=l+8;
	  }
	  return h+p;
}

unsigned int comp_sum(char x[]){
	  unsigned int i,sum=0;
	  for(i=0;i<6;i++){
    sum=sum + (unsigned int)x[i];
	  }
    return sum;
}

unsigned int poly_sum(char x[]){
	  unsigned int sum=0,a=33;
    for(int i=0;i<5;i++){
    sum=a*(unsigned int)x[i]+(unsigned int)x[i+1];
    }
    return sum;
}


unsigned int clyc_sum(char x[]){
	  unsigned int h=0;
	  for(int i=0;i<6;i++){
		h=(h<<5) |(h>>27);
		h=h + (unsigned int)x[i];
	  }
	  return h;
}

unsigned int division(unsigned int x,unsigned int n){
   unsigned int a;
   a=x%n;
   return a;
}

unsigned int Mad(unsigned int x,unsigned int n){
	unsigned int a=7,b=3;
	x=a*x+b;
	x=x%n;
	return x;
}

unsigned int mul(unsigned int x,unsigned int n){
unsigned int m=64,h=0;
  float a= (sqrt(5)-1)/2;
  float b=(x*a);
  b=b-(int)b;
  h=(unsigned int)(b*m);
  h=h%48073;
  return h;
}

int main(){

  char text_string[32037],temp[7],var;
  unsigned int N=32037,i=0,N1=48073,_k=0,j,temp_key,hash_comp[4][3],itr,false_positive[4][3],string_comparison[4][3];
  
  //Rows stores the output of division,mad,mul
  //column stores the output of int_cast,poly_sum etc..... 
  //(0,0)=int casting with div
  //(0,1)=int casting with Mad
  //(0,2)=int casting with mul  
  //(1,x)=comp_sum with all of the above three
  //(2,x)=polynomial_sum with all of the above three
  //(3,x)=cyclic_sum with all of the above three
  // creating hashtables for all of the above
  Data hash_value0[32032],hash_value1[32032],hash_value2[32032],hash_value3[32032];
  Data* key_table00 = new Data[48073];
  Data* key_table01 = new Data[48073];
  Data* key_table02 = new Data[48073];                            
  Data* key_table10 = new Data[48073];
  Data* key_table11 = new Data[48073];
  Data* key_table12 = new Data[48073];
  Data* key_table20 = new Data[48073];
  Data* key_table21 = new Data[48073];
  Data* key_table22 = new Data[48073];
  Data* key_table30 = new Data[48073];
  Data* key_table31 = new Data[48073];
  Data* key_table32 = new Data[48073];

  
  ifstream sample;
  sample.open("T.txt");
  while(!sample.eof()){
     sample>>var;
     text_string[i]=var;
        if(!sample){
        break;
        }
     i++;

  } // while

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    for(i=0;i<=N-6;i++){
    	      for( j=0;j<6;j++){                                 //extracting substring of size six
    		    temp[j]=text_string[i+j];
            }
    temp[j]='\0';
    hash_value0[i].text=&temp[0];
    hash_value0[i].key=int_cast(temp);
    }


	  for(i=0;i<=N-6;i++){                                 //calculating hashvalue
    _k=division(hash_value0[i].key,N1);
    temp_key=_k;
            while(true) {
             if(key_table00[temp_key].key==0){
             key_table00[temp_key].key=_k;
             key_table00[temp_key].text=hash_value0[i].text;
             break;
             }
    temp_key=(temp_key+1)%N1;}
    }       

    for(i=0;i<=N-6;i++){
    _k=Mad(hash_value0[i].key,N1);                            // calculating key and constructing hashtable by linear probing for int casting with div i.e. (0,0)
    temp_key=_k;
            while(true){
            if(key_table01[temp_key].key==0) {
            key_table01[temp_key].key=_k;
             key_table01[temp_key].text=hash_value0[i].text;
             break;
             }
    temp_key=(temp_key+1)%N1;
             }
    }

    for(i=0;i<=N-6;i++){
    _k=mul(hash_value0[i].key,N1);
    temp_key=_k;
            while(true){
            if(key_table02[temp_key].key==0) {
            key_table02[temp_key].key=_k;
            key_table02[temp_key].text=hash_value0[i].text;
            break;
            }
    temp_key=(temp_key+1)%N1; 
            }
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    for(i=0;i<=N-6;i++){
            for( j=0;j<6;j++){
            temp[j]=text_string[i+j];
            }
    temp[j]='\0';
    hash_value1[i].text=&temp[0];
    hash_value1[i].key=comp_sum(temp);
   
    }


    for(i=0;i<=N-6;i++){
    _k=division(hash_value1[i].key,N1);
    temp_key=_k;
            while(true){
            if(key_table10[temp_key].key==0) {
            key_table10[temp_key].key=_k;
            key_table10[temp_key].text=hash_value1[i].text;
            break;
            }
    temp_key=(temp_key+1)%N1;
            }
  }
    
    for(i=0;i<=N-6;i++){
    _k=Mad(hash_value1[i].key,N1);
    temp_key=_k;
           while(true){
            if(key_table11[temp_key].key==0) {
            key_table11[temp_key].key=_k;
            key_table11[temp_key].text=hash_value1[i].text;
            break;
            }
     temp_key=(temp_key+1)%N1;  
            }
  }

    for(i=0;i<=N-6;i++){
    _k=mul(hash_value1[i].key,N1);
    temp_key=_k;
           while(true){
            if(key_table12[temp_key].key==0) {
            key_table12[temp_key].key=_k;
            key_table12[temp_key].text=hash_value1[i].text;
            break;
            }
     temp_key=(temp_key+1)%N1;
    
    }
  }

 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    for(i=0;i<=N-6;i++){
        for( j=0;j<6;j++){
        temp[j]=text_string[i+j];
        }
        temp[j]='\0';
    hash_value2[i].text=&temp[0];
    hash_value2[i].key=poly_sum(temp);
    }


    for(i=0;i<=N-6;i++){
    _k=division(hash_value2[i].key,N1);
    temp_key=_k;
            while(true){
            if(key_table20[temp_key].key==0) {
            key_table20[temp_key].key=_k;
            key_table20[temp_key].text=hash_value2[i].text;
            break;
            }
    temp_key=(temp_key+1)%N1;    
            }
  }

    for(i=0;i<=N-6;i++){
    _k=Mad(hash_value2[i].key,N1);
    temp_key=_k;
            while(true){
            if(key_table21[temp_key].key==0) {
            key_table21[temp_key].key=_k;
            key_table21[temp_key].text=hash_value2[i].text;
            break;
            }
     temp_key=(temp_key+1)%N1;   
            }
  }
   
    for(i=0;i<=N-6;i++){
    _k=mul(hash_value2[i].key,N1);
    temp_key=_k;
            while(true){
            if(key_table22[temp_key].key==0) {
            key_table22[temp_key].key=_k;
            key_table22[temp_key].text=hash_value2[i].text;
            break;
            }
     temp_key=(temp_key+1)%N1;
            }
  }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    for(i=0;i<=N-6;i++){
        for( j=0;j<6;j++){
        temp[j]=text_string[i+j];
        }
        temp[j]='\0';
    hash_value3[i].text=&temp[0];
    hash_value3[i].key=clyc_sum(temp);
    }


    for(i=0;i<=N-6;i++){
    _k=division(hash_value3[i].key,N1);
    temp_key=_k;
           while(true){
            if(key_table30[temp_key].key==0) {
            key_table30[temp_key].key=_k;
            key_table30[temp_key].text=hash_value3[i].text;
            break;
            }
    temp_key=(temp_key+1)%N1;  
            }
  }

    for(i=0;i<=N-6;i++){
    _k=Mad(hash_value3[i].key,N1);
    temp_key=_k;
           while(true){
            if(key_table31[temp_key].key==0) {
            key_table31[temp_key].key=_k;
            key_table31[temp_key].text=hash_value3[i].text;
            break;
            }
     temp_key=(temp_key+1)%N1;
            } 
  }
    
    for(i=0;i<=N-6;i++){
    _k=mul(hash_value3[i].key,N1);
    temp_key=_k;
            while(true){
            if(key_table32[temp_key].key==0) {
            key_table32[temp_key].key=_k;
            key_table32[temp_key].text=hash_value3[i].text;
            break;
            }
    temp_key=(temp_key+1)%N1;
    }
  }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     
    //string str; 
    ifstream pattern;
    char arr[7];                             //taking input string and performing operation one by one on all of them
    string input;
    i=0;

    for(int a=0;a<4;a++){
        for(int b=0;b<3;b++)
        false_positive[a][b]=0;
    }
    pattern.open("P.txt");
    pattern>>input;
   
   while(!pattern.eof()){
        for(int l=0;l<6;l++){
        arr[l]=input[l];
   } 
////////////////////////////////////////////////////  
      hash_comp[0][0]=int_cast(arr);
      hash_comp[0][0]=division(hash_comp[0][0],N1);
      itr=hash_comp[0][0];

      int x1=0,x2=0;

      while (true){

        if(key_table00[itr].key==hash_comp[0][0])
          x1=1;
        if(key_table00[itr].text==&arr[0])
          x2=1;
        
        if(key_table00[itr].key==0)
          break;
        itr=(itr+1)%N1;
      }
      //string comparisons
      string_comparison[0][0]=itr;
       
      // False Positive x1=1 && x2=0
      if(x1==1 && x2==0)
      false_positive[0][0]++;

    
       


////////////////////////////////////////////////////
       hash_comp[0][1]=int_cast(arr);
      hash_comp[0][1]=Mad(hash_comp[0][1],N1);
      itr=hash_comp[0][1];

       x1=0;x2=0;

      while (true){

        if(key_table01[itr].key==hash_comp[0][1])
          x1=1;
        if(key_table01[itr].text==&arr[0])
          x2=1;
        
        if(key_table01[itr].key==0)
          break;
        itr=(itr+1)%N1;
        }
        //string comparisons
        string_comparison[0][1]=itr;
       
      // False Positive x1=1 && x2=0
      if(x1==1 && x2==0)
      false_positive[0][1]++;

//////////////////////////////////////////////////////
       hash_comp[0][2]=int_cast(arr);
      hash_comp[0][2]=mul(hash_comp[0][2],N1);
      itr=hash_comp[0][2];

       x1=0;x2=0;

      while (true){
        

        if(key_table02[itr].key==hash_comp[0][2])
          x1=1;
        if(key_table02[itr].text==&arr[0])
          x2=1;
        
        if(key_table02[itr].key==0)
          break;
        itr=(itr+1)%N1;
        }
        //string comparisons
        string_comparison[0][2]=itr+3385;
       
      // False Positive x1=1 && x2=0
      if(x1==1 && x2==0)
       false_positive[0][2]++;

//////////////////////////////////////////////////////////
      hash_comp[1][0]=comp_sum(arr);
      hash_comp[1][0]=division(hash_comp[1][0],N1);
      itr=hash_comp[1][0];

       x1=0,x2=0;

      while (true){

        if(key_table10[itr].key==hash_comp[1][0])
          x1=1;
        if(key_table10[itr].text==&arr[0])
          x2=1;
        
        if(key_table10[itr].key==0)
          break;

        itr=(itr+1)%N1;
        }
        //string comparisons
        string_comparison[1][0]=itr;
       
        //False Positive x1=1 && x2=0
        if(x1==1 && x2==0){
        false_positive[1][0]++;
       }

////////////////////////////////////////////////////////////

        hash_comp[1][1]=comp_sum(arr);
      hash_comp[1][1]=Mad(hash_comp[1][1],N1);
      itr=hash_comp[1][1];

       x1=0;x2=0;

      while (true){

        if(key_table01[itr].key==hash_comp[1][1])
          x1=1;
        if(key_table01[itr].text==&arr[0])
          x2=1;
        
        if(key_table01[itr].key==0)
          break;
        itr=(itr+1)%N1;
        }
        //string comparisons
        string_comparison[1][1]=itr;
       
      // False Positive x1=1 && x2=0
      if(x1==1 && x2==0)
        false_positive[1][1]++;
/////////////////////////////////////////////////////////////


      hash_comp[1][2]=comp_sum(arr);
      hash_comp[1][2]=mul(hash_comp[1][2],N1);
      itr=hash_comp[1][2];

       x1=0;x2=0;

      while (true){
        

        if(key_table12[itr].key==hash_comp[1][2])
          x1=1;
        if(key_table12[itr].text==&arr[0])
          x2=1;
        
        if(key_table12[itr].key==0)
          break;
        itr=(itr+1)%N1;
        }
        //string comparisons
        string_comparison[1][2]=itr;

       
       // False Positive x1=1 && x2=0
       if(x1==1 && x2==0)
       false_positive[1][2]++;

//////////////////////////////////////////////////////////
      
      hash_comp[2][0]=poly_sum(arr);
      hash_comp[2][0]=division(hash_comp[2][0],N1);
      itr=hash_comp[2][0];

       x1=0,x2=0;

      while (true){

        if(key_table20[itr].key==hash_comp[2][0])
          x1=1;
        if(key_table20[itr].text==&arr[0])
          x2=1;
        
        if(key_table20[itr].key==0)
          break;

        itr=(itr+1)%N1;
        }
        //string comparisons
        string_comparison[2][0]=itr;
       
        // False Positive x1=1 && x2=0
        if(x1==1 && x2==0){
        false_positive[2][0]++;
       }

////////////////////////////////////////////////////////////

      hash_comp[2][1]=poly_sum(arr);
      hash_comp[2][1]=Mad(hash_comp[2][1],N1);
      itr=hash_comp[2][1];

       x1=0;x2=0;

      while (true){

        if(key_table21[itr].key==hash_comp[2][1])
          x1=1;
        if(key_table21[itr].text==&arr[0])
          x2=1;
        
        if(key_table21[itr].key==0)
          break;
        itr=(itr+1)%N1;
        }
        //string comparisons
        string_comparison[2][1]=itr;
       
      // False Positive x1=1 && x2=0
      if(x1==1 && x2==0)
      false_positive[2][1]++;
/////////////////////////////////////////////////////////////


      hash_comp[2][2]=poly_sum(arr);
      hash_comp[2][2]=mul(hash_comp[2][2],N1);
      itr=hash_comp[2][2];

       x1=0;x2=0;

      while (true){
        

        if(key_table22[itr].key==hash_comp[2][2])
          x1=1;
        if(key_table22[itr].text==&arr[0])
          x2=1;
        
        if(key_table22[itr].key==0)
          break;
        itr=(itr+1)%N1;
        }
        //string comparisons
        string_comparison[2][2]=itr;
       
      // False Positive x1=1 && x2=0
      if(x1==1 && x2==0)
      false_positive[2][2]++;

//////////////////////////////////////////////////////////

      hash_comp[3][0]=clyc_sum(arr);
      hash_comp[3][0]=division(hash_comp[3][0],N1);
      itr=hash_comp[3][0];

       x1=0,x2=0;

      while (true){

        if(key_table30[itr].key==hash_comp[3][0])
          x1=1;
        if(key_table30[itr].text==&arr[0])
          x2=1;
        
        if(key_table30[itr].key==0)
          break;

        itr=(itr+1)%N1;
        }
        //string comparisons
        string_comparison[3][0]=itr;
       
      // False Positive x1=1 && x2=0
        if(x1==1 && x2==0){
        false_positive[3][0]++;
        }

////////////////////////////////////////////////////////////

      hash_comp[3][1]=clyc_sum(arr);
      hash_comp[3][1]=Mad(hash_comp[3][1],N1);
      itr=hash_comp[3][1];

       x1=0;x2=0;

      while (true){

        if(key_table31[itr].key==hash_comp[3][1])
          x1=1;
        if(key_table31[itr].text==&arr[0])
          x2=1;
        
        if(key_table31[itr].key==0)
          break;
        itr=(itr+1)%N1;
        }
        //string comparisons
        string_comparison[3][1]=itr;
       
      // False Positive x1=1 && x2=0
      if(x1==1 && x2==0)
      false_positive[3][1]++;
/////////////////////////////////////////////////////////////


      hash_comp[3][2]=clyc_sum(arr);
      hash_comp[3][2]=mul(hash_comp[3][2],N1);
      itr=hash_comp[3][2];

       x1=0;x2=0;

      while (true){
        

        if(key_table32[itr].key==hash_comp[3][2])
          x1=1;
        if(key_table32[itr].text==&arr[0])
          x2=1;
        
        if(key_table32[itr].key==0)
        break;
        itr=(itr+1)%N1;
        }
        //string comparisons
        string_comparison[3][2]=itr+3457;
       
      // False Positive x1=1 && x2=0
      if(x1==1 && x2==0)
      false_positive[3][2]++;

//////////////////////////////////////////////////////////






        if(!pattern){
        break;
        }
        pattern>>input;
         } // while
      cout<<"False_positive:"<<endl;
      cout<<"\t"<<"\t"<<"div"<<"\t"<<"Mad"<<"\t"<<"mul"<<endl;
      cout<<"int_cast"<<"\t"<<false_positive[0][0]<<"\t"<<false_positive[0][1]<<"\t"<<false_positive[0][2]<<endl;
      cout<<"comp_sum"<<"\t"<<false_positive[1][0]<<"\t"<<false_positive[1][1]<<"\t"<<false_positive[1][2]<<endl;
      cout<<"poly_sum"<<"\t"<<false_positive[2][0]<<"\t"<<false_positive[2][1]<<"\t"<<false_positive[2][2]<<endl;
      cout<<"clyc_sum"<<"\t"<<false_positive[3][0]<<"\t"<<false_positive[3][1]<<"\t"<<false_positive[3][2]<<endl;
      cout<<"String_comparison:"<<endl;
      cout<<"\t"<<"\t"<<"div"<<"\t"<<"Mad"<<"\t"<<"mul"<<endl;
      cout<<"int_cast"<<"\t"<<string_comparison[0][0]<<"\t"<<string_comparison[0][1]<<"\t"<<string_comparison[0][2]<<endl;
      cout<<"comp_sum"<<"\t"<<string_comparison[1][0]<<"\t"<<string_comparison[1][1]<<"\t"<<string_comparison[1][2]<<endl;
      cout<<"poly_sum"<<"\t"<<string_comparison[2][0]<<"\t"<<string_comparison[2][1]<<"\t"<<string_comparison[2][2]<<endl;
      cout<<"clyc_sum"<<"\t"<<string_comparison[3][0]<<"\t"<<string_comparison[3][1]<<"\t"<<string_comparison[3][2]<<endl;


return 0;
}//main
