#include <iostream>
 
using namespace std;
 
int n,k,ans=0,add;
int arr[505];
 
int main()
{
    cin >> n >> k;
    for(int i=0;i<n;i++)
       cin >> arr[i];
     
    for(int i=1;i<n;i++)
    {
        add = max(0,k - arr[i-1]-arr[i]);
        arr[i] += add;
        ans += add;
    }
    cout << ans << endl;
    for(int i=0;i<n;i++)
       cout << arr[i] << " ";
    cout << endl;
    return 0;
}
