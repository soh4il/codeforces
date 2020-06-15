#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
int q,n,m,c1,c2,k;
 
int main()
{
    cin >> q;
    while(q--)
    {
        cin >> n >> m >> c1 >> c2 >> k;
        int res1 = n/c1 + (n%c1?1:0);
        int res2 = m/c2 + (m%c2?1:0);
        if(res1+res2>k)cout << -1 << endl;
        else cout << res1 << " " << res2 << endl;
    }
    return 0;
}
