#include<bits/stdc++.h>
#define w first
#define h second
using namespace std;
 
int n,w,h,max_len = 0,start,len;
short memo[5003];
pair<int,int> envelopes[5003];
short nxt[5003];
 
int getLength(int idx)
{
    short& res = memo[idx];
    if(res != -1)return res;
    res = 0;
    for(int j=1;j<=n;j++)
    if(envelopes[idx].w < envelopes[j].w && envelopes[idx].h < envelopes[j].h)
    {
        int curr = getLength(j);
        if(curr > res)
        {
            res = curr;
            nxt[idx] = j;
        }
    }
    return ++res;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    memset(memo,-1,sizeof(memo));
    scanf("%d%d%d",&n,&w,&h);
    for(int i=1;i<=n;i++)scanf("%d%d",&envelopes[i].w,&envelopes[i].h);
    for(int i=1;i<=n;i++)
    {
        if(w < envelopes[i].w && h < envelopes[i].h)
        {
            len = getLength(i);
            if(len > max_len)
            {
                max_len = len;
                start = i;
            }
        }
    }
    if(max_len == 0)return cout << 0 << endl,0;
    cout << max_len << endl;
    cout << start;
    for(int i=1,curr=start;i<max_len;i++)
    {
        curr = nxt[curr];
        cout << " " << curr;
    }
    cout << endl;
    return 0;   
}
