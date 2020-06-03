#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 1;
    for(int i=1,j=0;i<=n;i++,j+=4)
        ans += j;
    cout << ans << endl; 
    return 0;
}
