#include <iostream>
#include <algorithm>
 
#define ll long long int
 
using namespace std;
 
int n,d,j=0;
ll curr = 0,ans = 0;
pair<int,int> arr[100005];
 
int main()
{
    cin >> n >> d;
    for(int i=0;i<n;i++)
       cin >> arr[i].first >> arr[i].second;
     
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        for(;j<n;j++)
        {
            if(arr[j].first-arr[i].first < d)
                curr += (ll)arr[j].second;
            else
            {
                curr -= (ll)arr[i].second;
                break;
            }
            ans = max(curr,ans);
        }
    }
    cout << ans << endl;
    return 0;
}
