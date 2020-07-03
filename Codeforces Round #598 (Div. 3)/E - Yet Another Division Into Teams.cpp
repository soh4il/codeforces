#include<bits/stdc++.h>
#define skill first
#define index second
#define INF (int)(1e9)+9
using namespace std;

int n,diff,cnt;
pair<int,int> a[200005];
int dp[200005];
int parent[200005];
int team[200005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].skill);
        a[i].index = i;
    }
    sort(a,a+n);
    for(int i = 1; i <= n; i++)
    {
    	dp[i] = INF;
    	parent[i] = -1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=3;j<=5&&i+j<=n;j++)
        {
            diff = a[i+j-1].skill - a[i].skill;
            if(dp[i+j] > dp[i]+diff)
            {
                dp[i+j] = dp[i]+diff;
                parent[i+j] = i;
            }
        }
    }
    cnt = 0;
    for(int i=n;i;i=parent[i],cnt++)
        for(int j=i-1;j>=parent[i];j--)
            team[a[j].index] = cnt+1;

    printf("%d %d\n%d",dp[n],cnt,team[0]);
    for(int i=1;i<n;i++)printf(" %d",team[i]);
    printf("\n");
    return 0;   
}
