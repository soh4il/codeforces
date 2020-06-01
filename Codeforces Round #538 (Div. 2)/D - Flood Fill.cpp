
#include<bits/stdc++.h>
using namespace std;
 
int n,in;
vector<int> arr(1);
int memo[5003][5003];
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&in);
        if(in != arr.back())arr.push_back(in);
    }
    n = (int)arr.size();
 
    for(int i=1;i<=n;i++)
    {
        for(int j=n;j>0;j--)
        {
			if (arr[i] == arr[j]) memo[i][j] = memo[i-1][j+1] + 1;
			else memo[i][j] = max(memo[i-1][j], memo[i][j+1]);
        }
    }
 
    printf("%d\n",n-1 - (memo[n][1] + 1)/2);
    return 0;   
}
