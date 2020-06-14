#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
ll n,in;
ll a[7005];
map<ll,bool> visited;
map<ll,pair<ll,ll>> cnt;
 
map<ll,vector<ll>> neighbors;
 
int main()
{   
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        cnt[a[i]].first++;
    }
    for(int i=0;i<n;i++)
    {
        cin >> in;
        cnt[a[i]].second += in;
    }
    for(auto i1 = cnt.begin();i1!=cnt.end();i1++)
        for(auto i2 = cnt.begin();i2!=cnt.end();i2++)
            if(i1 != i2 && (i2->second.first > 1))
                if(!(i1->first & ~ i2->first))
                    neighbors[i2->first].push_back(i1->first);
    ll ans = 0;
    for(auto i = cnt.begin();i!=cnt.end();i++)
        if(i->second.first > 1 && !visited[i->first])
        {
            visited[i->first] = 1;
            ans += i->second.second;
            for(auto j = neighbors[i->first].begin();j!=neighbors[i->first].end();j++)
                if(!visited[*j])
                {
                    ans += cnt[*j].second;
                    visited[*j] = 1;
                }
        }
    cout << ans << endl;
    return 0;
}
