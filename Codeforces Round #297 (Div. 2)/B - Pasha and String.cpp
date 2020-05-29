#include <bits/stdc++.h>
#define SIZE 100005
using namespace std;

int tc=1,n,m,swaps[SIZE]={0};
string s;

void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    cin >> s >> m;
    n = s.length();
    for(int i=0;i<m;i++)
    {
        int temp;
        cin >> temp;
        swaps[temp]++;
    } 
}

void solve()
{   
    for(int i=1;i<=n/2;i++)
        swaps[i] += swaps[i-1];
    for(int i=0;i<n/2;i++)
        if(swaps[i+1]%2)
            swap(s[i],s[n-i-1]);
    cout << s << endl;
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
