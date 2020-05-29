#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll t=1,a,b,ab;

bool dfs(int node,bool should_be);

void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    scanf("%lld%lld%lld",&a,&b,&ab);
    ll ans = 2 * (min(a,b)+ab);
    ans += (int)!(a==b);
    printf("%lld\n",ans);
}

void solve()
{
    
}

int main()
{
    preprocess();
    while(t--)
    {
        input();
        solve();
    }
    return 0;
}
