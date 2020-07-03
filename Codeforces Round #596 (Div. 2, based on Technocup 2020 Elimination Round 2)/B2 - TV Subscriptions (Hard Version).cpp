#include<bits/stdc++.h>
using namespace std;
 
int t,n,k,d;
int arr[200005];
int counter[1000006];
 
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&k,&d);
        for(int i=0;i<n;i++)scanf("%d",arr+i);
        int cnt = 0;
        memset(counter,0,(k+2)*sizeof(int));
        for(int i=0;i<d;i++)
        {
            if(!counter[arr[i]])
                cnt++;
            counter[arr[i]]++;
        }
        int mn = cnt;
        for(int i=d;i<n;i++)
        {
             counter[arr[i-d]]--;
             if(!counter[arr[i-d]])cnt--;
             if(!counter[arr[i]])
                cnt++;
            counter[arr[i]]++;
            mn = min(mn,cnt);
        }
        
        printf("%d\n",mn);
    }
    return 0;
}
