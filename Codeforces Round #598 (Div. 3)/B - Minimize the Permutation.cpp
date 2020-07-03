#include<bits/stdc++.h>
using namespace std;
 
int q,n,m;
int arr[105];
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    cin >> q;
    while(q--)
    {
        cin >> n;
        for(int i=0;i<n;i++)
            cin >> arr[i];
        m= n-1;
        for(int x=0;x<n;)
        {
            int mn = INT32_MAX,mn_i;
            for(int i=x;i<=x+m && i<n;i++)
            {
                if(arr[i] < mn)
                {
                    mn = arr[i];
                    mn_i = i;
                }
            }
            for(int i=mn_i;i>x;i--)
            {
                swap(arr[i],arr[i-1]);
                m--;
                if(!m)goto out;
            }
            if(x == mn_i)x++;
            else x = mn_i;
        }
        out:
            for(int i=0;i<n;i++)cout << arr[i] << " ";
            cout << endl;
    }
    return 0;   
}
