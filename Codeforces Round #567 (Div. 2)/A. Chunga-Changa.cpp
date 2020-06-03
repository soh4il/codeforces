#include <iostream>
#define ll long long int
using namespace std;

int main()
{
    ll x,y,z;
    cin >> x >> y >> z;
    cout << ((x+y)/z) << " ";
    ll xNeed = z - (x%z);
    ll yNeed = z - (y%z);
    if(xNeed <= yNeed && y%z >= xNeed)cout << xNeed << endl;
    else if(x%z >= yNeed)cout << yNeed << endl;
    else cout << 0 <<"\n";
	return 0;
}
