#include <bits/stdc++.h>
#define N (int) 3e5 + 5
using namespace std;
 
int n;  
int arr[N];
vector<pair<int,int>> swaps;
 
int main()
{
    //Presetup:
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //-------------------------------
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",arr+i);
    for(int i=1;i<=n;i++)
    {
        while(arr[i] != i)
        {
            if(abs(arr[i]-i) >= n/2)
            {
                int j = arr[i];
                swap(arr[i],arr[j]);
                swaps.push_back({i,j});
            }else if((arr[i] <= n/2 && i<= n/2) || (arr[i] > n/2 && i> n/2)){
                    int j = arr[i] <= n/2?n : 1;
                    int k = arr[i];
                    
                    swap(arr[i],arr[j]);
                    swap(arr[k],arr[j]);
                    swap(arr[i],arr[j]);
                        
                    swaps.push_back({i,j});
                    swaps.push_back({k,j});
                    swaps.push_back({i,j});
            }else{
                int j = arr[i];
                int k1 = i <= n/2?1:n;
                int k2 = n+1 - k1;
                
                swap(arr[k1],arr[j]);
                swap(arr[i],arr[k2]);
                swap(arr[k1],arr[k2]);
                swap(arr[k1],arr[j]);
                swap(arr[i],arr[k2]);
                
                swaps.push_back({k1,j});
                swaps.push_back({i,k2});
                swaps.push_back({k1,k2});
                swaps.push_back({k1,j});
                swaps.push_back({i,k2});
            }
        }
    }
    printf("%d\n",(int)swaps.size());
    for(pair<int,int> s:swaps)printf("%d %d\n",s.first,s.second);
    return 0;
}
