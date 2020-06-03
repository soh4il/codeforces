#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n%2)cout << "0\n";
    else
        cout << (1<<(n>>1)) << endl;
    return 0;
}
