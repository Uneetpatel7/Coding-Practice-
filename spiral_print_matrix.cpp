/* ******************Print the matrix spirally******************** */

#include <iostream>
using namespace std;

void traverse_spiral(int arr[4][4]){
    int n=4;
    int x1=0, x2=n-1, y1=0, y2= n-1;
    int i=0; int j=0;
    while (x1<x2 && y1<y2){
        
        for ( j=y1; j<=y2; j++ ){
            cout<<arr[i+1][j]<<" ";    
        }
        //cout << j <<endl;
        for ( i=x1+1 ; i<=x2 ; i++){
            cout<<arr[i][j-1]<<" ";
        }
        
        for (j= y2-1; j>=y1; j--){
            cout<<arr[i-1][j]<<" ";
        }
       // cout << i << j << "hey " <<endl;
        for (i= x2-1; i>x1; i--){
            cout<<arr[i][j+1]<<" ";
        }
    x1++;
    x2--;
    y1++;
    y2--;
    }
    
}

int main() {
	
	int arr[4][4];
    	int i,j,m,n,t,iterations;
     	scanf("%d",&iterations);
    	for(t=0 ; t<iterations ; t++)
    	{
        	for(i=0;i<4;i++)
        	{
        	    for(j=0 ; j<4 ; j++)
        	    {
                    scanf("%d",&arr[i][j] );	 
        	    }
        	}
        	
        	traverse_spiral(arr);
        	cout<< endl;
    	}
}
