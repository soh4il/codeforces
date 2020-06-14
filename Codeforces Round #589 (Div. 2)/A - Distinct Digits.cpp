#include<bits/stdc++.h> 
using namespace std;
 
int l,r; 
 
bool check(int i)
{
    bool found[10] = {0};
    while(i)
    {
        int r = i%10;
        if(found[r])return 0;
        found[r] = 1;
        i/=10;
    }
    return 1;
}
 
int main()
{
    cin>> l >> r;
    for(int i=l;i<=r;i++)
        if(check(i))
        {
            cout << i << endl;
            return 0;
        }
    cout << -1 << endl;
    return 0;
}
