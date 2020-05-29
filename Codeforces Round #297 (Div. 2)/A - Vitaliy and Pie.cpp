#include <bits/stdc++.h>
using namespace std;
 
int tc=1,n;
string s;
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
void input()
{
    cin >> n >> s;
}
 
void solve()
{   
    int cnt[30] = {0};
    int ans = 0;
    n = (n-1) << 1;
    for(int i=0;i<n;i++)
    {
        if(i%2){
            if(cnt[s[i]-'A'])
                cnt[s[i]-'A']--;
            else
                ans++;
        }else
            cnt[s[i]-'a']++;
    }
    cout << ans << endl;
}
 
int main()
{
    preprocess();
    while(tc--){
        input();
        solve();
    }
    return 0;
}
