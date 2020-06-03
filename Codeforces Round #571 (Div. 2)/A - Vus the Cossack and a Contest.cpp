#include <bits/stdc++.h>
using namespace std;
 
int n,m,k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    cin >> n >> m >> k;
    cout << (min(m,k) >= n ? "Yes":"No") << endl;
    return 0;
}
