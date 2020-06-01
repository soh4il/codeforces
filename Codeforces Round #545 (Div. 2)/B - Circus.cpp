
#include <bits/stdc++.h>
using namespace std;
 
int t=1,n;
string str1,str2;
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
void input()
{
    cin >> n >> str1 >> str2;
}
 
void solve()
{
    vector<int> clowns,acrobats,both,others;
    for(int i=0;i<n;i++)
    {
        if(str1[i] == '1' && str2[i] == '0')clowns.push_back(i+1);
        else if(str1[i] == '0' && str2[i] == '1')acrobats.push_back(i+1);
        else if(str1[i] == '1' && str2[i] == '1')both.push_back(i+1);
        else others.push_back(i+1);
    }
    int na = others.size(),nb= acrobats.size(),nc = clowns.size(),nd = both.size();
    bool ok=false;
    int a,b,c,d;
    for(c=0;c<=nc;c++){
        for(d=0;d<=nd;d++){
            b = nb+nd-c-2*d;
            ok = (0 <= b && b <= nb) && (c+b+d <= n/2) && ((a = n/2 - b - c - d) <= na);
            if(ok)break;
        }
        if(ok)break;
    }
    if(!ok)cout << -1 << endl;
    else {
        for(int i=0;i<a;i++)cout << others[i] << " ";
        for(int i=0;i<b;i++)cout << acrobats[i] << " ";
        for(int i=0;i<c;i++)cout << clowns[i] << " ";
        for(int i=0;i<d;i++)cout << both[i] << " ";
        cout << endl;
    }
}
 
int main()
{
    preprocess();
    while(t--)
    {
        input();
        solve();
    }
    return 0;
}
