#include <iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
 
int main(){
	int t;
	cin >> t;
	while(t--)
	{		
	    int n;
	    cin >> n;
	    vector<pair<int,int>> arr(n);
	    for(int i=0;i<n;i++)
	    {
	    	cin >> arr[i].first;
	    	arr[i].second = i;
	    }
	    sort(arr.begin(),arr.end());
	    int count = 0,mx = arr[0].second;
	    for(int i=1;i<n;i++)
	    {
	    	if(arr[i].second < mx)
	    		count++;
	    	else
	    		mx = arr[i].second;
	    }
	    cout << count << endl;	
	}
    return 0;
}
