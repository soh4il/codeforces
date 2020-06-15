#include <iostream>
using namespace std;
 
int n,t;
string s[2];
 
string ans()
{
    int i=0;
    for(int j=0;j<n;j++)
    {
        if(s[i][j] >= '3')
        {
            i = 1-i;
            if(s[i][j] < '3')return "NO";
        }
    }
    return i==1?"YES":"NO";
}
 
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> s[0] >> s[1];
        cout << ans() << endl;
    }
    return 0;
}
