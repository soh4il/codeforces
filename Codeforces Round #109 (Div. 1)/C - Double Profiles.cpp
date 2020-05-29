#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int t=1;
int n,m;
vector<vector<bool>> isFriend;
ll p_pow[1000006];
ll hash_value[1000006]={0};

void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    const int p = 3;
    p_pow[0] = 1;
    for(int i=1;i<=1000000;i++)p_pow[i] = (p_pow[i-1] * p);
}

void input()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        x--;y--;
        hash_value[x] += p_pow[y];
        hash_value[y] += p_pow[x];
    }
}

void solve()
{
    map<ll,int> cnt;
    for(int i=0;i<n;i++){
        cnt[hash_value[i]]++;
        cnt[hash_value[i] + p_pow[i]]++;
    }
    ll ans = 0;
    for(auto it=cnt.begin();it!=cnt.end();it++)
        for(ll i=1;i<it->second;i++)
            ans+=i;
    printf("%lld\n",ans);
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
