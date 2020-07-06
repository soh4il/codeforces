#include <bits/stdc++.h>
using namespace std;
 
class UnionFind {
    // OOP style
    private: vector<int> p, rank;
    // remember: vi is vector<int>
    public:
    vector<int> mx;
    UnionFind(int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
        mx.assign(N, 0); 
        for (int i = 0; i < N; i++) 
        {
            p[i] = i;
            mx[i] = i;
        }
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            // if from different set
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x;
            // rank keeps the tree short
            else {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++; 
            }
            mx[x] = max(mx[x],mx[y]);
            mx[y] = mx[x];
        } 
    } 
};
 
int n,m;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%d%d",&n,&m);
    UnionFind sets(n+5);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        sets.unionSet(x,y);
    }
    int ans = 0;
    int currHead = sets.mx[sets.findSet(1)];
    for(int i=2;i<=n;i++)
    {
        if(i > currHead)currHead = sets.mx[sets.findSet(i)];
        else if(i < currHead && ! sets.isSameSet(i,currHead))
        {
            sets.unionSet(i,currHead);
            ans++;
            currHead = sets.mx[sets.findSet(i)];
        }
    }
    printf("%d\n",ans);
    return 0;
}
