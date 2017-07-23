//Given a positive integer n, count the total number of set bits in binary representation of all numbers from 1 to n.
#include <bits/stdc++.h>
using namespace std;

unsigned int count_set_bits(unsigned int x){
    unsigned int count=0;
    while(x>0){
        if((x & 1)==1){
            count++;
        }
    x=x>>1;
    }
    return count;
}


int total_set_bits(unsigned int x){
    int setBits=0;
    for (unsigned int i=1; i<=x; i++){
        setBits += count_set_bits(i); 
    }
    return setBits;
}



int main() {
    unsigned int n=8;
	cout<< total_set_bits(n);
	return 0;
}
