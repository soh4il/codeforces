#include<bits/stdc++.h>
using namespace std;
 
int q,a,b,n,s;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    cin >> q;
    while(q--)
    {
        cin >> a >> b >> n >> s;
        s -= min(s/n,a)*n;
        if(b>=s)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;   
}
