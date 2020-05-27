#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
ll A,B,c,x,y,g;
 
void extendedEuclid(ll a,ll b){
    if(b == 0){
        x=1;y=0;g=a;return;
    }
    extendedEuclid(b,a%b);
    ll x1 = y;
    ll y1 = x - (a/b)*y;
    x = x1;
    y = y1;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    cin >> A >> B >> c;
    extendedEuclid(A,B);
    c = -c;
    if(c%g)return cout << "-1" << endl,0;
    cout << (x*(c/g)) << " " << (y*(c/g)) << endl;
    return 0;
}
