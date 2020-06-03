#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,k,m,ans = INT_MAX;
int steps[200005] = {0},freq[200005] = {0};

void cal(int x,int step)
{
    freq[x]++;
    if(freq[x] == k)ans = min(ans,steps[x]);
    if(x == 0)return;
    step++;
    steps[x/2] += step;
    cal(x/2,step);
}

int main()
{
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
        cal(arr[i],0);
    
    cout << ans << endl;
    return 0;
}
