
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
 
string s;
int dp[100005];
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    cin >> s;
    dp[0] = 1;
    if(s.find('m') != -1 || s.find('w') != -1)return cout << 0 << endl,0;
    for(int i=1;i<=s.length();i++)
    {
        if(i!=1&&s[i-1] == s[i-2] && (s[i-1] == 'u' || s[i-1] == 'n'))
            dp[i] = (dp[i-2] + dp[i-1]) % mod;
        else
            dp[i] = dp[i-1];
    }
    cout << dp[s.length()] << endl;
    return 0;   
}
