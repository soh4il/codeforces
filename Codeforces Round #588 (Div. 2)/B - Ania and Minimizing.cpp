#include<bits/stdc++.h>
using namespace std;
 
int n,k;
string num;
 
int main()
{   
    cin >> n >> k >> num;
    if(n == 1 && k == 1)cout <<  0 << endl;
    else{
        if(k)
        {
            if(num[0] != '1')k--;
            num[0] = '1';
        }
        for(int i=1;k && i<n;i++)
        {
            if(num[i]!='0')k--;
            num[i] = '0';
        }
        cout << num << endl;
    }
    return 0;
}
