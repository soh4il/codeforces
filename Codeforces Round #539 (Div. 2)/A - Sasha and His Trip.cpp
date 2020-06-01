#include <iostream>
 
using namespace std;
 
int main()
{
    int n,v;
    cin >> n >> v;
    int ans = min(n-1,v);
    for(int i=2;i<=n-v;i++)
        ans+=i;
    cout << ans << endl;
    return 0;
}
