#include <bits/stdc++.h>
#define SIZE 300005
using namespace std;

int q,n,in,ans,mx,cnt,lastIndex,l[SIZE],r[SIZE];
bool f[SIZE];

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
		for(int i=1;i<=n;i++)f[i]=0;
		ans = 0;
		for(int i=1;i<=n;i++)
		{
			cin >> in;
			if(!f[in]){l[in]=i;r[in]=i;f[in] = 1;ans++;}
			else r[in] = i;
		}
		mx = 0;cnt=0;lastIndex = -1;
		for(int i=1;i<=n;i++)
		{
			if(f[i])
			{
				if(l[i]<lastIndex)
					cnt = 1;
				else
					cnt++;
				lastIndex = r[i];
				mx = max(cnt,mx);
			}
		}
		cout << (ans - mx) << endl;
	}
	
	return 0;
}
