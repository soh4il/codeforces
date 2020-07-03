#include<bits/stdc++.h>
using namespace std;
 
int t,n,k,d;
int arr[200005];
 
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&k,&d);
        for(int i=0;i<n;i++)scanf("%d",arr+i);
        int mn = INT32_MAX;
        for(int i=0;i<=n-d;i++)
        {
            int visited[k+1] = {0};
            int cnt=0;
            for(int j=i;j<i+d;j++)
            {
                if(!visited[arr[j]])
                    cnt++;
                visited[arr[j]] = 1;
            }
            mn = min(cnt,mn);
        }
        printf("%d\n",mn);
    }
    return 0;
}
