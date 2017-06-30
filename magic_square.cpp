#include <bits/stdc++.h>
using namespace std;

void Generate_Square(int n){
	int i=n/2;
	int j=n-1;
	int counter=1;
	int square[n][n];
	memset(square, 0, sizeof(square));

	while(counter<=n*n){
		//cout<<"enter "<< i << " "<< j;
		
		square[i][j]=counter;
		i--;
		j++;

		if((i==-1) && (j==n)){
			cout<<"hi";
			i=0;j=n-2;}
		//cout<<"\t"<<"medium1 "<< i << " "<< j;
		i=(n+i)%n;
		j=(n+j)%n;
		//cout<<"\t"<<"medium2 "<< i << " "<< j;
		
		if(square[i][j]!=0){
			i++;j-=2;
		}
		
		//cout<<"\t"<<"exit "<< i << " "<< j<<endl;
		counter++;
	}

printf("The Magic Square for n=%d:\nSum of each row or column %d:\n\n",
			n, n*(n*n+1)/2);
	for(int x=0; x<n; x++)
	{
		for(int y=0; y<n; y++)
			printf("%3d ", square[x][y]);
		printf("\n");
	}

}


int main(){
	int n=7;
	Generate_Square(n);
	return 0;
}