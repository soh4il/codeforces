#include<bits/stdc++.h>
using namespace std;
 
int n,m,x,y,isZero = 0;
int dp[1003][1003][2];
char dir[1003][1003][2];
void cnt25(int x,int i,int j)
{
    dp[i][j][0] = 0;
    dp[i][j][1] = 0;
    while(x%2 == 0){
        dp[i][j][0]++;
        x/=2;
    }
    while(x%5 == 0){
        dp[i][j][1]++;
        x/=5;
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&m);
            if(!m)
            {
                isZero = 1;
                x = i;
                y = j;
                m=10;
            }
            cnt25(m,i,j);
 
            if(i&&j){
                if(dp[i-1][j][0] < dp[i][j-1][0])
                {
                    dp[i][j][0] += dp[i-1][j][0];
                    dir[i][j][0] = 'D';
                }
                else
                {
                    dp[i][j][0] += dp[i][j-1][0];
                    dir[i][j][0] = 'R';
                }
                if(dp[i-1][j][1] < dp[i][j-1][1])
                {
                    dp[i][j][1] += dp[i-1][j][1];
                    dir[i][j][1] = 'D';
                }
                else
                {
                    dp[i][j][1] += dp[i][j-1][1];
                    dir[i][j][1] = 'R';
                }   
            }
            else if(i){
                dp[i][j][0] += dp[i-1][j][0];
                dp[i][j][1] += dp[i-1][j][1];
                dir[i][j][0] = 'D';
                dir[i][j][1] = 'D';
            }
            else if(j){
                dp[i][j][0] += dp[i][j-1][0];
                dp[i][j][1] += dp[i][j-1][1];    
                dir[i][j][0] = 'R';
                dir[i][j][1] = 'R';
            }
        }
    }
    int k = dp[n-1][n-1][1] < dp[n-1][n-1][0];
    if(isZero && dp[n-1][n-1][k]){
        cout << 1 << endl;
        for(int i=0;i<x;i++)cout << 'D';
        for(int i=0;i<y;i++)cout << 'R';
        for(int i=x;i<n-1;i++)cout << 'D';
        for(int i=y;i<n-1;i++)cout << 'R';
        return 0;
    }
    cout << dp[n-1][n-1][k] << endl;
    string ans;
    for(int i=n-1,j=n-1;i||j;)
    {
        ans += dir[i][j][k];
        if(dir[i][j][k] == 'D')i--;
        else j--;
    }
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
    return 0;   
}
