#include <bits/stdc++.h>
using namespace std;

int q,n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//---------------------------
	cin >> q;
	while(q--)
	{
		cin >> n;
		if(n == 2)cout << 2 << endl;
		else
			cout << n%2 << endl;
	}
	
	return 0;
}
