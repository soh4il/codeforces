#include <bits/stdc++.h>
using namespace std;
 
int n,cnt=0;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%d",&n);
    for(int i=1;i<n;i++)if((n - i)%i == 0)cnt++;
    printf("%d\n",cnt);
    return 0;
}
