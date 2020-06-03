#include <bits/stdc++.h>
#define MOD 998244353
#define SIZE 100005
using namespace std;
 
int n,arr[SIZE];
 
int add(int a, int b);
int mul(int a, int b);
int f(int a,int b);
 
void preprocess(){}
 
void input()
{
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",arr+i);
}
 
void solve()
{
    int ans = 0;
    for(int i=0;i<n;i++)ans = add(ans, mul(n , f(arr[i],arr[i])) );
    printf("%d\n",ans);
}
 
int main()
{
    preprocess();
    input();
    solve();
    return 0;
}
 
 
int add(int a, int b) {
    a += b;
	if (a >= MOD) {
		a -= MOD;
	}
    return a;
}
 
int mul(int a, int b) {
	return a * 1ll * b % MOD;
}
 
int f(int a,int b)
{
    int res = 0,p=1;
    for(int i=0;a&&b;i++,p = mul(p,10))
    {
        if(i%2){
            res = add(res , mul(a%10,p));
            a/=10;
        }else{
            res = add(res , mul(b%10,p));
            b/=10;
        } 
    }
    for(;a;p = mul(p,10),a/=10)res = add(res , mul(a%10,p));
    for(;b;p = mul(p,10),b/=10)res = add(res , mul(b%10,p));
    return res;
}
