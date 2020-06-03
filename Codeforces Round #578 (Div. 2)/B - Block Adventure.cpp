#include<iostream>
 
using namespace std;
 
int n,bag,k;
int h[105];
 
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&bag,&k);
		for(int i=0;i<n;i++)scanf("%d",&h[i]);
		bool cant = false;
		for(int i=0;i<n-1;i++)
		{
			if(k>h[i] && k>h[i+1])
				bag += h[i];
			else if(h[i]>=h[i+1])
				bag += h[i] - max(h[i+1] - k,0);
			else if(h[i+1]-h[i] > k)
			{
				if(h[i+1]-h[i]-bag > k){
					cant = true;
					break;
				}
				bag -= h[i+1]-h[i]-k;
			}else
				bag += k - (h[i+1]-h[i]);
				
		}
		printf("%s\n", cant?"NO":"YES");
	}
	return 0;
}
