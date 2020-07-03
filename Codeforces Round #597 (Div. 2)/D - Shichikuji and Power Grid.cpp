#include<bits/stdc++.h>
using namespace std;
 
class City{
    public:
        int x,y,cost,k,parent;
 
        City()
        {
            parent = -1;
        }
 
        long long distance(City other)
        {
            return 1LL * (k + other.k) * (abs(x - other.x) + abs(y - other.y));
        }
        bool operator <(const City & other) const
        {
            return cost < other.cost;
        }
 
};
 
int n;
City city[2005];
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //--------------------------
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d%d",&city[i].x,&city[i].y);
    for(int i=0;i<n;i++)scanf("%d",&city[i].cost);
    for(int i=0;i<n;i++)scanf("%d",&city[i].k);
 
    long long total_cost = 0;
    vector<int> roots;
    vector<pair<int,int>> edges;
    bitset<2005> done;
    for(int _=0;_<n;_++)
    {
        int mn = INT32_MAX;
        int u = -1;
        for(int i=0;i<n;i++)
        {
            if(done.test(i))continue;
            if(city[i].cost < mn )
            {
                mn = city[i].cost;
                u = i;
            }
        }
        total_cost += mn;
        done.set(u);
        if(city[u].parent == -1)roots.push_back(u);
        else edges.push_back(make_pair( min(u,city[u].parent) , max(u,city[u].parent) ));
 
        for(int i=0;i<n;i++)
        {
            if(city[i].distance(city[u]) < city[i].cost)
            {
                city[i].cost = city[i].distance(city[u]);
                city[i].parent = u;
            }
        }
 
    } 
 
    printf("%lld\n",total_cost);
 
    printf("%d\n",(int)roots.size());
    sort(roots.begin(),roots.end());
    for(int root:roots)printf("%d ",root+1);
    printf("\n");
 
    printf("%d\n",(int)edges.size());
    for(pair<int,int> edge:edges)printf("%d %d\n",edge.first+1,edge.second+1);
 
    return 0;   
}
