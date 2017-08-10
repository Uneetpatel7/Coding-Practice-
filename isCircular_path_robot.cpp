/*  Given a sequence of moves for a robot, check if the sequence is circular or not. A sequence of moves is circular if first and last positions of robot are same. A move can be on of the following.
    
    G - Go one unit
    L - Turn left
    R - Turn right
*/
#include <bits/stdc++.h>
using namespace std;
#define N 0
#define E 1
#define S 2
#define w 3

bool isCircular{
    int x=0;
    int y=0;
    int direction = N;
    
    for (int i=0; path[i]; i++){
        if (path[i] == 'R'){
            direction = (direction + 1) % 4;
        }
        else if (path[i] == 'L'){
            direction = (4 + direction - 1) % 4;
        }
        else {
            if (direction == N)
            y++;
         else if (direction == E)
            x++;
         else if (direction == S)
            y--;
         else 
            x--; 
        }
        
    }
return (x==0 && y==0)    
}

int main()
{
    char path[] = "GLGLGLG";
    if (isCircular(path))
      cout << "Given sequence of moves is circular";
    else
      cout << "Given sequence of moves is NOT circular";
}
