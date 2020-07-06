#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
ll n;
 
ll ans()
{
    bool flag = 0;
    ll p=1;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i == 0)
        {
            if(flag)return 1;
            flag = 1;
            while(n%i == 0)n/=i;
            p = i;
        }
    }
    if(n!=1){
        if(flag)return 1;
        return n;
    }
    return p;
}
 
int main()
{
    //Presetup:
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    scanf("%lld",&n);
    printf("%lld\n",ans());
    return 0;
}
