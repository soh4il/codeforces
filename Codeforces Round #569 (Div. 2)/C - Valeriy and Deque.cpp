#include <iostream>
#include <deque>
#include <vector>

typedef long long int ll;
using namespace std;

int main()
{
    ll n,q;
    cin >> n >> q;
    vector<pair<int,int>> dp;
    deque <int> arr;
    for(ll i=0;i<n;i++)
    {
        int in;
        cin >> in;
        arr.push_back(in);
    }

    for(ll i=0;i<n-1;i++)
    {
        int A,B;
        A = arr.front();arr.pop_front();
        B = arr.front();arr.pop_front();
        dp.push_back(make_pair(A,B));
        if(A>B)
        {
            arr.push_front(A);
            arr.push_back(B);
        }else
        {
            arr.push_front(B);
            arr.push_back(A);
        }
    }

    int mx = arr.front();arr.pop_front();
    n--; 
    for(ll i=0;i<q;i++)
    {
        ll in;
        cin >> in;
        in--;
        if(in<n)
            cout << dp[in].first << " " <<  dp[in].second << endl;
        else
            cout << mx << " " <<  arr[in%n] << endl;

    }

    return 0;
}
