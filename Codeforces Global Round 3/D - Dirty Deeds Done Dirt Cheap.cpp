#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
 
int n; 
pair<int,int> in;
vector<pair<int,int>> small,big; 
int main()
{
    //Presetup:
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //-------------------------------
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&in.f,&in.s);
        if(in.f < in.s)
            small.push_back({in.s,i});
        else
            big.push_back({in.s,i});
        
    }
    if(small.size() > big.size())
    {
        sort(small.begin(),small.end(),greater<pair<int,int>>());
        printf("%d\n",(int)small.size());
        for(pair<int,int> p:small)printf("%d ",p.s);
    }else{
        sort(big.begin(),big.end());
        printf("%d\n",(int)big.size());
        for(pair<int,int> p:big)printf("%d ",p.s);   
    }
    printf("\n");
    return 0;
}
