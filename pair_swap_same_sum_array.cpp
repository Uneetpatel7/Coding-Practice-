#include <bits/stdc++.h>
using namespace std;


void swap(int A[],int B[],int nA, int nB){

	sort(A,A+nA);
	sort(B,B+nB);
	int sumA=0;
	int sumB=0;
	for(int x=0;x<nA;x++){
		sumA= sumA+A[x];
	}

	for(int y=0;y<nB;y++){
		sumB= sumB+B[y];
	}

	// if((sumA - sumB)%2!=0){
	// 	cout<< "enter the valid arrays:"<<endl;
	// 	return;
	// }

	 int diff = (sumA - sumB);

	 int i=0;
	 int j=0;

	 while( i<nA && j<nB){

	 	if((A[i]-B[j])== diff){
	 		cout<< "swap " <<A[i]<< " " <<B[j]<< endl;
	 		return;
	 	}

	 	else if((A[i]-B[j]) < diff)
	 		i++;

	 	else
	 		j++;
	 }

}



int main(){
	int A[] = { 4, 1, 2, 1, 1, 2 };
    int nA = sizeof(A) / sizeof(A[0]);
    int B[] = { 3, 6, 3, 3 };
    int nB = sizeof(B) / sizeof(B[0]);
    swap(A,B,nA,nB);
    return 0;
}