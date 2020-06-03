#include <bits/stdc++.h>
#define SIZE 200005
using namespace std;
 
int t=1,n,m;
vector<vector<int>> neighbors(SIZE);
bitset<SIZE> visited;
vector<pair<int,int>> cntEdges;
vector<int> ans;
vector<int> notans;
 
void bfs(int idx);
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    scanf("%d",&t);
}
 
void input()
{
    visited.reset();
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)neighbors[i].clear();
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        scanf("%d%d",&v1,&v2);
        neighbors[v1].push_back(v2);
        neighbors[v2].push_back(v1);
    }
}
 
void solve()
{
    ans.clear();
    notans.clear();
    cntEdges.clear();
    for(int i=1;i<=n;i++)cntEdges.push_back(make_pair(neighbors[i].size(),i));
    sort(cntEdges.begin(),cntEdges.end(),greater<pair<int,int>>());
    for(int i=0;i<n;i++)if(!visited.test(cntEdges[i].second))bfs(cntEdges[i].second);
    if(ans.size() <= n/2){
        printf("%d\n",(int)ans.size());
        for(int vertix:ans)printf("%d ",vertix);
        printf("\n");
    }else{
        printf("%d\n",(int)notans.size());
        for(int vertix:notans)printf("%d ",vertix);
        printf("\n");
    }
}
 
int main()
{
    preprocess();
    while(t--)
    {
        input();
        solve();
    }
    return 0;
}
 
 
void bfs(int idx){
    visited.set(idx);
    ans.push_back(idx);
    for(int neighbor:neighbors[idx])if(!visited.test(neighbor)){
        notans.push_back(neighbor);
        visited.set(neighbor);
    }
}
