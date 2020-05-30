#include <bits/stdc++.h>
using namespace std;
 
vector<int> prefects;
int n,sum;
 
int main()
{
    for(int i=1;prefects.size()<=10000;i++)
    {
        n = i;sum = 0;
        while(n)
        {
            sum += n%10;
            n/=10;
        }
        if(sum == 10)prefects.push_back(i);
    }
    cin >> n;
    cout << prefects[n-1] << endl;
    return 0;
}
