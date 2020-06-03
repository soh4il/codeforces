#include <bits/stdc++.h>
#define MOD 998244353
#define SIZE 100005
using namespace std;
 
int t=1,n;
vector<pair<int,int>> arr;
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
void input()
{
    scanf("%d",&n);
    arr.resize(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i].first);
        arr[i].second = i+1; 
    }
}
 
int solve()
{
    if(n == 2)return printf("%d\n",arr[0].second);
    sort(arr.begin(),arr.end());
    int d = arr[1].first - arr[0].first;
    int c = arr[2].first - arr[1].first;
    bool first_case = true;
    for(int i=3;i<n&&first_case;i++)if(arr[i].first - arr[i-1].first != c)first_case = false;
    if(first_case)return printf("%d\n",arr[0].second);
    c = arr[2].first - arr[0].first;
    bool second_case = true;
    for(int i=3;i<n&&second_case;i++)if(arr[i].first - arr[i-1].first != c)second_case = false;
    if(second_case)return printf("%d\n",arr[1].second);
    bool cannot = false;
    int idx;
    for(int i=2;i<n;i++)
    {
        int diff = arr[i].first - arr[i-1].first;
        if(diff != d){
            if(cannot)return printf("-1\n"); 
            cannot = true;
            arr[i].first = arr[i-1].first;
            idx = arr[i].second;
        }
    }
    return printf("%d\n",idx);
}
 
int main()
{
    preprocess();
    while(t--)
    {
        input();
        solve();
    }
    return 0;
}
