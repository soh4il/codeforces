#include <bits/stdc++.h>
using namespace std;
 
int n,k,x,y;
vector<int> neighbors[100005];
bitset<100005> visited;
 
void dfs(int id)
{
    visited.set(id);
    for(int neighbor:neighbors[id])if(!visited.test(neighbor))dfs(neighbor);
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++){
        scanf("%d%d",&x,&y);
        neighbors[x].push_back(y);
        neighbors[y].push_back(x);
    }
    int c = 0;
    for(int i=1;i<=n;i++)
    {
        if(!visited.test(i))
        {
            dfs(i);
            c++;
        }
    }
    printf("%d\n",k-n+c);
    return 0;
}
