#include <iostream>
 
using namespace std;
 
int n,t1,t2,ans = 1,curr = 1;
 
int main()
{
    cin >> n >> t1;
    for(int i=1;i<n;i++)
    {
        cin >> t2;
        if(t2 < t1)curr = 1;
        else curr++;
        ans = max(ans,curr);
        t1 = t2;
    }
    cout << ans << endl;
        
    return 0;
}
