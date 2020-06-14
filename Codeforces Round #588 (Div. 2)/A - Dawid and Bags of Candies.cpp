#include<bits/stdc++.h>
using namespace std;
 
 
int a,b,c,d;
 
string ans()
{
    if(a+b == c+d)return "YES";
    if(a+c == b+d)return "YES";
    if(a+d == b+c)return "YES";
    int sum = a+b+c+d;
    if(sum == 2*a)return "YES";
    if(sum == 2*b)return "YES";
    if(sum == 2*c)return "YES";
    if(sum == 2*d)return "YES";
    return "NO"; 
}
 
int main()
{   
    cin >> a >> b >> c >> d;
    cout << ans() << endl;
    return 0;
}
