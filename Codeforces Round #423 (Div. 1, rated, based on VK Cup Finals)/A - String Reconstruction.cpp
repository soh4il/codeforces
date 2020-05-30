#include <bits/stdc++.h>
#define SIZE 2000006
using namespace std;
 
int tc=1,n,k,len=-1;
string str,ans(SIZE,'a');
vector<int> nxt(SIZE,-1);
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
void input()
{
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> str >> k;
        int l = str.length();
        for(int j=0;j<k;j++){
            int index;
            cin >> index;
            index--;
            for(int j=index;j<index+l;)
            {
                ans[j] = str[j-index];
                if(nxt[j]!=-1)
                {
                    int temp = nxt[j];
                    nxt[j] = max(index+l,nxt[j]);
                    j = temp;
                }
                else
                    nxt[j++] = index+l;
            }
            len = max(len,l+index);
        }
    }
}
 
void solve()
{   
    for(int i=0;i<len;i++)cout << ans[i];
    cout << endl;
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
