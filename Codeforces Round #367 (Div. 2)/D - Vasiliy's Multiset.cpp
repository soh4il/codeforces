#include<bits/stdc++.h>
#define SIZE 200005
using namespace std;
 
int tc=1,x;
string chr;
 
struct Vertex {
    int next[2];
    int cnt[2];
 
    Vertex() {
        fill(begin(next), end(next), -1);
        fill(begin(cnt), end(cnt), 0);
    }
};
 
 
vector<Vertex> trie(1);
 
void add(int x) {
    int v = 0;
    for (int i=30;i>=0;i--) {
        int c = (x >> i) & 1;
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        trie[v].cnt[c]++;
        v = trie[v].next[c];
    }
}
 
void sub(int x) {
    int v = 0;
    for (int i=30;i>=0;i--) {
        int c = (x >> i) & 1;
        trie[v].cnt[c]--;
        v = trie[v].next[c];
    }
}
 
int mx(int x) {
    int v = 0;
    int ans = 0;
    for (int i=30;i>=0;i--) {
        int c = !((x >> i) & 1);
        if (!trie[v].cnt[c])
            v = trie[v].next[!c];
        else 
        {
            ans += 1 << i;
            v = trie[v].next[c];
        }
        
    }
    return ans;
}
 
void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //scanf("%d",&tc);
    add(0);
    cin >> tc;
}
 
void input()
{
    cin >> chr >> x;
}
 
void output()
{
    if(chr == "+")add(x);
    else if(chr == "-")sub(x);
    else cout << mx(x) << endl;
}
 
int main()
{
    preprocess();
    while(tc--)
    {
        input();
        output();
    }
    return 0;
}
