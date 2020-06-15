#include <iostream>
#include <vector>
 
using namespace std;
 
string str;
int q,type,L,R,n;
char c;
bool isBuild = true;
 
int count[300005][27] = {0};
 
int left(int p){return p<<1;}
int right(int p){return (p<<1)+1;}
 
void update(int p,int l,int r)
{
	if(!isBuild)count[p][str[L]-'a']--;
	count[p][c-'a']++;
	if(l==L && L==r){str[L] = c;return;}
	int mid = l + (r-l)/2;
	if(mid>=L)update(left(p),l,mid);
	else update(right(p),mid+1,r);
}
 
void build()
{
	n = str.length();
	for(L=0,c=str[L];L<n;L++,c=str[L])update(1,0,n);
	isBuild = false;
}
 
void distinct(int p,int l,int r,vector<int>& arr)
{
	if(r<l)return;
	if(R < l || r < L)return;
	if(L <= l && r <= R){
		for(int i=0;i<26;i++)arr[i]+=count[p][i];
		return;
	}
	int mid = l + (r-l)/2;
	if(R <= mid)distinct(left(p),l,mid,arr);
	else if(mid < L)distinct(right(p),mid+1,r,arr);
	else 
	{
		distinct(left(p),l,mid,arr);
		distinct(right(p),mid+1,r,arr);
	} 
}
 
int main()
{
	cin >> str >> q;
	build();
	
	while(q--)
	{
		cin >> type;
		switch(type)
		{
			case 1:
				cin >> L >> c;L--;
				update(1,0,n);
				break;
			default:
				cin >> L >> R;L--;R--;
				vector<int> arr(30,0);
				distinct(1,0,n,arr);
				int sum = 0;
				for(int i=0;i<26;i++)sum += arr[i]?1:0;
				cout << sum << endl;
		}
	}
	return 0;
}
