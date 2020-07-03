#include <bits/stdc++.h>
using namespace std;
 
int q,n;
string s,t;
 
int solve()
{
    int freq1[30]={0},freq2[30]={0};
    for(int i=0;i<n;i++)
    {
        freq1[s[i]-'a']++;
        freq2[t[i]-'a']++;
    }
    bool more = 0;
    for(int i=0;i<26;i++)
    {
        if(freq1[i]!=freq2[i])return cout << "NO\n",0;
        if(freq1[i] > 1)more = 1;
    }
    if(more)return cout << "YES\n",0;
    int sw1 = 0,sw2 = 0;
    for(int i=n-1;i>0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(s[j] > s[j+1]){
                sw1++;
                swap(s[j],s[j+1]);
            }
            if(t[j] > t[j+1]){
                sw2++;
                swap(t[j],t[j+1]);
            }
        }
    }
    cout << (sw1%2 == sw2%2 ? "YES":"NO") << endl;
}
 
int main()
{
    //Presetup:
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //-------------------------------
    cin >> q;
    while(q--)
    {
        cin >> n >> s >> t;
        solve();
    }
    return 0;
}
