#include<bits/stdc++.h>
using namespace std;
 
int t,n;
string s;
 
string sys1To2(string x)
{
    int num = 0,pw=1;
    for(int i=x.length()-1;i>=0;i--)
    {
        num += ((int)x[i]-'A' + 1) * pw;
        pw *= 26;
    }
    return to_string(num);
}
 
string sys2To1(string ss)
{
    stringstream geek(ss); 
    int x; 
    geek >> x;
    string rev = "";
    while(x)
    {
        char add = (char) (x%26 + '@');
        rev += add=='@'?'Z':add;
        x--;
        x/=26;
    }
    reverse(rev.begin(),rev.end());
    return rev;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    cin >> t;
    while(t--)
    {
        cin >> s;
        n = s.length();
        vector<string> num;
        string temp = "";
        for(int i=0;i<n;i++)
        {
            if(!i || !(isdigit(s[i]) || isdigit(s[i-1])))
                temp += s[i];
            else if(isdigit(s[i]) && isdigit(s[i-1]))
                temp += s[i];
            else
            {
                num.push_back(temp);
                temp = s[i];
            }
        }
        num.push_back(temp);
        assert(num.size() == 2 || num.size() == 4);
        if(num.size() == 2)
            cout << "R" << num[1] << 'C' << sys1To2(num[0]) << endl;
        else
            cout << sys2To1(num[3]) << num[1] << endl;
    }
    return 0;   
}
