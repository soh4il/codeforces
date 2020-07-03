#include<bits/stdc++.h>
using namespace std;
 
int n,m,d,check,gaps;
int c[1003];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    cin >> n >> m >> d;
    check = (m+1) * (d-1);
    gaps = n;
    int sum = 0;
    for(int i=0;i<m;i++)
    {
        cin >> c[i];
        gaps -= c[i];
    }
    
    if(gaps > check)return cout << "NO\n",0;
    cout << "YES\n";
    int curr = 0;
    for(int i=0,g=min(gaps,d-1);i<m;i++,g=min(gaps,d-1))
    {
        for(int j=curr;j<curr+g;j++)
            cout << 0 << " ";
        gaps -= g;
        curr += g;
        for(int j=curr;j<curr+c[i];j++)
            cout << (i+1) << " ";
    }
    for(int i=0;i<gaps;i++)cout << 0 << " ";
    cout << endl;
    
    return 0;   
}
