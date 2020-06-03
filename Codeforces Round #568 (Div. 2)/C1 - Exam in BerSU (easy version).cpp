#include <bits/stdc++.h>
#define MOD 998244353
#define SIZE 100005
using namespace std;
 
int t=1,n,m,arr[102];
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
void input()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%d",arr+i);
}
 
void solve()
{
    int sum = 0;
    for(int i=0;i<n;i++)
    {
       sum += arr[i];
       int temp = sum,cnt = 0;
       for(int j=i;j>=0 && temp > m;j--,cnt++,temp-=arr[j]);
       printf("%d ",cnt);
       sort(arr,arr+i+1);
    }
    printf("\n");
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
