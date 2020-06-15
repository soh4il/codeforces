#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
ll n,w,d,p;
 
int main()
{
    cin >> n >> p >> w >> d;
    for(ll y=0,x=(p-d*y)/w;y<w;y++,x=(p-d*y)/w)
        if((p-d*y)%w == 0&& x>=0 && x+y<=n)
            return 0&printf("%lld %lld %lld\n",x,y,n-x-y);
    return 0&printf("-1\n");
}
