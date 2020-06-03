#include <iostream>
#include <vector>
#define ll long long int
using namespace std;
 
ll n,m,r=1,ans=0;
bool flag = false;
 
int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> m;
        if(m < 0)
        {
            r *= -1;
            ans += m*-1 - 1;
        }else if (m > 0)
            ans += m - 1;
        else
        {
            ans++;
            flag = true;
        }
    }
    if(r == -1 && !flag)ans += 2;
    cout << ans << endl;
    return 0;
}
