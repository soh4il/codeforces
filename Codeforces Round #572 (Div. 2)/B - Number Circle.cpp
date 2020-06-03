#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    sort(arr.begin(),arr.end());
 
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i] >= arr[(i+n-1)%n]+arr[(i+1)%n])
        {
            swap(arr[i],arr[(i+n-1)%n]);
            if(arr[(i+n-1)%n] >= arr[(i+n-2)%n]+arr[i])
            {
                cout << "NO\n";
                return 0;
            }
        }
    }
    
    vector<int>::iterator it = arr.begin();
    cout << "YES\n";
    for(;it!=arr.end();it++)
        cout << *it << " ";
    cout << endl;
    
    return 0;
}
