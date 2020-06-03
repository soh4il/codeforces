#include <bits/stdc++.h>
#define MOD 998244353
#define SIZE 100005
using namespace std;
 
int t=1,n,m,arr[200005];
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
    map<int,int> cnt;
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
        int deleted = 0,needed = sum - m;
 
        map<int, int>::reverse_iterator it;
        for (it = cnt.rbegin(); it != cnt.rend() && needed>0; it++)
        {
            int temp = min((int)ceil((float)needed/(it->first)),it->second);
            deleted += temp;
            needed -= temp * it->first;
        }
 
        printf("%d ",deleted);
        cnt[arr[i]]++;
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
