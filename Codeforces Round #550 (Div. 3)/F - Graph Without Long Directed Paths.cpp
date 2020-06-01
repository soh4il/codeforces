#include <bits/stdc++.h>
#define SIZE 200005
using namespace std;

int t=1,n,m;
vector<int> edges;
vector<vector<int>> neighbors;
bitset<SIZE> visited;
bitset<SIZE> isIn;

bool dfs(int node,bool should_be);

void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    scanf("%d%d",&n,&m);
    neighbors.resize(n+2);
    edges.resize(m);
    for(int i=0;i<m;i++)
    {
        int node2;
        scanf("%d%d",&edges[i],&node2); 
        neighbors[edges[i]].push_back(node2);
        neighbors[node2].push_back(edges[i]);
    }
}

void solve()
{
    bool ok = 1;
    for(int i=1;i<=n && ok;i++)if(!visited.test(i))ok = dfs(i,0);
    if(!ok)printf("NO\n");
    else{
        printf("YES\n");
        for(int i=0;i<m;i++)
        {
            printf("%d",!isIn.test(edges[i]));
        }
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


bool dfs(int node,bool should_be){
    if(visited.test(node))return should_be == isIn.test(node);
    visited.set(node);
    if(should_be)isIn.set(node);
    for(int neighbor:neighbors[node])if(!dfs(neighbor,!should_be))return false;
    return true;
}
