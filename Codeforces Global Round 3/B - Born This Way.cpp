#include <bits/stdc++.h>
#define SIZE 200005
using namespace std;
 
int t=1,n,m,ta,tb,k;
vector<int> a,b;
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
void input()
{
    scanf("%d%d%d%d%d",&n,&m,&ta,&tb,&k);
    a.resize(n);b.resize(m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        a[i] += ta;
    }
    for(int i=0;i<m;i++)scanf("%d",&b[i]);
}
 
void solve()
{
    if(k >= n){
        printf("-1\n");
        return;
    }
    int mx = 0;
    for(int i=0;i<=k;i++)mx = max((k - i) + (int)(lower_bound(b.begin(),b.end(),a[i]) - b.begin()),mx);
    if(mx >= m)printf("-1\n");
    else printf("%d\n",b[mx] + tb);
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
