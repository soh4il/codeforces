#include <bits/stdc++.h>
#define SIZE 200005
using namespace std;
 
int t=1,n,arr[SIZE];
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
void input()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",arr+i);
}
 
void solve()
{
    string ans = "";
    int last = -1;
    for(int l = 0,r=n-1;l<=r;){
        if(arr[l] > last && arr[r] > last){
            if(arr[l] <= arr[r]){
                ans+='L';
                last = arr[l++];
            }
            else {
                ans+='R';
                last = arr[r--];
            }
        }else if(arr[l] > last){
            ans += 'L';
            last = arr[l++];
        }else if(arr[r] > last){
            ans += 'R';
            last = arr[r--];
        }else break;
    }
    cout << ans.length() << endl << ans << endl;
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
