#include<bits/stdc++.h> 
#define MOD 1000000007
#define ll long long int
using namespace std;
 
int h,w,t;
int grid[1005][1005];
 
int main()
{
    cin >> h >> w;
    memset(grid,-1,sizeof(grid));
    for(int i=0;i<h;i++)
    {
        cin >> t;
        for(int j=0;j<t;j++)grid[i][j] = 1;
        grid[i][t] = 0;
    }
 
    for(int j=0;j<w;j++)
    {
        cin >> t;
        for(int i=0;i<t;i++)
        {
            if(!grid[i][j])
            {
                cout << 0 << endl;
                return 0;
            }
            grid[i][j] = 1;
        }
        if(grid[t][j] == 1)
        {
            cout << 0 << endl;
            return 0;
        }
        grid[t][j] = 0;
    }
 
    ll ans = 1;
 
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            if(grid[i][j] == -1)
                ans = (ans<<1) % MOD;
    cout << ans << endl;
    return 0;
}
