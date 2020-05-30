#include <iostream>
using namespace std;
 
int n,m,res=0;
 
int main()
{
    cin >> n >> m;
    while(n>0 && m>0 && !(n<2 && m < 2))
    {
        if(n > m)
            n -= 3;
        else
            m -= 3;
        n++;
        m++;
        res++;
    }
    cout << res << endl;
    return 0;
}
