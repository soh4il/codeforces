#include <bits/stdc++.h>
using namespace std;
 
int t,m,n,id=0;
string operation;
map<int,pair<int,int>> blocks;
 
void alloc()
{
    set<pair<int,int>> blocks_starts;
    for(auto block:blocks)blocks_starts.insert({block.second.first,block.first});
    int start = 0,end;
    for(pair<int,int> block_start:blocks_starts)
    {
        int idx = block_start.second;
        end = blocks[idx].first;
        if(end - start >= n){
            blocks_starts.insert(make_pair(start,++id));
            blocks[id] = {start,start+n-1};
            cout << id << endl;return;
        }
        start = blocks[idx].second+1;
    }
    end = m;
    if(end - start >= n){
        blocks_starts.insert(make_pair(start,++id));
        blocks[id] = {start,start+n-1};
        cout << id << endl;return;
    }
    cout << "NULL\n";
}
 
void erase()
{
    if(blocks.find(n) == blocks.end())cout << "ILLEGAL_ERASE_ARGUMENT\n";
    else blocks.erase(n);
}
 
void defragment()
{
    set<pair<int,int>> blocks_starts;
    for(auto block:blocks)blocks_starts.insert({block.second.first,block.first});
    int first_empty = 0;
    for(auto block_start:blocks_starts)
    {
        int diff = block_start.first - first_empty;
        blocks[block_start.second].first = first_empty;
        blocks[block_start.second].second -= diff;
        first_empty = blocks[block_start.second].second + 1;
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    cin >> t >> m;
    while(t--)
    {
        cin >> operation;
        if(operation != "defragment")cin >> n;
        else defragment();
        if(operation == "alloc")alloc();
        else if(operation == "erase") erase();
    }
    return 0;
}
