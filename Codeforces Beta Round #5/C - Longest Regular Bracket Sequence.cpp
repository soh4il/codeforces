
#include<bits/stdc++.h>
#define SIZE 1000006
using namespace std;
 
string str;
int n,d;
stack<int> st;
int c[SIZE];
int max_len = 0,cnt = 1;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    cin >> str;
    n = str.length();
    for(int i=0;i<n;i++)
    {
        if(str[i] == '(')st.push(i);
        else{
            if(st.empty())c[i] = -1;
            else{
                d = st.top();st.pop();
                c[i] = d;
                if(d && str[d - 1] == ')' && c[d - 1] != -1)c[i] = c[d - 1];
                if(max_len == i - c[i]+1)cnt++;
                else if(max_len < i - c[i]+1)
                {
                    max_len = i - c[i]+1;
                    cnt = 1;
                }
            }
        }
    }
    cout << max_len << " " << cnt << endl;
    return 0;   
}
