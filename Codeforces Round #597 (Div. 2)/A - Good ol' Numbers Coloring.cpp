#include<bits/stdc++.h>
using namespace std;
 
int t,a,b;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        if(__gcd(a,b) != 1)
            printf("Infinite\n");
        else printf("Finite\n");
    }
    return 0;   
}
