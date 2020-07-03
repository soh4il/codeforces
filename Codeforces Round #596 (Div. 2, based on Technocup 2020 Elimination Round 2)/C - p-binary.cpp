#include<bits/stdc++.h>
using namespace std;
 
int n,p;
int main()
{
    scanf("%d%d",&n,&p);
    for(int i=1;i<32;i++)
        if(__builtin_popcount(n-i*p) <= i && n-i*p >= i)
            return 0&printf("%d\n",i);
    return 0&printf("-1\n");
}
