#include <bits/stdc++.h>
using namespace std;
 
int n,ones=0,zeros=0;
string s;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    cin >> n >> s;
    for(char c:s)
    {
        if(c == 'z')zeros++;
        if(c == 'n')ones++;
    }
    for(int i=0;i<ones;i++)cout << 1 << " ";
    for(int i=0;i<zeros;i++)cout << 0 << " ";
    cout << endl;
    return 0;
}
