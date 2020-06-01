#include <bits/stdc++.h>
#define SIZE 200005
#define ll long long int
using namespace std;
 
ll t=1,H,n,d[SIZE],prefix[SIZE];
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
void input()
{
    scanf("%lld%lld",&H,&n);
    for(int i=0;i<n;i++)scanf("%lld",d+i);
}
 
void solve()
{
    prefix[0] = d[0];
    for(int i=1;i<n;i++)prefix[i] = d[i] + prefix[i-1];
    ll mn = INT64_MAX,mn_i=-1;
    for(int i=0;i<n;i++)
    {
        ll num1 = prefix[i],num2 = prefix[n-1] - num1;
        ll x = num1 <= -H;
        ll temp=-1;
        if(num1 + num2)temp = ceil((double)(num2-H)/(num1+num2));
        if(temp > 0)x = temp;
        if(x > 0){
            if(x < mn){
                mn = x;
                mn_i = i+1;
            }
        }
    }
    if(mn_i == -1)printf("-1\n");
    else printf("%lld\n",n*mn-n+mn_i);
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
