#include <iostream>
using namespace std;

int n;
int coinValue[] = {100, 20, 10, 5,  1};

int main()
{
    
    cin >> n;
    int ans = 0;
    for(int i=0;i<5 && n;i++)
    {
        ans += n/coinValue[i];
        n %= coinValue[i];
    }
    cout << ans << endl;
    return 0;
}
