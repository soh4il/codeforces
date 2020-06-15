#include <iostream>
#include <math.h>
using namespace std;
 
int t;
double n,m;
 
int main() {
    cin >> t;
    while(t--)
    {
        cin >> n;
        double avg = 0;
        for(int i=0;i<n;i++)
        {
            cin >> m;
            avg += m;
        }
        cout << (int)ceil(avg/n) << endl;
    }
    return 0;
}
