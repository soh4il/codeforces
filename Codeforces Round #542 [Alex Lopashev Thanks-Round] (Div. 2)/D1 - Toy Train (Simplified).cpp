#include <bits/stdc++.h>
#define SIZE 5003
using namespace std;

int t=1,n,m,cnt[SIZE]={0},mn[SIZE]={0};

int distance(int src,int dest){
    if(dest < src)return (n-src) + dest;
    return dest - src;
}

void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)mn[i] = n+10;
    for(int i=0;i<m;i++)
    {
        int s,d;
        scanf("%d%d",&s,&d);
        cnt[s]++;
        mn[s] = min(mn[s],distance(s,d));
    }

}

void solve()
{
    for(int s=1;s<=n;s++)
    {
        int tm = 0;
        for(int i=1;i<=n;i++)if(cnt[i])tm = max(tm,distance(s,i) + (cnt[i]-1) * n + mn[i]);
        printf("%d ",tm);
    }
    printf("\n");
}

int main()
{
    preprocess();
    while(t--){
        input();
        solve();
    }
    return 0;
}
