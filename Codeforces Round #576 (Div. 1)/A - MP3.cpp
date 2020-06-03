#include <bits/stdc++.h>
#define log2(n) log(n)/log(2) 
using namespace std;
 
int n,I,a;
map<int,int> cnt;
vector<int> distinct;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%d%d",&n,&I);
    I*=8;I /= n;
    if(I > log2(n))return 0&printf("0\n");
    I = 1 << I;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        if(!cnt[a])distinct.push_back(a);
        cnt[a]++;
    }
    sort(distinct.begin(),distinct.end());
    int m = distinct.size();
    vector<int> prefix(m);
 
    prefix[0] = cnt[distinct[0]];
    for(int i=1;i<m;i++)prefix[i] = prefix[i-1] + cnt[distinct[i]];
    int ans = 0;
    for(int l=0,r=l+I-1;r<m;l++,r++)
    {
        int curr = prefix[m-1] - prefix[r];
        if(l)curr += prefix[l-1];
        if(ans)ans = min(curr,ans);
        else ans = curr;
    }
    printf("%d\n",ans);
    return 0;
}
