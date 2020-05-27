#include <bits/stdc++.h>
using namespace std;
 
int h[100005],n,k,a=0;
vector<pair<int,int>> idx;
multiset<int> segment;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%d%d",&n,&k);
    for(int i=1,j=1;j<=n;j++)
    {
        scanf("%d",&h[j]);
        segment.insert(h[j]);
        int small = *segment.begin(),big= *segment.rbegin();
        
        while(big-small>k){
            segment.erase(segment.find(h[i++]));
            small=*segment.begin();
            big=*segment.rbegin();
        }
        if(j-i+1>a){
            a=j-i+1;
            idx.clear();
        }
        if(j-i+1==a)idx.push_back(make_pair(i,j));
    }
    
    printf("%d %d\n",a,(int)idx.size());
    for(pair<int,int> id:idx)printf("%d %d\n",id.first,id.second);
    return 0;
}
