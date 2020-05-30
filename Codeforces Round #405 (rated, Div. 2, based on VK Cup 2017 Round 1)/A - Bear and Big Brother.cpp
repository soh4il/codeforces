#include <bits/stdc++.h>
using namespace std;
 
int a,b;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%d%d",&a,&b);
    int year = 0;
    for(;a<=b;year++,a*=3,b*=2);
    printf("%d\n",year);
    return 0;
}
