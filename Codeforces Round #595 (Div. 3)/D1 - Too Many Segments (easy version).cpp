#include<bits/stdc++.h>
#define N 250
#define inRange(i,p) (ranges[p].first <=i && i <= ranges[p].second)
#define farer(p,pos) (pos == -1 || ranges[pos].second < ranges[p].second )
using namespace std;
 
int cnt[N] = {0};
int n,k,m;
pair<int,int> ranges[N];
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%d%d",&n,&k);
    memset(cnt,0,sizeof(int)*(n+5));
    for(int i=0;i<n;i++)
    {
         scanf("%d%d",&ranges[i].first,&ranges[i].second);
         cnt[ranges[i].first]++;
         cnt[ranges[i].second + 1]--;
    }   
    for(int i=1;i<N;i++)cnt[i] += cnt[i-1];
 
    vector<bool> removed(n+1,0);
    m = 0;
    for(int i=0;i<N;i++)
    {
        while(cnt[i]>k)
        {
            int pos = -1;
            for(int p=0;p<n;p++)
                if(!removed[p] && inRange(i,p) && farer(p,pos))
                    pos = p;
            //assert(pos != -1);
            for(int j=ranges[pos].first;j<=ranges[pos].second;j++)
                cnt[j]--;
            removed[pos] = 1;
            m++;
        }
    }
    printf("%d\n",m);
    for(int p=0;p<n;p++)
        if(removed[p])
            printf("%d ",p+1);
    printf("\n");
    return 0;   
}
