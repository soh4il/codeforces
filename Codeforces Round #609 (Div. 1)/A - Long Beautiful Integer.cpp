#include <bits/stdc++.h>
using namespace std;

int n,k;
char x[200005];
bool larger = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%d%d%s",&n,&k,x);
    for(int j=n - 1 - k;j>=0 && !larger;j--)if(x[j] < x[j+k])larger = 1;
    if(larger)for(int i=k;i--;)if(x[i]!='9'){x[i]++;break;}else x[i] = 0; 
    for(int i=k;i<n;i++)x[i] = x[i-k];
    printf("%d\n%s\n",n,x);
    return 0;
}
