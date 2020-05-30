#include<iostream>
 
using namespace std;
 
int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int count = 0;
	for(int i=1;i<n;i++)
	{
		if(s[i]==s[i-1])
		{
			if(s[i]!='R' && (i+1==n || s[i+1]!='R'))
				s[i] = 'R';
			else if(s[i]!='G' && (i+1==n || s[i+1]!='G'))
				s[i] = 'G';
			else
				s[i] = 'B';
			count++;
		}
	}
	cout << count << endl << s << endl;
	return 0;
}
