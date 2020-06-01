#include<iostream>
 
using namespace std;
 
int main()
{
    
    int x,y,z;
    cin >> x >> y >> z;
    if((x+z > y && y+z > x) || (x!=y && ((x+z == y || y+z == x))))
        cout << "?\n";
    else if(x > y)
        cout << "+\n";
    else if(x < y)
        cout << "-\n";
    else
        cout << "0\n";
 
    return 0;
}
