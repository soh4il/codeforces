#include <bits/stdc++.h>
#define MOD 998244353
#define SIZE 100005
using namespace std;
 
int n,arr[SIZE],cnt[12] = {0};
 
int add(int a, int b);
int mul(int a, int b);
int f(int a,int l,bool is_left);
int get_len(int num);
 
void preprocess(){}
 
void input()
{
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
        cnt[get_len(arr[i])]++;
    }
}
 
void solve()
{
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=10;j++)ans = add(ans, mul(cnt[j] , f(arr[i],j,true) + f(arr[i],j,false)) );
    }
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
 
int f(int a,int l,bool is_left)
{
    int res = 0,p=1;
    for(int i=0;a&&l>0;i++,p = mul(p,10))
    {
        if(is_left){
            if(i%2){
                res = add(res , mul(a%10,p));
                a/=10;
            }else l--;
        }else{
            if(i%2 == 0){
                res = add(res , mul(a%10,p));
                a/=10;
            }else l--;
        }
    }
    for(;a;p = mul(p,10),a/=10)res = add(res , mul(a%10,p));
    return res;
}
 
 
int get_len(int num){
    int len = 0;
    for(;num;num/=10,len++);
    return len;
}
