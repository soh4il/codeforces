#include <bits/stdc++.h>
using namespace std;
 
class UnionFind{
private:
    vector<int> p;
    vector<int> rank;
    vector<vector<int>> arr;
    int getParent(int i)
    {
        return i == p[i] ? i : p[i] = getParent(p[i]);
    }
    bool isSameParent(int i,int j){
        return getParent(i) == getParent(j);
    }
public:
    UnionFind(int n){
        p.resize(n+5);
        rank.resize(n+5);
        arr.resize(n+5);
        for(int i=1;i<=n;i++){
            p[i] = i;
            arr[i].push_back(i);
            rank[i] = 1;
        }
    }
    void merge(int i,int j)
    {
        if(!isSameParent(i,j))
        {
            int x = getParent(i),y=getParent(j);
            if(rank[x] > rank[y])
            {
                p[y] = p[x];
                for(int num:arr[y])arr[x].push_back(num);
            }else{
                p[x] = p[y];
                for(int num:arr[x])arr[y].push_back(num);
                if (rank[x] == rank[y]) rank[y]++; 
            }
        }
    }
    void print(int i){
        int par = getParent(i);
        for(int num:arr[par])printf("%d ",num);
        printf("\n");
    }
};

int t,n;

void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //scanf("%d",&t);
    t=1;
}
 
void input()
{
    scanf("%d",&n);
}
 
void solve()
{
  UnionFind uf(n);
  for(int i=0;i<n-1;i++)
  {
      int x,y;
      scanf("%d%d",&x,&y);
      uf.merge(x,y);
  }
  uf.print(1);
}
 
int main()
{
    preprocess();
    while(t--)
    {
        input();
        solve();
    }
    return 0;
}
