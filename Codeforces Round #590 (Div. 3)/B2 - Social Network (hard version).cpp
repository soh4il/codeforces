#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <deque>
#include <set>
#define SIZE 100005
 
using namespace std;
 
int n,m=0,k;
//vector<int> arr(SIZE);
deque<int> dq;
set<int> s;
 
int main() {
    
    cin >> n >> k >> m;
    dq.push_back(m);
    s.insert(m);
    for(int i=0;i<n;i++)
    {
        cin >> m;
        if(!s.count(m))
        {
            if(dq.size() == k)
            {
                s.erase(s.find(dq.back()));
                dq.pop_back();
            }
            dq.push_front(m);
            s.insert(m);
            
        }
    }
 
    cout << dq.size() << endl;
    for(auto it = dq.begin();it!=dq.end();it++)
        cout << *it << " ";
    cout << endl;
 
    return 0;
}
