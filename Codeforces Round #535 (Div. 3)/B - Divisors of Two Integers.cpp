#include <iostream>
#include <algorithm>
 
using namespace std;
 
int n;
int arr[100005];
 
int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
       cin >> arr[i];
     
    sort(arr,arr+n,greater<int>());
    cout << arr[0] << " ";
    for(int i=1;i<n;i++)
        if(arr[0]%arr[i] || arr[i] == arr[i-1])
        {
            cout << arr[i] << endl;
            break;
        }
    return 0;
}
