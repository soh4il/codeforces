#include<bits/stdc++.h>
using namespace std;
 
int n,c;
int a[200005]={0};
int b[200005]={0};
int dpS[200005] = {0};
int dpE[200005] = {0};
 
int main()
{
    scanf("%d%d",&n,&c);
    for(int i=1;i<n;i++)scanf("%d",a+i);
    for(int i=1;i<n;i++)scanf("%d",b+i);
    dpE[0] = c;
    for(int i=1;i<n;i++)
    {
        printf("%d ",min(dpS[i-1],dpE[i-1]));
        dpS[i] = min(dpS[i-1]+a[i],dpE[i-1]+a[i]);
        dpE[i] = min(dpS[i-1]+c+b[i],dpE[i-1]+b[i]);
    }
    printf("%d \n",min(dpS[n-1],dpE[n-1]));
    return 0;
}
