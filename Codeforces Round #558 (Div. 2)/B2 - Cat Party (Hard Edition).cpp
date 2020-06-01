#include <bits/stdc++.h>
using namespace std;
 
int n,in,x;
map<int,int> cnt;
map<int,int> cntCnt;
 
bool isValid()
{
    if(x == 1)return true;
    if(cntCnt.size() == 1 && cntCnt.find(1) != cntCnt.end())return true;
    if(cntCnt.size() == 1 && cntCnt.begin()->second == 1)return true;
    if(cntCnt.size() != 2)return false;
    if(cntCnt.find(1) != cntCnt.end())return cntCnt[1] == 1 || (cntCnt.find(2) != cntCnt.end() &&  cntCnt[2] == 1);
    if(cntCnt.begin()->first != cntCnt.rbegin()->first - 1)return false;
    if(cntCnt.rbegin()->second != 1)return false;
    return true;
    
}
 
int main(){
    scanf("%d",&n);
    int ans = 0;
    for(x=1;x<=n;x++)
    {
        scanf("%d",&in);
        if(cnt.find(in) != cnt.end())
        {
            cntCnt[cnt[in]]--;
            if(cntCnt[cnt[in]] == 0)cntCnt.erase(cnt[in]);
        }
        cnt[in]++;
        cntCnt[cnt[in]]++;
        if(isValid())ans = x;
    }
    printf("%d\n",ans);
    return 0;
}
