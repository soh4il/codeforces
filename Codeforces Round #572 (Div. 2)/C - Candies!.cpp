#include<iostream>
#include<vector>
 
using namespace std;
 
class SegmetTree
{
    private:
        vector<int> arr;
        vector<vector<bool>> calculated;
        vector<vector<int>> candies;
        vector<vector<int>> sum;
        
        int getIndex(int n)
        {
            int len = 0;
            while(n>>=1)len++;
            return len;
        }
 
     public:
        SegmetTree(int n,const vector<int> _arr)
        {
            arr = _arr;
            int ln = getIndex(n);
            for(int i=0;i<n+4;i++)
            {
                vector<bool> calcTemp;calcTemp.assign(ln+4,0);
                vector<int> candTemp(ln+1);candTemp.assign(ln+4,0);
                vector<int> sumTemp(ln+1);sumTemp.assign(ln+4,0);
                calculated.push_back(calcTemp);
                candies.push_back(candTemp);
                sum.push_back(sumTemp);
            }
        }
        int getCandies(int l,int r)
        {
            int index = getIndex(r-l+1);
            if(calculated[l][index])return candies[l][index];
 
            if(l >= r)
            {
                sum[l][index] = arr[l];
                candies[l][index] = 0;
                return 0;
            }
            
 
            int m = (l+r) >> 1;            
            int left = getIndex(m-l+1),right = getIndex(r-m);
            candies[l][index] = getCandies(l,m) + getCandies(m+1,r);
            sum[l][index] = (sum[l][left] + sum[m+1][right]) % 10;
            if(sum[l][left] + sum[m+1][right] >= 10) candies[l][index]++;
            calculated[l][index] = 1;
            return candies[l][index];
        }
};
 
int main()
{
    int n;
    cin >> n;
    vector<int> arr(100100);
    for(int i=1;i<=n;i++)
        cin >> arr[i];
    int q;
    cin >> q;
    SegmetTree tree(n,arr);
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin >> l >> r;
        cout << tree.getCandies(l,r) << endl;
    }
    return 0;
}
