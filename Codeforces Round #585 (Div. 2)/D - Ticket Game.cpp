#include <bits/stdc++.h>
#define ld long double
using namespace std;
 
int n;
ld leftSum,rightSum;
char s[200005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%d%s",&n,s);
    leftSum = rightSum = 0;
    for(int i=0;i<n/2;i++)
    {
        if(s[i] != '?') leftSum += (ld)s[i] - '0';
        else leftSum += 4.5;
    }
 
    for(int i=n/2;i<n;i++)
    {
        if(s[i] != '?') rightSum += (ld)s[i] - '0';
        else rightSum += 4.5;
    }
    if(fabsl(leftSum - rightSum) >= 1e-9)return 0&printf("Monocarp\n");
    printf("Bicarp\n");
    return 0;
}
