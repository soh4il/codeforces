#include <bits/stdc++.h>
using namespace std;

int q;
string s,t;

string sameChar()
{
	int count1[30] = {0},count2[30] = {0};
	for(int i=0;i<s.length();i++)
	{
		int c1 = s[i] - 'a',c2 = t[i] - 'a';
		count1[c1]++;count2[c2]++;
		if(count1[c1] && count2[c1])return "YES";
		if(count1[c2] && count2[c2])return "YES";
	}
	return "NO";	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//---------------------------
	cin >> q;
	while(q--)
	{
		cin >> s >> t;
		cout << sameChar() << endl;
	}
	
	return 0;
}
