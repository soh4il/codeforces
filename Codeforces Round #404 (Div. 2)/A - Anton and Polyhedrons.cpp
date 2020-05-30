#include <iostream>
#include <map>
 
using namespace std;
 
map<string,int> mp;
int n;
string in;
 
int main()
{
    mp["Icosahedron"] = 20;
    mp["Cube"] = 6;
    mp["Tetrahedron"] = 4;
    mp["Dodecahedron"] = 12;
    mp["Octahedron"] = 8;
    cin >> n;
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        cin >> in;
        sum += mp[in];
    }
    cout << sum << endl;
    return 0;
}
