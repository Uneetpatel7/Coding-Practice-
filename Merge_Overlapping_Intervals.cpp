/*Given a set of time intervals in any order, merge all overlapping intervals into one and output the result which should have only mutually exclusive intervals. 
Let the intervals be represented as pairs of integers for simplicity.*/


#include<bits/stdc++.h>
using namespace std;
 

struct Interval
{
    int s, e;
};
 
bool mycomp(Interval a, Interval b)
{   return a.s > b.s; }
 
void mergeIntervals(Interval arr[], int n)
{
    sort(arr, arr+n);
 
    int index = 0; // Stores index of last element
 
    for (int i=0; i<n; i++)
    {
        if (index != 0 && arr[index-1].s <= arr[i].e)
        {
            while (index != 0 && arr[index-1].s <= arr[i].e)
            {
                // Merge previous and current Intervals
                arr[index-1].e = max(arr[index-1].e, arr[i].e);
                arr[index-1].s = min(arr[index-1].s, arr[i].s);
                index--;
            }
        }
        else // Doesn't overlap with previous, add to
            // solution
            arr[index] = arr[i];
 
        index++;
    }
 
    cout << "\n The Merged Intervals are: ";
    for (int i = 0; i < index; i++)
        cout << "[" << arr[i].s << ", " << arr[i].e << "] ";
}
 
int main()
{
    Interval arr[] =  { {6,8}, {1,9}, {2,4}, {4,7} };
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeIntervals(arr, n);
    return 0;
}
