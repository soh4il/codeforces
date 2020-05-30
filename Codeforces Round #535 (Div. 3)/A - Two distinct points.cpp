#include <iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while(t--)
    {
        int l1,l2,r1,r2;
        cin >> l1 >> r1 >> l2 >> r2;
        pair<int,int> left,right;
        pair<int,int> range1=make_pair(l1,r1),range2=make_pair(l2,r2);
        
        left = min(range1,range2);
        right = max(range1,range2);
        if(range1 == left)
            cout << left.first << " " << right.second << endl;
        else
            cout << right.second << " " << left.first << endl;
    }
    return 0;
}
