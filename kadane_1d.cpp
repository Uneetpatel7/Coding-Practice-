#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(int a[], int size)
{
int max_so_far = a[0];
int curr_max = a[0];
int start=0;
int end=0;
queue<int> q;
q.push(a[0]);
for (int i = 1; i < size; i++)
{
		//curr_max = max(a[i], curr_max+a[i]);
		if (a[i] >= curr_max + a[i] ){
		    curr_max = a[i];
		    start = i;
		    q.push(a[i]);
		    q.pop();
		}
		else {
		    curr_max = curr_max + a[i];
		    q.push(a[i]);
		}
		
		
		
		//max_so_far = max(max_so_far, curr_max);
		if (max_so_far >= curr_max){
		    max_so_far = max_so_far;
		}
		else{ 
		    max_so_far = curr_max;
		    end = i;
		
		    
		}
}
cout << "The starting and ending indexes are : " << start << " ," << end << endl; 
return max_so_far;
}

/* Driver program to test maxSubArraySum */
int main()
{
int a[] = {-2, -3, 4, -1, -2, 1, 5, -3, -2, 11};
int n = sizeof(a)/sizeof(a[0]);
int max_sum = maxSubArraySum(a, n);
cout << "Maximum contiguous sum is " << max_sum;
return 0;
}
