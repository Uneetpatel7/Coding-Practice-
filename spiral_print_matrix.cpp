/* ******************Print the matrix spirally******************** */

#include <iostream>
using namespace std;

void traverse_spiral(int arr[4][4]){
    int n=4;
    int x1=0, x2=n-1, y1=0, y2= n-1;
    //x1 and x2 are the left and right bound to of traversal respectively
    //y1 and y2 are the upper and lower bound of the traversal respectively
    int i=0; int j=0;
    while (x1<x2 && y1<y2){
        
        for ( j=y1; j<=y2; j++ ){
            cout<<arr[i][j]<<" ";    
        }
        
        for ( i=x1+1 ; i<=x2 ; i++){
            cout<<arr[i][j]<<" ";
        }
        
        for (j= y2-1; j>=y1; j--){
            cout<<arr[i][j]<<" ";
        }
        
        for (i= x2-1; i>x1; i--){
            cout<<arr[i][j]<<" ";
        }
    x1++; //moving left bound one step right
    x2--; //moving right bound one step left
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
        	
    	}
}
