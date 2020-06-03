#include<iostream>
 
using namespace std;
 
int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int rooms[15] = {0};
	for(int i=0;i<s.length();i++)
	{
		if(s[i] == 'L')
		{
			for(int j=0;j<10;j++)
			{
				if(!rooms[j]){
					rooms[j] = 1;
					break;
				}
			}
		}else if(s[i] == 'R')
		{
			for(int j=9;j>=0;j--)
			{
				if(!rooms[j]){
					rooms[j] = 1;
					break;
				}
			}
		}else
		{
			int index = s[i]-'0';
			rooms[index] = 0;
		}
	}
	for(int i=0;i<10;i++)
		cout << rooms[i];
	cout << endl;
	return 0;
}
