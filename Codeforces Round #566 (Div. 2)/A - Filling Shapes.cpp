#include<iostream>

using namespace std;

int main()
{
    int i;
    cin >> i;
    if(i%2)cout << "0\n";
    else
        cout << (1<<(i>>1)) << endl;
    return 0;
}
