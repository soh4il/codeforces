#include <bits/stdc++.h>
using namespace std;
 
int tc=1,n;
string str[300];
vector<int> kfc[150];
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
void input()
{
    cin >> n;
    for(int i=0;i<2*n-2;i++)
    {
        cin >> str[i];
        kfc[str[i].length()].push_back(i);
    }
}
 
void solve()
{
    string prefix = str[kfc[n-1][0]],suffix=str[kfc[n-1][1]];
    bool canBePrefix = prefix.substr(1) == suffix.substr(0,n-2);
 
    for(int i=1;i<n-1 && canBePrefix;i++)
        canBePrefix = (str[kfc[i][0]] == prefix.substr(0,i)) || (str[kfc[i][1]] == prefix.substr(0,i));
 
    if(!canBePrefix)
        swap(prefix,suffix);
     
    bool isPrefix[300] = {0};
    
    for(int i=1;i<n;i++){
        if(str[kfc[i][0]] == prefix.substr(0,i))
            isPrefix[kfc[i][0]] = 1;
        else
            isPrefix[kfc[i][1]] = 1;
    }
    for(int i=0;i<2*n-2;i++)cout << (isPrefix[i]?'P':'S');
    cout << endl;
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
