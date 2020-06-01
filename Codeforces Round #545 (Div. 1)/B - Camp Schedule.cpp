#include <bits/stdc++.h>
using namespace std;
 
string s,t;
 
int z_function(string str) {
    int n = (int) str.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && str[z[i]] == str[i + z[i]])
            ++z[i];
        if(i + z[i] == n)return i;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return n;
}
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
void input()
{
    cin >> s >> t;
}
 
void solve()
{
    int cnt[2]={0};
    for(char c:s)cnt[c-'0']++;
    int m = z_function(t);
    int n = s.length();
    for(int i=0;i<n;i++)
    {
        bool val = t[i%m] - '0';
        if(cnt[val]){
            cout << val;
            cnt[val]--;
        }else{
            cout << (!val);
            cnt[!val]--;
        }
    }
    cout << endl;
}
 
int main()
{
    preprocess();
    input();
    solve();
 
    return 0;
}
