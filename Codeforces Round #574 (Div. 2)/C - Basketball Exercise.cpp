#include<iostream>
 
using namespace std;
 
typedef long long int ll;
 
int main() {
    int n;
    scanf("%d",&n);
    ll row[100005][2];
    ll sums[100005][2] = {0};
    for(int i=0;i<n;i++)scanf("%lld",&row[i][0]);
    for(int i=0;i<n;i++)scanf("%lld",&row[i][1]);
    for(int i=0;i<n;i++)
    {
        ll mx0 = 0,mx1 = 0;
        for(int j=i-1;j>=0 && j>=i-2;j--)
        {
            mx0 = max(sums[j][0],mx0);
            mx1 = max(sums[j][1],mx1);
        }
        sums[i][0] = row[i][0] + mx1;
        sums[i][1] = row[i][1] + mx0;
    }
    printf("%lld\n",max(sums[n-1][0],sums[n-1][1]));
    return 0;
}
