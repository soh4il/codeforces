#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
int q,n;
string s;
 
int main()
{
    cin >> q;
    while(q--)
    {
        cin >> n >> s;
        int mn =-1,mx=-1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '1')
            {
                if(mn == -1)mn = i;
                mx = i+1;
            }
        }
        if(mx == -1)cout << n << endl;
        else{
            int res = max(n,2*mx);
            res = max(2*(n-mn),res);
            cout << res << endl;
        }
    }
    return 0;
}
