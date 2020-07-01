#include<bits/stdc++.h>
#define N 200005
using namespace std;
 
int cnt[N] = {0};
int n,k,m,sub;
pair<int,int> ranges[N];
vector<int> rangeStarts[N];
vector<int> rangeEnds[N];
int subChange[N] = {0};
 
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
         rangeStarts[ranges[i].first].push_back(i);
         rangeEnds[ranges[i].second+1].push_back(i);
    }   
    for(int i=1;i<N;i++)cnt[i] += cnt[i-1];
 
    vector<bool> removed(n+1,0);
    set<pair<int,int>> currRanges;
    m = 0;
    for(int i=0;i<N;i++)
    {
        for(int index:rangeStarts[i])currRanges.insert(make_pair(ranges[index].second,index));
        for(int index:rangeEnds[i])
        {
            set<pair<int,int>>::iterator it = currRanges.find(make_pair(ranges[index].second,index));
            if(it != currRanges.end())currRanges.erase(it);
        }
 
        sub += subChange[i];
        while(cnt[i] - sub >k)
        {
            set<pair<int,int>>::iterator it = prev(currRanges.end());
            int pos = it->second;
            currRanges.erase(it);
            sub++;
            subChange[ranges[pos].second+1]--;
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
