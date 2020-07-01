#include <bits/stdc++.h>
#define scn(x) scanf("%lld",&x)
#define mod 1000000007
#define ll long long int
using namespace std;

ll a,b;
ll fb[100005];


int main()
{
    //Presetup:
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fb[0] = fb[1] = 1;
    for(int i=2;i<=100000;i++)
        fb[i] = (fb[i-1]+fb[i-2]) % mod;
    //--------------------------
    scn(a);scn(b);
    ll ans = (fb[a]+fb[b]-1) % mod;
    ans = (ans * 2) % mod;
    printf("%lld",ans);
    
    return 0;
}
