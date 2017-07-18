
/////////////// catalan number using dynamic programing //////////////////////////////

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli catalan_number(unsigned int n)
{
  lli catalan[n+1];
  catalan[0]=1;
  catalan[1]=1;
  for (int i=2; i<=n; i++)
  {
    catalan[i]=0;
    for (int j=0; j<i; j++)
      catalan[i] += catalan[j]*catalan[i-j-1];
  }
  return catalan[n];
}

int main(){

  cout<< "The 10th catalan number is:" << catalan_number(10) <<endl;

  return 0;  
}
