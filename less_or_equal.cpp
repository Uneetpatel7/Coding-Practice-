#include <bits/stdc++.h>
using namespace std;

//Given two unsorted arrays arr1[] and arr2[]. They may contain duplicates.
//For each element in arr1[] count elements less than or equal to it in array arr2[].

int binary_search(int arr[], int left, int right, int target){
    
    while(left<=right){
    int mid = (left+right)/2;
        if (arr[mid]<=target)
            left=mid+1;
        else
            right=mid-1;
    }
    return right;
}

void count_less_or_equal(int arr1[],int arr2[],int n_arr1,int n_arr2){
    sort(arr2,arr2+n_arr2);

    for(int i=0; i<n_arr1;i++){
        int index = binary_search(arr2,0,n_arr2-1,arr1[i]);
        	cout<<(index+1)<<" ";

    }

}




int main() {
    int arr1[]={1, 2, 3, 4, 7, 9};
    int arr2[]={0, 1, 2, 1, 1, 4};
    int n_arr1= sizeof(arr1)/sizeof(arr1[0]);
    int n_arr2= sizeof(arr2)/sizeof(arr2[0]);
    count_less_or_equal(arr1,arr2,n_arr1,n_arr2);
	return 0;
}
