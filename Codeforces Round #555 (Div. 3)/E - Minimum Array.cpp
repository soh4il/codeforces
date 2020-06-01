
#include <bits/stdc++.h>
#define SIZE 200005
using namespace std;
 
int t=1,n,a[SIZE];
multiset<int> b;
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //scanf("%d",&t);
}
 
void input()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        b.insert(x);
    }
}
 
void solve()
{
    for(int i=0;i<n;i++)
    {
        multiset<int>::iterator it = b.lower_bound((n-a[i])%n);
        if(it == b.end())it = b.begin();
        printf("%d ",(*it + a[i])%n);
        b.erase(it);
    }
    printf("\n");
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
