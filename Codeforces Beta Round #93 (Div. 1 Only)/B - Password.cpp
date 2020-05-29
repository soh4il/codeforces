#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
int t=1,n;
string str;
ll p_pow[1000006],hash_value[1000006]={0},inv[1000006];
const ll mod = (ll) 1e9 + 9;
 
ll exp(ll b, ll e){
    ll ans=1;
 
    while(e){
        if(e&1)  ans= (ans*b) % mod;
        b= (b*b) % mod;
        e/= 2;
    }
 
    return ans;
}
 
bool equalPrefix(int l,int r)
{
    return (((hash_value[r] - hash_value[l] + mod) % mod ) * inv[l]) % mod == hash_value[r-l];
}
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    const int p = 31;
    p_pow[0] = 1;
    for(int i=1;i<=1000000;i++)
    {
        p_pow[i] = (p_pow[i-1] * p) % mod;
        inv[i] = exp(p_pow[i],mod-2);
    }
}
 
void input()
{
    cin >> str;
}
 
void solve()
{
    n = str.length();
    hash_value[0] = 0;
    for (int i=1;i<=n;i++) 
        hash_value[i] = (hash_value[i-1] + (str[i-1] - 'a' + 1) * p_pow[i]) % mod;
    
    vector<int> lens;
    for(int len=1;len<n-1;len++)if(equalPrefix(n-len,n))lens.push_back(len);
 
    int r = lens.size(),l = 0,long_len=-1;
    while(l < r){
        int mid = (l+r-1)/2;
        bool found = 0;
        for(int i=1;i<n-lens[mid] && !found;i++)found = equalPrefix(i,i+lens[mid]);
        if(found)
        {
            l = mid+1;
            long_len = lens[mid];
        }
        else r = mid-1;
    }
 
    if(long_len == -1)cout << "Just a legend\n";
    else cout << str.substr(0,long_len) << endl;
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
