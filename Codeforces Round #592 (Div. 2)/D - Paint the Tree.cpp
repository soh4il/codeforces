#include<bits/stdc++.h>
#define ll long long int
#define MAX_SIZE 100005
using namespace std;
 
 
int n,curr;
int cost[MAX_SIZE][3];
vector<vector<int>> graph;
char p[][3] = {{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
char path[7][MAX_SIZE];
 
ll dfs(int i,int parent,int node)
{
    ll res = 0;
    for(int neighbor:graph[node])
        if(neighbor != parent)
            res += dfs((i+1)%3,node,neighbor);
    path[curr][node] = p[curr][i];
    return res + cost[node][p[curr][i]];
}
 
int main()
{
    cin >> n;
    graph.assign(n+3,vector<int>());
    for(int i=0;i<n;i++)cin >> cost[i][0];
    for(int i=0;i<n;i++)cin >> cost[i][1];
    for(int i=0;i<n;i++)cin >> cost[i][2];
    
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin >> x >> y;
        graph[--x].push_back(--y);
        graph[y].push_back(x);
        if(graph[x].size() >= 3 || graph[y].size() >= 3)return 0&printf("-1\n");
    }
 
    int root = -1;
    for(int i=0;i<n;i++)if(graph[i].size() == 1)root = i;
    ll res = INT64_MAX;int resIndex;
    for(curr = 0;curr<6;curr++)
    {
        ll curr_res = dfs(0,-1,root);
        if(curr_res < res)
        {
            res = curr_res;
            resIndex = curr;
        }
    }
    cout << res << endl;
    for(int i=0;i<n;i++)
        printf("%d ",path[resIndex][i]+1);
    cout << endl;
    return 0;
}
