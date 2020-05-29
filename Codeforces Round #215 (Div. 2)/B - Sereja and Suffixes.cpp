#include <iostream>
#include <vector>
 
using namespace std;
 
int n,m,in;
bool counted[100005] = {0};
 
int main()
{
    cin >> n >> m;
    vector<int> arr(n);
    vector<int> memo(n+3);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    memo[n+1] = 0;
    for(int i=n;i>=1;i--)
    {
        memo[i] = memo[i+1];
        if(!counted[arr[i-1]])
        {
            counted[arr[i-1]] = 1;
            memo[i]++;
        }
    }
    while(m--)
    {
        cin >> in;
        cout << memo[in] << endl;
    }
    return 0;
}
