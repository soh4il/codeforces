#include<bits/stdc++.h>
using namespace std;
 
int n,v,t,x,n1,n2;
vector<pair<int,int>> v1,v2;
vector<int> ans;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%d%d",&n,&v);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&t,&x);
        if(t == 1)v1.push_back(make_pair(x,i));
        else v2.push_back(make_pair(x,i));
    }
    sort(v1.begin(),v1.end(),greater<pair<int,int>>());
    sort(v2.begin(),v2.end(),greater<pair<int,int>>());
    n1 = (int)v1.size();
    n2 = (int)v2.size();
    for(int i=1;i<n1;i++)v1[i].first += v1[i-1].first;
    for(int i=1;i<n2;i++)v2[i].first += v2[i-1].first;
    tuple<int,int,int> ans = make_tuple(0,0,0);
    for(int i=0,j=min(n2,(v-i)/2);i<=v && i<=n1;i++,j=min(n2,(v-i)/2))
    {
        int curr = 0;
        if(i) curr = v1[i-1].first;
        if(j) curr += v2[j-1].first;
        ans = max(ans,make_tuple(curr,i,j));
    }
    cout << get<0>(ans) << endl;
    for(int i=0;i<get<1>(ans);i++)cout << v1[i].second << " ";
    for(int i=0;i<get<2>(ans);i++)cout << v2[i].second << " ";
    cout << endl;
    return 0;   
}
