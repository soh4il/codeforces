#include <bits/stdc++.h>
#define SIZE (1<<24)
#define x first
#define y second
#define distance(ob1,ob2) ( (ob1.x - ob2.x)*(ob1.x - ob2.x) + (ob1.y - ob2.y)*(ob1.y - ob2.y) )
using namespace std;
 
int n,previous[SIZE],cost[SIZE];
pair<int,int> objects[30];
int dis[25][25];
 
int log2(int x)
{
    assert(x);
    int pw = 0;
    while(!(x&1))x>>=1,pw++;
    return pw+1;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%d%d%d",&objects[0].x,&objects[0].y,&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&objects[i].x,&objects[i].y);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            dis[i][j] = distance(objects[i],objects[j]);
    previous[0] = 0;
    memset(cost,0x3f,sizeof(cost));cost[0]=0;
    
    for(int i=0;i<(1<<n)-1;i++)
    for(int j=0;j<n;j++)if(!(i&(1<<j)))
    {
        for(int k=j;k<n;k++)if(!(i&(1<<k)))
        {
            int p = i | (1<<j) | (1<<k);
            int temp = cost[i] + dis[0][j+1] + dis[j+1][k+1] + dis[k+1][0];
            if(temp < cost[p])
            {
                cost[p] = temp;
                previous[p] = i;
            }
        }
        break;
    }
 
    printf("%d\n0",cost[(1<<n) - 1]);
    for(int i=(1<<n) - 1;i;i=previous[i])
    {
        for(int j = i - previous[i];j;j-=j&-j)
            printf(" %d",log2(j&-j));
        printf(" 0");
    }
    printf("\n");
    return 0;
}
