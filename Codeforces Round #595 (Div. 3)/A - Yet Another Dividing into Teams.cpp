#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
int q,n;
int arr[105];
 
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",arr+i);
        sort(arr,arr+n);
        int flag = 0;
        for(int i=1;i<n;i++)
        {
            if(arr[i] == arr[i-1]+1)
            {
                flag = 1;
                break;
            }
        }
        printf("%d\n",flag?2:1);
    }
    return 0;
}
