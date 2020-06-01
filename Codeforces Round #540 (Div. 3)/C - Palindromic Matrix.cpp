#include <bits/stdc++.h>
using namespace std;
 
int tc=1,n,in,numbers[1003]={0};
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
void input()
{
    scanf("%d",&n);
    for(int i=0;i<n*n;i++)
    {
        scanf("%d",&in);
        numbers[in]++;
    }
}
 
void solve()
{
    int middle = -1;
    vector<int> corners;
    vector<int> plus;
    for(int i=1;i<=1000;i++){
        if(numbers[i]%4 == 1 || numbers[i]%4 == 3)
        {
            if(middle != -1 || n%2 == 0){
                puts("NO");
                return;
            }
            middle = i;
        }
 
        int j=0;
        for(;j<numbers[i]/4 && corners.size() < (n/2)*(n/2);j++)
            corners.push_back(i);
        for(;j<numbers[i]/4;j++)
        {
            plus.push_back(i);
            plus.push_back(i);
        }
        for(int k=0;k<numbers[i]%4 - (numbers[i]%2);k+=2)
            plus.push_back(i);
    }
    if(corners.size() != (n/2)*(n/2) || (n%2 && plus.size() != n-1) || (n%2==0 && plus.size() != 0)){
        puts("NO");
        return;
    }
    puts("YES");
    int ans[n+1][n+1] = {0};
    
    int idx = 0;
    for(int i=0;i<n/2;i++)
        for(int j=0;j<n/2;j++)
            ans[i][j] = ans[i][n-1-j] = ans[n-1-i][j] = ans[n-1-i][n-1-j] = corners[idx++];
    
    idx = 0;
    if(n%2)
    {
        for(int i=0;i<n/2;i++)
            ans[n/2][i] = ans[n/2][n-1-i] = plus[idx++];
        for(int i=0;i<n/2;i++)
            ans[i][n/2] = ans[n-1-i][n/2] = plus[idx++];
        ans[n/2][n/2] = middle; 
    }
 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",ans[i][j]);
        puts("");
    }
}
 
int main()
{
    preprocess();
    while(tc--){
        input();
        solve();
    }
    return 0;
}
