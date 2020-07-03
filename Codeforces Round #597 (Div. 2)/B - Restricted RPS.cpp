#include<bits/stdc++.h>
using namespace std;
 
int t,n,a,b,c,R,P,S;
string s;
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    cin >> t;
    while(t--)
    {
        cin >> n >> a >> b >> c >> s;
        R = P = S = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == 'R')R++;
            else if(s[i] == 'P')P++;
            else S++;
        }
        int remR = max(0,a-S);
        int remP = max(0,b-R);
        int remS = max(0,c-P);
        int rem = remR + remP + remS; 
        if(rem > n/2 ){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        string ans = "";
        for(int i=0;i<n;i++)
            ans+="0";
        a -= remR;
        b -= remP;
        c -= remS;
        for(int i=0;i<n;i++)
        {
            if(s[i] == 'S' && a)
            {
                ans[i] = 'R';
                a--;
            }
            if(s[i] == 'R' && b)
            {
                ans[i] = 'P';
                b--;
            }
            if(s[i] == 'P' && c)
            {
                ans[i] = 'S';
                c--;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(ans[i] == '0')
            {
                if(remR){
                    ans[i] = 'R';
                    remR--;
                }else if(remP){
                    ans[i] = 'P';
                    remP--;
                }else if(remS){
                    ans[i] = 'S';
                    remS--;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;   
}
