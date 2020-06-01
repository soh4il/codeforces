#include<iostream>
#include<math.h>
using namespace std;
 
int main()
{
    
    int n;
    cin >> n;
    int m = (int)ceil((n+1)/2.0);
    cout << m << endl;
    int num = 1;
    for(int i=1;i<=m;i++,num++)
        cout << 1 << " " << i << endl;
    for(int i=2;num<=n;i++,num++)
        cout << m << " " << i << endl;
    return 0;
}
