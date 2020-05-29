
#include <bits/stdc++.h>
#define SIZE 100005
#define ll long long int
using namespace std;
 
int t=1,n,q;
vector<ll> s,miss,prefix;
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
void input()
{
    scanf("%d",&n);
    s.resize(n);
    for(int i=0;i<n;i++)scanf("%lld",&s[i]);
}
 
void solve()
{
    sort(s.begin(),s.end());
    for(int i=1;i<n;i++)if(s[i]-s[i-1])miss.push_back(s[i]-s[i-1]-1);
    sort(miss.begin(),miss.end());
    ll m = miss.size(),dist = m+1;
    prefix.resize(m);
    if(m)prefix[0] = miss[0];
    for(int i=1;i<m;i++)prefix[i] = prefix[i-1] + miss[i];
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        ll l,r,diff;
        scanf("%lld%lld",&l,&r);
        diff = r-l;
        vector<ll>::iterator it = lower_bound(miss.begin(),miss.end(),diff);
        if(it == miss.begin()){
            printf("%lld ",dist + (m+1) * diff);
            continue;
        }
        ll idx = it - miss.begin() - 1LL;
        ll res = dist + prefix[idx] + ((m-idx) * diff);
        printf("%lld ",res);
    }
    printf("\n");
}
 
int main()
{
    preprocess();
    while(t--){
        input();
        solve();
    }
    return 0;
}
