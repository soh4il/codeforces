#include <iostream>
#include<vector>
#include<algorithm>
#define ll long long int
 
using namespace std;
 
int main(){
	int t;
	cin >> t;
	while(t--)
	{		
	    ll n,m;
	    cin >> n >> m;
	    vector<ll> rem;
	    for(ll i=m;i<=m*10;i+=m)
		    rem.push_back(i%10);
		ll div = n/m/10,remen = n/m%10;
	    ll sum = 0;
		for(int i=0;i<10;i++)
			sum += rem[i] * div;
		for(int i=0;i<remen;i++)
			sum += rem[i];
	    cout << sum << endl;
	}
    return 0;
}
