#include <bits/stdc++.h>
#define INF 1000
using namespace std;

int n,m,dist[103][103],path[1000006];
char grid[103][103];

void floydWarshall ()  
{  
    for (int current = 1; current <= n; current++)  
    {  
        for (int source = 1; source <= n; source++)  
        {  
            for (int destination = 1; destination <= n; destination++)  
            {  
                if (dist[source][current] + dist[current][destination] < dist[source][destination])  
                    dist[source][destination] = dist[source][current] + dist[current][destination];  
            }  
        }  
    }  
} 


int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%s",grid[i]);
    scanf("%d",&m);
    for(int i=0;i<m;i++)scanf("%d",&path[i]);
    for (int i = 1; i <= n; i++)  
        for (int j = 1; j <= n; j++)  
        {
            if(i==j)dist[i][j] = 0;
            else dist[i][j] = grid[i][j-1] == '1'?1:INF;
        }
    floydWarshall();
    vector<int> ans;
    ans.push_back(path[0]);
    int last = 0;
    for(int i=1;i<m;i++)
    {
        if(dist[ans.back()][path[i]] < i-last){
            ans.push_back(path[i-1]);
            last = i-1;
        }
    }
    ans.push_back(path[m-1]);
    printf("%d\n",(int)ans.size());
    for(int node:ans)printf("%d ",node);
    printf("\n");
    return 0;
}
