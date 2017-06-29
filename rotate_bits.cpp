#include<stdio.h>
#define INT_BITS 32
 
int leftRotate(int n, unsigned int rotate)
{
  
   return (n << rotate)|(n >> (INT_BITS - rotate));
}
 
int rightRotate(int n, unsigned int rotate)
{
   return (n >> rotate)|(n << (INT_BITS - rotate));
}
 

int main()
{
  int n = 16;
  int rotate = 2;
  printf("Left Rotation of %d by %d is ", n, rotate);
  printf("%d", leftRotate(n, rotate));
  printf("\nRight Rotation of %d by %d is ", n, rotate);
  printf("%d", rightRotate(n, rotate));
  getchar();
} 