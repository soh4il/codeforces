#include <bits/stdc++.h>
using namespace std;
 
int n;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%d",&n);
    for(int i=0;i<n;i++)printf("%s%s %s",i?" ":"",i%2?"I love":"I hate",i == n-1?"it\n":"that");
    return 0;
}
