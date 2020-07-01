#include<bits/stdc++.h>
using namespace std;
 
bitset<200005> visited;
int q,n;
int arr[200005];
int ans[200005];
 
int dfs(int node,int depth)
{
    if(visited.test(node))return ans[node] = depth-1;
    visited.set(node);
    return ans[node] = dfs(arr[node],depth+1);
}
 
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        visited.reset();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",arr+i);
        for(int i=1;i<=n;i++)
            if(!visited.test(i))
                ans[i] = dfs(i,1);
        for(int i=1;i<=n;i++)
            printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}
