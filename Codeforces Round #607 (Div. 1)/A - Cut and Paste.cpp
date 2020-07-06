#include <bits/stdc++.h>
#define ll unsigned long long int
#define mod (ll)(1e9 + 7)
using namespace std;
 
ll t,x,len,curr_len;
char s[1000006];
ll solve()
{
    curr_len = len = strlen(s+1);
    for(ll l=1;l<=x;l++)
    {
        ll sl = (s[l] - '0'),dl = (len - l);
        ll mul = (sl-1) * (dl + mod);
        len = (len + mul) % mod;
        if(curr_len <= x+1)for(ll i=0;i< (sl-1) * dl && curr_len < x+1;i++)
        {
            curr_len++;
            s[curr_len] = s[curr_len - dl];
        }
    }
    printf("%lld\n",len);
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%s",&x,s+1);
        solve();
    }
    return 0;
}
