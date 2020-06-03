#include <iostream>
#define ll long long int

using namespace std;
 
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    return gcd(b,a%b);
}
 
int main(){
    ll n,m,q,g;
    cin>>n>>m>>q;
    g=gcd(n,m);
    ll s[3];
    s[1]=n/g;
    s[2]=m/g;
    while(q--){
        ll sx,sy,ex,ey;
        cin>>sx>>sy>>ex>>ey;
        if((sy-1)/s[sx] == (ey-1)/s[ex])cout<<"YES\n";
        else cout<<"NO\n";
    }
    
    return 0;
}
