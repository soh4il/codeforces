#include<bits/stdc++.h>
using namespace std;
 
int q,n,one;
long long k;
string s;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    cin >> q;
    while(q--)
    {
        cin >> n >> k;
        cin >> s;
        one = -1;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '1' && one==-1)
                one = i;
            if(s[i] == '0'){
                if(one != -1)
                {
                    long long distance = min((long long)i-one,k);
                    one = i - distance;
                    swap(s[i],s[one]);
                    one++;
                    k -= distance;
                }
            }
            if(!k)break;
        }
        cout  << s << endl;
    }
    return 0;   
}
