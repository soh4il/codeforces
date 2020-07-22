#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;


int solution1(vector<int> arr1,vector<int> arr2)
{
    int n = arr1.size();
    set<int> hand;
    queue<int> deck;
    for(int i=0;i<n;i++)
        hand.insert(arr1[i]);
    for(int i=0;i<n;i++)
        deck.push(arr2[i]);
    int last,count = 0;
    if(hand.count(1))
        last = 1;
    else
    {
        last = arr2[n-1] + 1;
        for(int i=n-1;i>1;i--)
        {
            if(arr2[i] == 1)break;
            if(arr2[i] != arr2[i-1]+1)
                return -1;
        }   
    }
    for(int i=last;i<=n;i++)
    {
        if(!hand.count(i))
            return -1;
        deck.push(i);
        hand.erase(i);
        hand.insert(deck.front());
        deck.pop();
        count++;
    }
    return count;

int solution2(vector<int> arr1,vector<int> arr2)
{
    int n = arr1.size();
    set<int> hand;
    queue<int> deck;
    for(int i=0;i<n;i++)
        hand.insert(arr1[i]);
    for(int i=0;i<n;i++)
        deck.push(arr2[i]);
    
    int wait = 0;
    for(int i=1;i<=n;i++)
        if(arr2[i-1])wait = max(wait,i-arr2[i-1]+1);
    
    int last=1,count = 0;
    for(int i=0;i<wait;i++)        
    {
        deck.push(0);
        hand.insert(deck.front());
        deck.pop();
        count++;
    }
    
    for(int i=last;i<=n;i++)
    {
        if(!hand.count(i))
            return -1;
        deck.push(i);
        hand.erase(i);
        hand.insert(deck.front());
        deck.pop();
        count++;
    }
    return count;
    
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr1(n);
    vector<int> arr2(n);
    int count_in_hand = 0;
    for(int i=0;i<n;i++)
    {
        cin >> arr1[i];
        if(arr1[i])
            count_in_hand++;
    }
    for(int i=0;i<n;i++)
        cin >> arr2[i];
    int ans1,ans2;
    if((ans1 = solution1(arr1,arr2)) != -1)
        cout << ans1 << endl;
    else if((ans2 = solution2(arr1,arr2)) != -1)
        cout << ans2 << endl;        
    else
        cout << 2*n << endl;
    return 0;
}
