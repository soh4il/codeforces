#include <iostream>
 
using namespace std;
 
int n,m,in;
int maxa = 0,maxb = 0,mina = INT32_MAX,minb = INT32_MAX;
 
int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> in;
        maxa = max(maxa,in);
        cin >> in;
        mina = min(mina,in);
    }
    cin >> m;
    for(int i=0;i<m;i++)
    {
        cin >> in;
        maxb = max(maxb,in);
        cin >> in;
        minb = min(minb,in);
    }
    cout << max(max(maxb - mina,maxa - minb),0) << endl;
 
    return 0;
}
