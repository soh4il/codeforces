#include<bits/stdc++.h>
#define ll long long int
#define mod (int)(1e9 + 7)
using namespace std;
 
ll f(ll x)
{
    ll m=0,n=0,*p=&m,*temp=&n;
    for(ll i=1;i<=x;i<<=1)
    {
        *p = (*p + i) % mod;
        x-=i;
        swap(p,temp);
    }
    *p = (*p + x) % mod;
    return (( n * (n+1) % mod ) + ( m * m % mod ) ) % mod;
}
 
ll l,r;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%lld%lld",&l,&r);
    printf("%lld\n",(f(r) - f(l-1) + mod) % mod);    
    return 0;   
}
