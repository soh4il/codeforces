#include<bits/stdc++.h>
using namespace std;
 
int x,y;
 
int main()
{
    scanf("%d%d",&x,&y);
    if(x == y)
        printf("%d0 %d1\n",x,y);
    else if(x+1 == y)
        printf("%d %d\n",x,y);
    else if(x == 9 && y == 1)
        printf("9 10\n");
    else
        printf("-1\n");
    return 0;
}
