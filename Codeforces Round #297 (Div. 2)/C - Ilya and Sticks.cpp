#include <bits/stdc++.h>
#define SIZE 100005
#define ll long long int
using namespace std;
 
int tc=1,n;
vector<int> len;
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
void input()
{
    scanf("%d\n",&n);
    len.resize(n);
    for(int i=0;i<n;i++)
        scanf("%d",&len[i]);
}
 
void solve()
{   
    sort(len.begin(),len.end());
    ll dim[n] = {0},id=0;
    for(int i=n-1;i>0;i--)
    {
        if(abs(len[i]-len[i-1]) <= 1)
        {
            dim[id++] = (ll)len[i-1];
            i--;
        }
    }
    ll ans = 0;
    for(int i=0;i<id;i+=2)
        ans += dim[i]*dim[i+1];
 
    printf("%lld\n",ans);
}
 
int main()
{
    preprocess();
    while(tc--){
        input();
        solve();
    }
    return 0;
}
