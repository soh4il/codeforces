#include <bits/stdc++.h>
using namespace std;
 
int a1,a2,k1,k2,n;
 
int main()
{
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    if(k1>k2)
    {
        swap(k1,k2);
        swap(a1,a2);
    }
    
     int mn = max(0,n - (a1*(k1-1) + a2*(k2-1)));
    
    int mnC = min(n,a1*k1);
    int mx = mnC/k1;
    n -= mnC;
    int mxC = min(n,a2*k2);
    mx += mxC /k2;
    cout << mn << " " << mx << endl;
    return 0;
}
