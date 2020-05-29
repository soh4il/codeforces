#include <iostream>
#define ll long long int
using namespace std;

ll n,m=0;
ll arr[100005] = {0};

int main()
{
    cin >> n;
    for(ll i=0,x;i<n;i++)cin >> x,arr[x]++,m=max(m,x);
    for(ll i=2;i<=m;i++)
        arr[i] = max(arr[i]*i+arr[i-2],arr[i-1]);
    cout << arr[m] << endl;
    return 0;
}
