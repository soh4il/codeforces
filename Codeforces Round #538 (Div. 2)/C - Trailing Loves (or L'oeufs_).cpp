#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
ll n,b,ans = INT64_MAX,cnt1,cnt2;
 
void calc(ll i)
{
    cnt1=cnt2=0;
    while(b%i == 0){b/=i;cnt1++;}
    if(cnt1)
    {
        for(ll j=1;j<=n/i;){j*=i;cnt2+=n/j;}
        ans = min(ans,cnt2/cnt1);
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%lld%lld",&n,&b); 
    for(ll i=2;i*i<=b;i++)calc(i);
    if(b!=1)calc(b);
    printf("%lld\n",ans);
 
    return 0;   
}
