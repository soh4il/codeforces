#include <bits/stdc++.h>
#define INF 100000009
using namespace std;

int tc=1,n,d[30][30];
string s,t;

void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0;i<26;i++)
    {
        d[i][i] = 0;
        for(int j=i+1;j<26;j++)
            d[i][j] = d[j][i] = INF;
    }
}

void input()
{
    cin >> s >> t >> n;
    for(int i=0;i<n;i++)
    {
        char a,b;
        int distance;
        cin >> a >> b >> distance;
        d[a-'a'][b-'a'] = min(d[a-'a'][b-'a'],distance);
    }
}

void solve()
{   

    if(s.length()!=t.length())
    {
        puts("-1");
        return;
    }

    for (int k = 0; k < 26; ++k) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
            }
        }
    }

    int ans = 0;
    for(int i=0;i<s.length();i++)
    {
        int mn = INF;
        char to;
        for(int j=0;j<26;j++)
        {
            if(d[s[i]-'a'][j]+d[t[i]-'a'][j] < mn)
            {
                mn = d[s[i]-'a'][j]+d[t[i]-'a'][j];
                to = j+'a';
            }
        }
        if(mn == INF){
            puts("-1");
            return;
        }
        s[i] = to;
        ans += mn;
    }
    cout << ans << endl << s << endl;
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
