#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
int g(int x,int n)
{
    int res = 0,zeros = 0;
    for(int i=1;i<=n;i<<=1)
    {
        if(i&n)
        {
            n^=i;
            if(!(x&n))res += 1 << zeros;
        }
        if(!(x&i))zeros++;
    }   
    return res;
}
 
ll f(int l,int r)
{
    if(l == r)return 0;
    if(l == 0)return 2 * r - 1 + f(1,r);
    ll res = 0;
    if(l&1)
    {
        res = 2 * ( g(l,r) - g(l,l) );
        l++;
    }
    if(r&1)res += 2 * ( g(r-1,r) - g(r-1,l) );
    return res + 3 * f(l/2,r/2);
}
 
int t,l,r;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&l,&r);
        printf("%lld\n",f(l,r+1));
    }
    return 0;   
}
