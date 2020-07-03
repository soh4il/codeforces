#include<bits/stdc++.h>
#define ll  long long int
#define vi vector<int>
using namespace std;


ll _sieve_size;
bitset<100005> bs;
vi primes;
void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++) 
        if (bs[i]) {
            for (ll j = i * i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back((int)i);
        } 
}

int n,k,m;
map<vector<pair<int,int>>,int> mp;

int ans()
{
    vector<pair<int,int>> list1,list2;
    for(int i=0;primes[i]*primes[i] <= m;i++)
    {
        if(m%primes[i] == 0)
        {
            int cnt = 0;
            for(;m%primes[i] == 0;cnt++,m/=primes[i]);
            if(cnt%k)
            {
                list1.push_back({primes[i],cnt%k});
                list2.push_back({primes[i],k-cnt%k});
            }
        }
    }
    if(m!=1)
    {
        list1.push_back({m,1});
        list2.push_back({m,k-1});
    }
    int res = mp[list2];
    mp[list1]++;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    sieve(100000);
    scanf("%d%d",&n,&k);
    ll res = 0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&m);
        res += ans();
    }
    printf("%lld\n",res);
    return 0;   
}
