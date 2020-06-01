#include<bits/stdc++.h>
#define ll long long int
#define k second
using namespace std;
 
ll a,b,diff;
vector<ll> divisors;
inline ll lcm(ll x,ll y)
{
    return x*y / __gcd(x,y);
}
void setDivisors()
{
    for(int i=1;i*i<=diff;i++)
    {
        if(diff%i == 0)
        {
            divisors.push_back(i);
            if(i*i != diff)divisors.push_back(diff/i);
        }
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%lld%lld",&a,&b);
    if(a == b)return 0&printf("0\n");
    if(a > b)swap(a,b);
    diff = b - a;
    setDivisors();
    pair<ll,ll> mn = make_pair(INT64_MAX,INT64_MAX);
    for(ll div:divisors)
    {
            int k = (div - a % div) % div;
            pair<ll,ll> curr = make_pair(lcm(a+k,b+k),k);
            mn = min(mn,curr);
    }
    printf("%lld\n",mn.k);
    return 0;   
}
