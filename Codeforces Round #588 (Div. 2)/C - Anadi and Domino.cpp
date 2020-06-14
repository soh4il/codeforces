#include<bits/stdc++.h>
using namespace std;
 
int n,k,x,y;
int graph[10][10] = {0};
 
int ans(int q,int p)
{
    int val[10] = {0};
    val[q] = val[p] = 1;
    for(int i=1,j=2;i<=7&&j<=6;i++)
        if(i!=q&&i!=p)val[i] = j++;
    bool dominas[10][10] = {0};
    int res = 0;
    for(int i=1;i<7;i++)
        for(int j=i+1;j<=7;j++)
        {
            if(graph[i][j]&&dominas[val[i]][val[j]] == 0&&dominas[val[j]][val[i]]  == 0)
            {
                res++;
                dominas[val[i]][val[j]] = 1;
                dominas[val[j]][val[i]] = 1;
            }    
        }
    return res;
}
 
int main()
{   
    cin >> n >> k;
    for(int i=0;i<k;i++)
    {
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    if(n <= 6)
        cout << k << endl;
    else{
        x = 0;
        for(int i=1;i<=7;i++)
            for(int j=i+1;j<=7;j++)
                x = max(x,ans(i,j));
        cout << x << endl;
    }
    return 0;
}
