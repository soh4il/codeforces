#include <bits/stdc++.h>
#define SIZE 1003
using namespace std;
 
const int mod = 1e9 + 7;
 
int tc=1,n,a[30],cnt[SIZE]={0},mn[SIZE]={0},maxLen=0;
string s;
bool isValid[SIZE][SIZE];
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
void input()
{
    cin >> n >> s;
    for(int i=0;i<26;i++)
        cin >> a[i];
}
 
void solve()
{   
    cnt[0] = 1;
    mn[0] = 0;
    for(int r=1;r<=n;r++)
    {
        int mnA = r;
        mn[r] = n;
        for(int l = r-1;l>=0;l--){
            mnA = min(mnA,a[s[l] - 'a']);
            if(mnA < (r-l))
                break;
            cnt[r] = (cnt[r] + cnt[l]) % mod;
            maxLen = max(maxLen,r-l);
            mn[r] = min(mn[r],mn[l] + 1);
            //cerr << '(' << l << ',' << r << ')' << " " << cnt[r] << " " << maxLen << " " << mn[r] << endl;
        }
    }
    cout << cnt[n] << endl << maxLen << endl << mn[n] << endl;
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
