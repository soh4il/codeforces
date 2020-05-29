#include <bits/stdc++.h>
#define ll long long int
#define SIZE 2000
using namespace std;
 
int t=1,n,k;
bool isGood[30]={0};
string str;
string goodArray;
ll p_pow[SIZE],hash_value[SIZE]={0};
int prefix[SIZE] = {0};
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    const int p = 1000000007;
    p_pow[0] = 1;
    for(int i=1;i<SIZE;i++)
        p_pow[i] = p_pow[i-1] * p;
}
 
void input()
{
    cin >> str >> goodArray >> k;
}
 
void solve()
{
    n = str.length();
    for(int i=0;i<26;i++)
        isGood[i] = goodArray[i] - '0';
 
    for(int i=1;i<=n;i++)
        prefix[i] = prefix[i-1] + 1-isGood[str[i-1]-'a'];
 
    int ans = 0;
    set<ll> goodSubstrings[n+2];
    for(int l=0;l<n;l++)
    {
        ll hash = 0;
        for(int len=1;l+len<=n;len++)
        {    
            hash = hash + (str[l+len-1] - 'a' + 1) * p_pow[len-1];
            if(prefix[l+len] - prefix[l] <= k)
                goodSubstrings[len].insert(hash);
        }
            
    }
    for(int i=1;i<=n;i++)ans+=(int)goodSubstrings[i].size();
    printf("%d\n",ans);
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
