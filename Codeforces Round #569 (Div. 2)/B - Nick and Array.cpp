#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[100005];
    int mn=1000009,mx=-1000009;
    int mn_i,mx_i,negative = 0;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
        if(abs(arr[i]) < abs(-1*arr[i]-1))
            arr[i] = -1*arr[i]-1;
        
        if(arr[i]<0)negative++;
        if(arr[i] < mn)
        {
            mn = arr[i];
            mn_i = i;
        }
        if(arr[i] > mx)
        {
            mx = arr[i];
            mx_i = i;
        }
    }

    if(negative%2)
    {
        if(abs(-1*mn-1) > abs(-1*mx-1))
            arr[mn_i] = -1*mn-1;
        else
            arr[mx_i] = -1*mx-1;
    }
    
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
