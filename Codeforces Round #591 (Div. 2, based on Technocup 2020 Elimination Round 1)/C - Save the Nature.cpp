#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll k;
int q,n,x,y,a,b;

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
		vector<int> arr(n);
		for(int i=0;i<n;i++)
		{
			cin >> arr[i];
			arr[i]/=100;
		}
		sort(arr.begin(),arr.end(),greater<int>());
		cin >> x >> a >> y >> b >> k;
		if(x<y){swap(x,y);swap(a,b);}
		x-=y;
		int i=1,i1,i2,i3;
		i1=i2=i3=0;ll j =0;
		for(;j<k&&i<=n;i++)
		{
			if(i%a == 0 || i%b == 0)
				j += arr[i1++] * y;
			if(i%a == 0)
				j += arr[i2++] * x;
			if(i%a == 0 && i%b == 0)
				j += arr[i3++] * y;
		}
		cout << (j>=k?i-1:-1) << endl;
	}
	
	return 0;
}
