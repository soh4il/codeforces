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
            if(arr[l] < arr[r]){
                ans+='L';
                last = arr[l++];
            }
            else if(arr[l] > arr[r]) {
                ans+='R';
                last = arr[r--];
            }else{
                string ansRight = "R";
                while(arr[r] < arr[r-1]){
                    ansRight += 'R';
                    r--;
                }
                string ansLeft = "L";
                while(arr[l] < arr[l+1]){
                    ansLeft += 'L';
                    l++;
                }
                if(ansLeft.length() > ansRight.length())ans+=ansLeft;
                else ans += ansRight;
                break;
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
